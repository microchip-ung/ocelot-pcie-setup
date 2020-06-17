//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT

#include <ctype.h>
#include <string.h>

#include "common.h"     /* Always include common.h at the first place of user-defined herder files */
#include "sysutil.h"
#include "hwport.h"
#include "txt.h"
#include "h2io.h"
#include "uartdrv.h"
#include "main.h"
#include "print.h"
#include "h2.h"
#include "timer.h"
#include "txrxtst.h"
#include "clihnd.h"
#include "version.h"
#include "spiflash.h"
#include "vtss_api_base_regs.h"

#include "i2c_h.h"
#include "ledtsk.h"
#include "i2c.h"
#include "misc2.h"
#include "vtss_common_os.h"
#include "h2pcs1g.h"
#include "h2sdcfg.h"



#ifndef NO_DEBUG_IF

/*****************************************************************************
 *
 *
 * Defines
 *
 *
 *
 ****************************************************************************/

#define CLI_MAX_NO_OF_PARMS     4
#define CLI_MAX_CMD_LEN         48

#define FORMAT_OK    0
#define FORMAT_ERROR 1

#if TRANSIT_EEE
#define EEE_WAKEUP_TIME_MAX 1000
#define EEE_WAKEUP_TIME_MIN 0
#endif

/*****************************************************************************
 *
 *
 * Typedefs and enums
 *
 *
 *
 ****************************************************************************/

typedef struct {
    uchar *str;
    uchar len;
} str_parm_t;

/*****************************************************************************
 *
 *
 * Prototypes for local functions
 *
 *
 *
 ****************************************************************************/

static uchar handle_command (void);
static void  cli_show_sw_ver(void);
static uchar retrieve_parms (void);
#if !defined(BRINGUP)
static void cli_show_port_info(void);
#endif
#if TRANSIT_UNMANAGED_SYS_MAC_CONF
static uchar retrieve_str_parms (void);
#endif
static void  skip_spaces (void);
static uchar cmd_cmp (char *s1, char *s2) small;
#if TRANSIT_UNMANAGED_SYS_MAC_CONF
static uchar handle_sys_config (void);
#endif
#ifndef VTSS_COMMON_NDEBUG
static void update_debug_lvl(uchar lvl);
#endif
#if TRANSIT_FAN_CONTROL
#if UNMANAGED_FAN_DEBUG_IF
static void handle_fan_control (void);
#endif
#endif
#if TRANSIT_LLDP
#if UNMANAGED_LLDP_DEBUG_IF
static void cmd_print_lldp_remoteinfo (void);
#endif
#endif

/*****************************************************************************
 *
 *
 * Local data
 *
 *
 *
 ****************************************************************************/

static ulong idata parms [CLI_MAX_NO_OF_PARMS];
static str_parm_t str_parms [CLI_MAX_NO_OF_PARMS];
static uchar parms_no;

static uchar xdata cmd_buf [CLI_MAX_CMD_LEN];
static uchar xdata *cmd_ptr;
static uchar cmd_len = 0;

/* Common Sequence Mnemonic */
#define CLI_CTLC    0x03
#define CLI_CTLD    0x04
#define CLI_BEL     0x07
#define CLI_CTLH    0x08
#define CLI_BS      CLI_CTLH
#define CLI_LF      0x0a
#define CLI_CR      0x0d
#define CLI_ESC     0x1b
#define CLI_DEL     0x7f

#define CLI_SEQUENCE_INDICATOR     0x5b  // [
#define CLI_CURSOR_UP              0x41  // A
#define CLI_CURSOR_DOWN            0x42  // B
#define CLI_CURSOR_FORWARD         0x43  // C
#define CLI_CURSOR_BACKWARD        0x44  // D

/* Control Sequence Introducer (CSI)
 * An escape sequence that provides supplementary controls and is itself a
 * prefix affecting the interpretation of a limited number of contiguous
 * characters. In the VT100 the CSI is ESC [. */
#define CLI_CSI_1   CLI_ESC /* First character of CSI */
#define CLI_CSI_2   0x5b    /* Second character of CSI */
#define CLI_CUF     0x43    /* Cursor Forward, Sequence: Escape [ C */
#define CLI_CUB     0x44    /* Cursor Backward, Sequence: Escape [ D */
#define CLI_EL      0x4B    /* Erase in Line, Sequence: Escape [ K */


/* ************************************************************************ */
void cli_tsk (void)
/* ------------------------------------------------------------------------ --
 * Purpose     : Handle command line interface.
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    uchar error_status;

    if (cmd_ready()) {
        cmd_ptr = &cmd_buf[0];
        skip_spaces();
#if TRANSIT_UNMANAGED_SWUP
        if (cmd_cmp(cmd_ptr, "ERASE") == 0) {
#ifndef VTSS_COMMON_NDEBUG
            vtss_os_trace_level = 0;
#endif //VTSS_COMMON_NDEBUG

            cmd_ptr += (sizeof("ERASE") - 1);
            if (retrieve_parms() != FORMAT_OK) {
                error_status = FORMAT_ERROR;
            } else {
#if FRONT_LED_PRESENT
                led_update_system(VTSS_LED_MODE_BLINK_GREEN);
#endif //FRONT_LED_PRESENT
                print_cr_lf();
                if (flash_erase_code((ulong) parms[0])) {
                    println_str("Fail");
                } else {
                    println_str("Done");
                }
                error_status = 0;
#if FRONT_LED_PRESENT
                led_update_system(VTSS_LED_MODE_ON_GREEN);
#endif //FRONT_LED_PRESENT
            }
        } else if (cmd_cmp(cmd_ptr, "PROGRAM") == 0) {

            cmd_ptr += (sizeof("PROGRAM") - 1);
            if (retrieve_parms() != FORMAT_OK) {
                error_status = FORMAT_ERROR;
            }
            else if (parms_no != 3) {
                error_status = FORMAT_ERROR;
            } else {
#ifndef VTSS_COMMON_NDEBUG
                vtss_os_trace_level = 0;
#endif //VTSS_COMMON_NDEBUG
#if FRONT_LED_PRESENT
                led_update_system(VTSS_LED_MODE_BLINK_GREEN);
#endif //FRONT_LED_PRESENT
                print_cr_lf();
                if (flash_download_image((ulong) parms[0], (ulong) parms[1], (uchar) parms[2])) {
                    println_str("Fail");
#if FRONT_LED_PRESENT
                    led_update_system(VTSS_LED_MODE_ON_GREEN);
#endif //FRONT_LED_PRESENT
                } else {
                    println_str("Done");
                    h2_reset();
                }
            }
        } else
#endif //TRANSIT_UNMANAGED_SWUP


        if (cmd_buf[0] != CLI_CR && /* Null string */
            (error_status = handle_command()) != NULL) {
            /* empty queue */
            while (uart_byte_ready()) {
                (void) uart_get_byte();
            }
            /* Show error message */
            println_str("%% Invalid command");
        }

        cmd_len = 0;
        CLI_PROMPT();
    }
}

static void cli_csi_prefix(uchar ctrl_key) small
{
    uart_put_byte(CLI_CSI_1);
    uart_put_byte(CLI_CSI_2);
    uart_put_byte(ctrl_key);
}

static void cli_backspace(void) small
{
    cli_csi_prefix(CLI_CUB);
    cli_csi_prefix(CLI_EL);
}

/* ************************************************************************ */
bool cmd_ready (void)
/* ------------------------------------------------------------------------ --
 * Purpose     : Collect bytes received by uart driver and check if a command
 *               is ready (i.e. <CR> received).
 * Remarks     : Returns TRUE, if command is ready, otherwise FALSE.
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    uchar ch;

    if (uart_byte_ready()) {
        ch = uart_get_byte();

        if (ch != CLI_LF) { /* discard LF chars */
            if (ch == CLI_CTLH) { /* handle backspace char */
                if (cmd_len > 0) {
                    cmd_len--;
                    cli_backspace();
                }
            } else {
                if (ch == CLI_SEQUENCE_INDICATOR) {
                    delay_1(1); // Delay 1ms to check if cursor control character come along with the sequence indicator
                }
                if (ch == CLI_SEQUENCE_INDICATOR && uart_byte_ready()) {
                    ch = uart_get_byte();
                    if (ch == CLI_CURSOR_UP && cmd_len == 0) { // Only support cursor up while first character input.
                        for (cmd_len = 0; cmd_buf[cmd_len] > 31 && cmd_buf[cmd_len] < 128; cmd_len++) {
                            uart_put_byte(cmd_buf[cmd_len]);
                        }
                    }
                } else if (ch == CLI_CR) {
                    /* error handling: ensure that CR is present in buffer in case of buffer overflow */
                    if (cmd_len == CLI_MAX_CMD_LEN) {
                        cmd_buf[CLI_MAX_CMD_LEN - 1] = CLI_CR;
                    }
                    cmd_buf[cmd_len++] = ch;
                    uart_put_byte(ch); // Echo the input character
                    uart_put_byte(CLI_CR);
                    uart_put_byte(CLI_LF);
                    return TRUE;
                } else if (cmd_len < CLI_MAX_CMD_LEN && (ch > 31 && ch < 128) /* printable characters(32-127) */) {
                    cmd_buf[cmd_len++] = ch;
                    uart_put_byte(ch); // Echo the input character
                }
            }
        }
    }

    return FALSE;
}

#if 0 /* For debug only */
void list_mii_reg(uchar iport)
{
    uchar  cnt;

    println_str("std");

    for (cnt = 0; cnt <= 31; cnt++) {
        print_hex_w(cnt);
        print_str(": ");
        print_hex_w(phy_read(iport, cnt));
        print_cr_lf();
    }

    println_str("ext1");

    phy_page_ext(iport);
    for (cnt = 0x12; cnt <= 0x1e; cnt++) {
        print_hex_w(cnt);
        print_str(": ");
        print_hex_w(phy_read(iport, cnt));
        print_cr_lf();
    }

    println_str("ext2");

    phy_page_ext2(iport);
    for (cnt = 0x10; cnt <= 0x11; cnt++) {
        print_hex_w(cnt);
        print_str(": ");
        print_hex_w(phy_read(iport, cnt));
        print_cr_lf();
    }

    println_str("gp");

    phy_page_gp(iport);
    for (cnt = 0x0e; cnt <= 0x1d; cnt++) {
        print_hex_w(cnt);
        print_str(": ");
        print_hex_w(phy_read(iport, cnt));
        print_cr_lf();
    }

    phy_page_std(iport);

}
#endif

static void cli_show_help_msg(void)
{
    println_str("V : Show version");
    println_str("R <target> <offset> <addr>: Read from chip register");
    println_str("  --> Example: Read Chip ID register DEVCPU_GCB:CHIP_REGS:CHIP_ID");
    println_str("  -->                                0x71070000       0x0     0x0");
    println_str("  --> Command: R 0x71070000 0x0 0x0");

#if 0 //defined(VTSS_ARCH_OCELOT)
    println_str("  --> ANA       : 0x71880000      ES0       : 0x71040000");
    println_str("  --> DEVCPU_GCB: 0x71070000      DEVCPU_ORG: 0x71000000");
    println_str("  --> DEVCPU_PTP: 0x710E0000      DEVCPU_QS : 0x71080000");
    println_str("  --> DEV[ 0]   : 0x711E0000      DEV[ 1]   : 0x711F0000");
    println_str("  --> DEV[ 2]   : 0x71200000      DEV[ 3]   : 0x71210000");
    println_str("  --> DEV[ 4]   : 0x71220000      DEV[ 5]   : 0x71230000");
    println_str("  --> DEV[ 6]   : 0x71240000      DEV[ 7]   : 0x71250000");
    println_str("  --> DEV[ 8]   : 0x71260000      DEV[ 9]   : 0x71270000");
    println_str("  --> DEV[10]   : 0x71280000");
#endif

    println_str("W <target> <offset> <addr> <value>: Write switch register");
    println_str("I <uport> <addr> [<page>]: Read PHY register");
    println_str("  --> Example: Read user port 1 PHY ID from PHY register 2 page 0");
    println_str("  --> Command: I 1 0x2 0");
    println_str("O <uport> <addr> <value> [<page>]: Write PHY register");

#if defined(VTSS_ARCH_OCELOT) && defined(CUSTOM_PHY)
    println_str("Q <addr> [<page>]: Read VSC8531 PHY register");
    println_str("  --> Example: Read PHY ID from PHY register 2 page 0");
    println_str("  --> Command: O 0x2 0");
    println_str("U <addr> <value> [<page>]: Write VSC8531 PHY register");
#endif /* defined(VTSS_ARCH_OCELOT) && defined(CUSTOM_PHY) */
    println_str("P : Show Port information");
    println_str("? : Show commands");

#ifndef UNMANAGED_REDUCED_DEBUG_IF
#if defined(VTSS_ARCH_OCELOT)

#if defined(UNMANAGED_FLOW_CTRL_IF)
    println_str("K <0|1> <uport>: Flow control mode (0=Enable, 1=Disable)");
#endif //UNMANAGED_FLOW_CTRL_IF

#if defined(BUFFER_RESOURCE_DEBUG_ENABLE)
    println_str("B <0|1>: Dump buffer resource configuration or status (0=Config, 1=Status)");
#endif // BUFFER_RESOURCE_DEBUG_ENABLE


#endif /* defined(VTSS_ARCH_OCELOT) */



    println_str("X : Reboot device");
    println_str("Z <0|1>: E-Col-Drop mode, linkup ports only (0=Disable, 1=Enable)");

#if UNMANAGED_FAN_DEBUG_IF
    println_str("F temp_max temp_on: Update temp. max and on");
#endif // UNMANAGED_FAN_DEBUG_IF

#ifndef VTSS_COMMON_NDEBUG
    println_str("B level: Set debug level 1 to 4");
#endif


    println_str("S <0|1>: Suspend/Resume applications (0=Resume, 1=Suspend)");

#if TRANSIT_UNMANAGED_SWUP
    println_str("D : Dump bytes from SPI flash");
#endif // TRANSIT_UNMANAGED_SWUP

#endif /* UNMANAGED_REDUCED_DEBUG_IF */

}

/* ************************************************************************ */
static uchar handle_command (void)
/* ------------------------------------------------------------------------ --
 * Purpose     : Interpret and handle command (apart from config commands).
 * Remarks     : Module variable cmd_ptr must have been set to point to first
 *               non-space char in command string, when this function is called.
 *               Returns 0, if successful, otherwise <> 0.
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    uchar cmd;
#ifndef UNMANAGED_REDUCED_DEBUG_IF
#if TRANSIT_EEE
    ulong dat;
#endif    

#if UNMANAGED_TCAM_DEBUG_IF
    uchar cntr;
    tcam_data_conf_t conf_r;
#endif
#endif //UNMANAGED_REDUCED_DEBUG_IF

    cmd = *cmd_ptr;
    cmd_ptr++;

    if (retrieve_parms() != FORMAT_OK) {
        return FORMAT_ERROR;
    }

    switch (conv_to_upper_case(cmd)) {
    case 'V': /* Get version info */
        cli_show_sw_ver();
        break;

#if !defined(BRINGUP)
    case 'P': /* Show port information */
        cli_show_port_info();
        break;
#endif // !BRINGUP

    case 'W': /* Write switch register */
        if (parms_no >= 4) {
            H2_WRITE((parms[0] + parms[1] + parms[2]), parms[3]);
        }
        // No need break state for this case (write operation).
        // Read the register value after that.

    case 'R': /* Read switch register */
        /* Target and offset as parameter */
        if (parms_no >= 3) {
            H2_READ((parms[0] + parms[1] + parms[2]), parms[3] /*dat*/);
            print_parse_info_32(parms[3]);
        }
        break;

#if !defined(BRINGUP)
    case 'O': /* Write PHY register */
        /* Front port number and PHY address */
        if (parms_no >= 4) {
            /* Change page */
            phy_write(uport2cport((uchar) parms[0]), 31, parms[3]);
            phy_write(uport2cport((uchar) parms[0]), parms[1], parms[2]);
            phy_write(uport2cport((uchar) parms[0]), 31, 0);
        } else if (parms_no == 3) {
            phy_write(uport2cport((uchar) parms[0]), parms[1], parms[2]); // direct write
        }
        // No need break state for this case (write operation).
        // Read the register value after that.

    case 'I': /* Read PHY register */
        /* Front port number and PHY address */
        print_hex_prefix();
        if (parms_no > 2) {
            // Change page
            phy_write(uport2cport((uchar) parms[0]), 31, parms[2]);
            print_hex_w(phy_read(uport2cport((uchar) parms[0]), parms[1]));
            phy_write(uport2cport((uchar) parms[0]), 31, 0); // Back to std page
        } else if (parms_no == 2) {
            print_hex_w(phy_read(uport2cport((uchar) parms[0]), parms[1]));
        }

        print_cr_lf();
        break;
#endif /* !defined(BRINGUP) */

#if defined(VTSS_ARCH_OCELOT) && defined(CUSTOM_PHY)
    case 'U': /* Write VSC8531 PHY register */
        if (parms_no > 2) {
            /* Change page */
            custom_phy_write(31, parms[2]);
            custom_phy_write(parms[0], parms[1]);
            custom_phy_write(31, 0); // Back to std page
        } else if (parms_no == 2) {
            custom_phy_write(parms[0], parms[1]); // direct write
        }
        // No need break state for this case (write operation).
        // Read the register value after that.
    case 'Q': /* Read VSC8531 PHY register */
        print_hex_prefix();
        if (parms_no > 1) {
            // Change page
            custom_phy_write(31, parms[1]);
            print_hex_w(custom_phy_read(parms[0]));
            custom_phy_write(31, 0); // Back to std page
        } else if (parms_no == 1) {
            print_hex_w(custom_phy_read(parms[0]));
        }

        print_cr_lf();
        break;
#endif /* defined(VTSS_ARCH_OCELOT) && defined(CUSTOM_PHY) */

#ifndef VTSS_COMMON_NDEBUG
    case 'L': /* test LED */
        led_state(parms[0], parms[1], parms[2]);
        break;
#endif


    case '?': /* Show CLI command help message */
        cli_show_help_msg();
        break;

#ifndef UNMANAGED_REDUCED_DEBUG_IF
#if defined(VTSS_ARCH_OCELOT)

#if defined(UNMANAGED_FLOW_CTRL_IF)
    case 'K':   /* Flow control mode */
       phy_flowcontrol_set(uport2cport(parms[1]), !parms[0]);
       phy_state_to_setup(uport2cport(parms[1]));
     break;           
#endif //UNMANAGED_FLOW_CTRL_IF

#if defined(BUFFER_RESOURCE_DEBUG_ENABLE) || defined(SERDES_DEBUG_ENABLE)
    case 'B':   /* Dump buffer resource configuration or status */
        switch ((uchar) parms[0]) {
#if defined(BUFFER_RESOURCE_DEBUG_ENABLE)
        case 0:    // Dump RES_CFG 
        case 1: {  // Dump RES_STAT
            BOOL dump_status = parms[0] ? TRUE : FALSE;
            ulong i, j, reg_val, wm_value, wm_unit, inuse, maxuse, res_idx;

            if (dump_status) {
                println_str("RES_STAT: Dump when maxuse != 0 and maxuse >= wm");
            } else {
                println_str("RES_CFG: Dump when wm != 0");
            }

            for (i = 0; i < 1024; i++) {
                // Read RES_CFG
                H2_READ(VTSS_QSYS_RES_CTRL_RES_CFG(i), reg_val);
                wm_unit = VTSS_X_QSYS_RES_CTRL_RES_CFG_WM_MULTIPLIER_UNIT(reg_val);
                wm_value = VTSS_X_QSYS_RES_CTRL_RES_CFG_WM_VALE(reg_val) * (wm_unit ? 16 : 1);

                // Read RES_STAT
                if (dump_status) {
                    H2_READ(VTSS_QSYS_RES_CTRL_RES_STAT(i), reg_val);
                    inuse = VTSS_X_QSYS_RES_CTRL_RES_STAT_INUSE(reg_val);
                    maxuse = VTSS_X_QSYS_RES_CTRL_RES_STAT_MAXUSE(reg_val);
                }

                if ((!dump_status && wm_value) || // Only dump when wm_value != 0
                    (dump_status && maxuse && maxuse >= wm_value)     // Only dump when maxuse != 0 and maxuse >= wm_value
                   ) {
                    res_idx = i / 256;
                    print_str("Res[");
                    if (res_idx == 0) {
                        print_str("SrcMem");
                    } else if (res_idx == 1) {
                        print_str("SrcRef");
                    } else if (res_idx == 2) {
                        print_str("DstMem");
                    } else { // res_idx = 3
                        print_str("DstRef");
                    }
                    print_str("] - ");

                    j = i % 256;
                    if (j < 96) {
                        print_str("Port and QoS class : Port");
                        print_dec(j / 8);
                        print_str(", Class");
                        print_dec(j % 8);
                    } else if (j < 216) {
                        //print_str("Unused:");
                        //print_dec(j);
                    } else if (j < 224) {
                        print_str("QoS class sharing  : Class");
                        print_dec(j - 216);
                    } else if (j < 236) {
                        print_str("Port reservation   : Port");
                        print_dec(j - 224);
                    } else if (j == 254) {
                        print_str("Color sharing      : DP=1(Yellow)");
                    } else if (j == 255) {
                        print_str("Color sharing      : DP=0(Green)");
                    } else {
                        //print_str("Unused:");
                        //print_dec(j);
                    }

                    print_str(". WM=");
                    print_dec(wm_value);

                    if (dump_status) {
                        print_str(", Inuse=");
                        print_dec(inuse);
                        print_str(", Maxuse=");
                        print_dec(maxuse);
                    }
                    print_cr_lf();
                }
            }
        }
        break;
#endif // BUFFER_RESOURCE_DEBUG_ENABLE

#if defined(SERDES_DEBUG_ENABLE)
        case 2: {
            ulong idx, i, sd6g_addr, reg_val, dump_reg_cnt = 31;
            ulong reg_addr[31] = {
                VTSS_HSIO_SERDES6G_DIG_CFG_SERDES6G_DIG_CFG            ,
                VTSS_HSIO_SERDES6G_DIG_CFG_SERDES6G_DFT_CFG0           ,
                VTSS_HSIO_SERDES6G_DIG_CFG_SERDES6G_DFT_CFG1           ,
                VTSS_HSIO_SERDES6G_DIG_CFG_SERDES6G_DFT_CFG2           ,
                VTSS_HSIO_SERDES6G_DIG_CFG_SERDES6G_TP_CFG0            ,
                VTSS_HSIO_SERDES6G_DIG_CFG_SERDES6G_TP_CFG1            ,
                VTSS_HSIO_SERDES6G_DIG_CFG_SERDES6G_RC_PLL_BIST_CFG    ,
                VTSS_HSIO_SERDES6G_DIG_CFG_SERDES6G_MISC_CFG           ,
                VTSS_HSIO_SERDES6G_DIG_CFG_SERDES6G_OB_ANEG_CFG        ,
                VTSS_HSIO_SERDES6G_DIG_STATUS_SERDES6G_DFT_STATUS      ,
                VTSS_HSIO_SERDES6G_DIG_STATUS_SERDES6G_ERR_CNT         ,
                VTSS_HSIO_SERDES6G_DIG_STATUS_SERDES6G_MISC_STATUS     ,
                VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_DES_CFG            ,
                VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_IB_CFG             ,
                VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_IB_CFG1            ,
                VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_IB_CFG2            ,
                VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_IB_CFG3            ,
                VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_IB_CFG4            ,
                VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_IB_CFG5            ,
                VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_OB_CFG             ,
                VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_OB_CFG1            ,
                VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_SER_CFG            ,
                VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_COMMON_CFG         ,
                VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_PLL_CFG            ,
                VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_ACJTAG_CFG         ,
                VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_GP_CFG             ,
                VTSS_HSIO_SERDES6G_ANA_STATUS_SERDES6G_IB_STATUS0      ,
                VTSS_HSIO_SERDES6G_ANA_STATUS_SERDES6G_IB_STATUS1      ,
                VTSS_HSIO_SERDES6G_ANA_STATUS_SERDES6G_ACJTAG_STATUS   ,
                VTSS_HSIO_SERDES6G_ANA_STATUS_SERDES6G_PLL_STATUS      ,
                VTSS_HSIO_SERDES6G_ANA_STATUS_SERDES6G_REVID
            };        
            char *reg_name[31] = {
                "SERDES6G_DIG_CFG_SERDES6G_DIG_CFG",
                "SERDES6G_DIG_CFG_SERDES6G_DFT_CFG0",
                "SERDES6G_DIG_CFG_SERDES6G_DFT_CFG1",
                "SERDES6G_DIG_CFG_SERDES6G_DFT_CFG2",
                "SERDES6G_DIG_CFG_SERDES6G_TP_CFG0 ",
                "SERDES6G_DIG_CFG_SERDES6G_TP_CFG1",
                "SERDES6G_DIG_CFG_SERDES6G_RC_PLL_BIST_CFG",
                "SERDES6G_DIG_CFG_SERDES6G_MISC_CFG",
                "SERDES6G_DIG_CFG_SERDES6G_OB_ANEG_CFG",
                "SERDES6G_DIG_STATUS_SERDES6G_DFT_STATUS",
                "SERDES6G_DIG_STATUS_SERDES6G_ERR_CNT",
                "SERDES6G_DIG_STATUS_SERDES6G_MISC_STATUS",
                "SERDES6G_ANA_CFG_SERDES6G_DES_CFG",
                "SERDES6G_ANA_CFG_SERDES6G_IB_CFG",
                "SERDES6G_ANA_CFG_SERDES6G_IB_CFG1",
                "SERDES6G_ANA_CFG_SERDES6G_IB_CFG2",
                "SERDES6G_ANA_CFG_SERDES6G_IB_CFG3",
                "SERDES6G_ANA_CFG_SERDES6G_IB_CFG4",
                "SERDES6G_ANA_CFG_SERDES6G_IB_CFG5",
                "SERDES6G_ANA_CFG_SERDES6G_OB_CFG",
                "SERDES6G_ANA_CFG_SERDES6G_OB_CFG1",
                "SERDES6G_ANA_CFG_SERDES6G_SER_CFG",
                "SERDES6G_ANA_CFG_SERDES6G_COMMON_CFG",
                "SERDES6G_ANA_CFG_SERDES6G_PLL_CFG",
                "SERDES6G_ANA_CFG_SERDES6G_ACJTAG_CFG",
                "SERDES6G_ANA_CFG_SERDES6G_GP_CFG ",
                "SERDES6G_ANA_STATUS_SERDES6G_IB_STATUS0",
                "SERDES6G_ANA_STATUS_SERDES6G_IB_STATUS1",
                "SERDES6G_ANA_STATUS_SERDES6G_ACJTAG_STATUS",
                "SERDES6G_ANA_STATUS_SERDES6G_PLL_STATUS",
                "SERDES6G_ANA_STATUS_SERDES6G_REVID"
            };

            for (idx = 0; idx < 2; idx++) {
                if (idx == 0) {
                    println_str("Dump SerDes6G_1");
                    sd6g_addr = 1 << 1; // SerDes6G_1
                } else {
                    println_str("Dump SerDes6G_2");
                    sd6g_addr = 1 << 2; // SerDes6G_2
                }

                for (i = 0; i < dump_reg_cnt; i++) {
                    h2_sd6g_read(sd6g_addr);
                    H2_READ(reg_addr[i], reg_val);
                    println_str(reg_name[i]);
                    print_parse_info_32(reg_val);
                    print_cr_lf();  
                }
            }
            break;
        }
        case 3: {
            ulong idx, i, sd1g_addr, reg_val, dump_reg_cnt = 15;
            ulong reg_addr[15] = {
                VTSS_HSIO_SERDES1G_ANA_CFG_SERDES1G_DES_CFG        ,
                VTSS_HSIO_SERDES1G_ANA_CFG_SERDES1G_IB_CFG         ,
                VTSS_HSIO_SERDES1G_ANA_CFG_SERDES1G_OB_CFG         ,
                VTSS_HSIO_SERDES1G_ANA_CFG_SERDES1G_SER_CFG        ,
                VTSS_HSIO_SERDES1G_ANA_CFG_SERDES1G_COMMON_CFG     ,
                VTSS_HSIO_SERDES1G_ANA_CFG_SERDES1G_PLL_CFG        ,
                VTSS_HSIO_SERDES1G_ANA_STATUS_SERDES1G_PLL_STATUS  ,
                VTSS_HSIO_SERDES1G_DIG_CFG_SERDES1G_DFT_CFG0       ,
                VTSS_HSIO_SERDES1G_DIG_CFG_SERDES1G_DFT_CFG1       ,
                VTSS_HSIO_SERDES1G_DIG_CFG_SERDES1G_DFT_CFG2       ,
                VTSS_HSIO_SERDES1G_DIG_CFG_SERDES1G_TP_CFG         ,
                VTSS_HSIO_SERDES1G_DIG_CFG_SERDES1G_RC_PLL_BIST_CFG,
                VTSS_HSIO_SERDES1G_DIG_CFG_SERDES1G_MISC_CFG       ,
                VTSS_HSIO_SERDES1G_DIG_STATUS_SERDES1G_DFT_STATUS  ,
                VTSS_HSIO_SERDES1G_DIG_STATUS_SERDES1G_MISC_STATUS
            };        
            char *reg_name[15] = {
                "SERDES1G_ANA_CFG_SERDES1G_DES_CFG",
                "SERDES1G_ANA_CFG_SERDES1G_IB_CFG",
                "SERDES1G_ANA_CFG_SERDES1G_OB_CFG",
                "SERDES1G_ANA_CFG_SERDES1G_SER_CFG",
                "SERDES1G_ANA_CFG_SERDES1G_COMMON_CFG",
                "SERDES1G_ANA_CFG_SERDES1G_PLL_CFG",
                "SERDES1G_ANA_STATUS_SERDES1G_PLL_STATUS",
                "SERDES1G_DIG_CFG_SERDES1G_DFT_CFG0",
                "SERDES1G_DIG_CFG_SERDES1G_DFT_CFG1",
                "SERDES1G_DIG_CFG_SERDES1G_DFT_CFG2",
                "SERDES1G_DIG_CFG_SERDES1G_TP_CFG",
                "SERDES1G_DIG_CFG_SERDES1G_RC_PLL_BIST_CFG",
                "SERDES1G_DIG_CFG_SERDES1G_MISC_CFG",
                "SERDES1G_DIG_STATUS_SERDES1G_DFT_STATUS",
                "SERDES1G_DIG_STATUS_SERDES1G_MISC_STATUS "
            };

            for (idx = 0; idx < 2; idx++) {
                if (idx == 0) {
                    println_str("Dump SerDes1G_4");
                    sd1g_addr = 1 << 4; // SerDes1G_4
                } else {
                    println_str("Dump SerDes1G_5");
                    sd1g_addr = 1 << 5; // SerDes1G_5
                }
                for (i = 0; i < dump_reg_cnt; i++) {
                    h2_sd1g_read(sd1g_addr);
                    H2_READ(reg_addr[i], reg_val);
                    println_str(reg_name[i]);
                    print_parse_info_32(reg_val);
                    print_cr_lf();  
                }
            }
            break;
        }
#endif // SERDES_DEBUG_ENABLE
    }
break;
#endif // BUFFER_RESOURCE_DEBUG_ENABLE || SERDES_DEBUG_ENABLE

#if UNMANAGED_TCAM_DEBUG_IF
    case 'Y': /* TCAM configuration get */
    {
        tcam_target_t type;
        if ((uchar)parms[1] == 0)
            type = TCAM_TARGET_IS1;
        else
            type = TCAM_TARGET_IS2;

        memset(&conf_r,0,sizeof(tcam_data_conf_t));
        cntr = h2_tcam_count_get(type);
        print_dec(cntr);
        println_str(" is ACL count ");
        if ((uchar)parms[0] < cntr) {
            h2_tcam_conf_get(type, (uchar) parms[0], &conf_r);
            print_str("TCAM information of entry id ");
            print_dec(parms[0]);
            print_cr_lf();
            print_line(66);
            print_cr_lf();
            for (cntr=0;cntr<TCAM_ENTRY_WIDTH;cntr++) {
                print_cr_lf();
                print_hex_dw(conf_r.tcam_entry[cntr]);
                println_str("<tcam entry");
                print_hex_dw(conf_r.tcam_mask[cntr]);
                println_str("<tcam mask");
            }
            print_hex_dw(conf_r.tcam_action[0]);
            println_str("<action 0");
            print_hex_dw(conf_r.tcam_action[1]);
            println_str("<action 1");
            print_hex_dw(conf_r.tg);
            println_str("<tg");
            print_hex_dw(conf_r.tcam_count);
            println_str("<count");
        } else {
            print_dec((uchar)parms[0]);
            println_str(" is not valid ACL id");
        }
        break;
    }
#endif


#endif //#elif 

    case 'Z': { /* Enable/Disalbe Excessive Col drop */
        vtss_iport_no_t iport_idx;
        vtss_cport_no_t chip_port;
        uchar drop_enable = (parms_no == 1 && parms[0] == 1) ? 0 : 1;

        for (iport_idx = MIN_PORT; iport_idx < MAX_PORT; iport_idx++) {
            chip_port = iport2cport(iport_idx);
            if (is_port_link(chip_port)) { // Link up
                // Set E-Col-Drop on link-up ports only
                h2_enable_exc_col_drop(iport2cport(iport_idx), drop_enable);
            }
        }
        break;
    } // case 'Z'


    case 'X': /* Reboot device */
        h2_reset();
        break;

#ifndef VTSS_COMMON_NDEBUG
    case 'B': /* debug level */
        if(((uchar) parms[0] <= VTSS_COMMON_TRLVL_RACKET) &&
                ((uchar) parms[0] >= VTSS_COMMON_TRLVL_ERROR)) {
            update_debug_lvl((uchar) parms[0]);
        }
        break;
#endif


#if !defined(BRINGUP)
    case 'S': /* Suspend/Resume applications */
        switch ((uchar) parms[0]) {
        case 0:
            /* Resume */
            sysutil_set_suspend(FALSE);
            break;
        case 1:
            /* Suspend */
            sysutil_set_suspend(TRUE);
            break;

        default:
            return FORMAT_ERROR;
        }
        break;
#endif /* BRINGUP */

#if TRANSIT_UNMANAGED_SWUP
    case 'D': /* Dump bytes from SPI flash */
        flash_read_bytes(parms[0], parms[1]);
        break;
#endif

#endif /* UNMANAGED_REDUCED_DEBUG_IF */

    default:
        return FORMAT_ERROR;
    }
    return FORMAT_OK;
}

/* ************************************************************************ */
static uchar retrieve_parms (void)
/* ------------------------------------------------------------------------ --
 * Purpose     : Retrieve parameters from command string.
 * Remarks     : Module variable cmd_ptr must have been set to point to first
 *               char after the command in the command string, when this function
 *               is called.
 *               The module variables parms_no and parms are updated with
 *               actual number of parameters and the actual parameter values.
 *               Returns 0, if successful, otherwise <> 0.
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    uchar ch;
    uchar base;
    uchar j;
    uchar no_of_digits;
    uchar digits [10];
    ulong parm_bin;

    ch = *cmd_ptr;
    if ((ch != ' ') && (ch != CLI_CR)) {
        return FORMAT_ERROR;
    }


    parms_no = 0;
    /* Preset parms to ff's, which may be used as default indication */
    memset(parms, 0xff, sizeof(parms));

    /*
    ** Retrieve parameters one by one.
    */
    for (;;) {

        skip_spaces();
        base = 10; /* default parameter is specified in decimal */
        no_of_digits = 0;

        /*
        ** Check if any hex prefix
        */
        if (*cmd_ptr == '0' && (conv_to_upper_case(*(cmd_ptr + 1)) == 'X')) {
            base = 16; /* parameter is specified in hex */
            cmd_ptr += 2;
            if (*cmd_ptr == ' ') {
                return FORMAT_ERROR;
            }
        }

        /*
        ** Retrieve digits until delimiter (space or CR) and then convert
        ** parameter to binary
        */
        for (;;) {

            ch = *cmd_ptr;

            if ((ch == ' ') || (ch == CLI_CR)) {

                if (no_of_digits > 0) {
                    parm_bin = 0;
                    for (j = 0; j < no_of_digits; j++) {
                        parm_bin = (parm_bin * base) + digits[j];
                    }
                    if (parms_no < CLI_MAX_NO_OF_PARMS) {
                        parms[parms_no++] = parm_bin;
                    }
                }
                /* End processing at end of command string */
                if (ch == CLI_CR) {
                    return FORMAT_OK;
                }
                break; /* go get new parameter */
            } else {

                ch = ascii_to_hex_nib(ch);
                if (ch != 0xff) {
                    if (no_of_digits < 10) {
                        digits[no_of_digits++] = ch;
                        if (ch > 9) {
                            base = 16; /* parameter is specified in hex */
                        }
                    }
                } else {
                    return FORMAT_ERROR;
                }
            }
            cmd_ptr++;
        }
    }
}

#if TRANSIT_UNMANAGED_SYS_MAC_CONF
/* ************************************************************************ */
static uchar retrieve_str_parms (void)
/* ------------------------------------------------------------------------ --
 * Purpose     : Retrieve parameters from command string.
 * Remarks     : Module variable cmd_ptr must have been set to point to first
 *               char after the command in the command string, when this function
 *               is called.
 *               The module variables parms_no and parms are updated with
 *               actual number of parameters and the actual parameter values.
 *               Returns 0, if successful, otherwise <> 0.
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    uchar ch;
    uchar j;

    ch = *cmd_ptr;
    if ((ch != ' ') && (ch != CLI_CR)) {
        return FORMAT_ERROR;
    }

    parms_no = 0;
    for(parms_no = 0; parms_no < CLI_MAX_NO_OF_PARMS; parms_no++) {
        skip_spaces();
        str_parms[parms_no].str = cmd_ptr;
        str_parms[parms_no].len = 0;
        while(1) {
            if(*cmd_ptr == CLI_CR) { /* Enter Key */
                *cmd_ptr = '\0';
                for(j = parms_no + 1; j < CLI_MAX_NO_OF_PARMS; j++) {
                    str_parms[j].str = cmd_ptr;
                    str_parms[j].len = 0;
                }
                return FORMAT_OK;
            }
            if(*cmd_ptr == ' ') { /* Space Key */
                *cmd_ptr = '\0'; // string null end sign
                cmd_ptr++;
                break;
            }
            str_parms[parms_no].len++;
            cmd_ptr++;
        }
    }
    return FORMAT_OK;
}
#endif

#ifndef VTSS_COMMON_NDEBUG
static void update_debug_lvl(uchar lvl)
{
    vtss_os_trace_level = lvl;
}
#endif

#if TRANSIT_UNMANAGED_SYS_MAC_CONF
static uchar cmd_retrieve_mac_addr (uchar *mac_addr_str, uchar * mac_addr)
/* ------------------------------------------------------------------------ --
 * Purpose     : Retrieve MAC value from command string.
 * Remarks     : Module variable cmd_ptr must have been set to point to first
 *               non-space char after the "config mac" command in the command string,
 *               when this function is called.
 *               The retrieved MAC address is returned in module variable cmd_mac_addr
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    uchar j;
    uchar k;
    uchar ch;
    uchar *ptr = mac_addr_str;

    for (j = 0; j < 6; j++) {
        for (k = 0; k < 2; k++) {
            ch = *ptr;
            ptr++;

            ch = ascii_to_hex_nib(ch);
            if (ch == 0xff) {
                return FORMAT_ERROR;
            }

            mac_addr[j] = (mac_addr[j] << 4) | ch;
        }

        if (j < 5) {
            ch = *ptr;
            if (ascii_to_hex_nib(ch) == 0xff) {
                ptr++;
                if ((ch != '-') && (ch != ':') && (ch != '.')) {
                    return FORMAT_ERROR;
                }
            }
        }
    }
    if(*ptr != '\0') {
        return FORMAT_ERROR;
    }

    return FORMAT_OK;
}
#endif

/* ************************************************************************ */
static void skip_spaces (void)
/* ------------------------------------------------------------------------ --
 * Purpose     : Adjust cmd_ptr to point to next char different from space.
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    while (*cmd_ptr == ' ') {
        cmd_ptr++;
    }
}

#if TRANSIT_UNMANAGED_SWUP
/* ************************************************************************ */
static uchar cmd_cmp (char *s1, char *s2) small
/* ------------------------------------------------------------------------ --
 * Purpose     : Compare a string in RAM with a 0-terminated string in flash memory.
 * Remarks     : s1 points to string in RAM, s2 points to string in flash.
 *               Returns 0 if RAM string is equal to the flash string up till, but
 *               not including the 0-terminator. Otherwise 1 is returned.
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    uchar ch1;
    uchar ch2;

    for (;;) {
        ch2 = *s2;
        if (ch2 == 0) {
            return 0;
        }
        s2++;

        ch1 = conv_to_upper_case(*s1++);
        if (ch1 != ch2) {
            return 1;
        }
    }
}
#endif

#endif /* NO_DEBUG_IF */
#if !defined(BRINGUP)
static void print_phy_model_2_txt(unsigned char model)
{
    switch (model) {
        case PHY_MODEL_VTSS_8211:
        case PHY_MODEL_VTSS_8221:
            print_n_str("COBRA", 12);
        break;
        case PHY_MODEL_VTSS_8224:
        case PHY_MODEL_VTSS_8234:
        case PHY_MODEL_VTSS_8244:
            print_n_str("QUATTRO", 12);
        break;
        case PHY_MODEL_VTSS_8538:
        case PHY_MODEL_VTSS_8558:
        case PHY_MODEL_VTSS_8658:
            print_n_str("SPYDER", 12);
        break;
        case PHY_MODEL_VTSS_8664:
            print_n_str("ENZO", 12);
        break;
        case PHY_MODEL_VTSS_8512:
            print_n_str("ATOM", 12);
        break;
        case PHY_MODEL_VTSS_8504:
        case PHY_MODEL_VTSS_8552:
            print_n_str("TESLA", 12);
        break;
        case PHY_MODEL_VTSS_8514:
             print_n_str("ELISE_8514", 12);
        break;
        case PHY_MODEL_VTSS_7512:
            print_n_str("OCELOT_7512", 12);
        break;
        case PHY_MODEL_NONE:
            print_n_str("Not PHY", 12);
        case PHY_MODEL_UNKNOWN:
        default:
        print_n_str("Unknown PHY", 12);
            break;
    }
}
static void port_info_format_output(uchar *fdata)
{
    uchar link_mode = fdata[6], speed;

    print_spaces(3);
    print_dec_8_right_2(fdata[0]);
    print_spaces(4);
    print_dec_8_right_2(fdata[1]);
    print_spaces(4);
    print_dec_8_right_2(fdata[2]);
    print_spaces(7);
    print_dec_8_right_2(fdata[3]);
    print_spaces(6);
    print_hex_prefix();
    print_hex_b(fdata[4]);
    print_spaces(1);
    if (phy_map(fdata[2])) {
#if defined(VTSS_ARCH_OCELOT)
        // PHY/Serdes model
        print_phy_model_2_txt(fdata[5]);
        print_spaces(1);

        // CRC uPatch
        if (fdata[5] == PHY_MODEL_VTSS_8514 || fdata[5] == PHY_MODEL_VTSS_7512 || fdata[5] == PHY_MODEL_VTSS_8221 || fdata[5] == PHY_MODEL_VTSS_8211) {
            print_n_str("No uPatch", 11);
        }
#endif
    } else {
        // PHY/Serdes model
        if (fdata[3] == MAC_IF_SFP_MSA_DETECTED) {
            print_n_str("Auto SFP", 12);
        } else if (fdata[3] == MAC_IF_100FX) {
            print_n_str("100M SFP", 12);
        } else if (fdata[3] == MAC_IF_SGMII) {
            print_n_str("SGMII", 12);
        } else if (fdata[3] == MAC_IF_SERDES_1G) {
            print_n_str("1000BaseX", 12);
        } else if (fdata[3] == MAC_IF_SERDES_2_5G) {
            print_n_str("2.5G", 12);
        } else {
            print_n_str("-", 12);
        }
        print_spaces(1);
        
        // CRC uPatch
        print_n_str("Not PHY", 11);
    }
    print_spaces(1);

    // Link mode
    if (link_mode == LINK_MODE_DOWN) {
        print_str("Down");
    } else {
        print_str("Up - ");
        speed = link_mode & LINK_MODE_SPEED_MASK;
        if (speed == LINK_MODE_SPEED_10) {
            print_str("10M");
        } else if (speed == LINK_MODE_SPEED_100) {
            print_str("100M");
        } else if (speed == LINK_MODE_SPEED_1000) {
            print_str("1G");
        } else if (speed == LINK_MODE_SPEED_2500) {
            print_str("2.5G");
        } else {
            print_str("Unknown");
        }
        if (link_mode & LINK_MODE_FDX_MASK) {
            print_str("FDX");
        } else {
            print_str("HDX");
        }

        // Flow control status
        print_spaces(1);
        print_str("FC(");
        print_str(fdata[7] ? "E)" : "D)");
    }
    print_cr_lf();
}

static void cli_show_port_info(void)
{
    phy_id_t        phy_id;
    vtss_uport_no_t uport_idx = 0;
    vtss_iport_no_t iport = 0;
    vtss_cport_no_t chip_port = 0;
    uchar           fdata[8];
    ulong           reg_val;

    print_str("uPort");
    print_spaces(1);
    print_str("iPort");
    print_spaces(1);
    print_str("cPort");
    print_spaces(1);
    print_str("MIIM Bus");
    print_spaces(1);
    print_str("MIIM Addr");
    print_spaces(3);
    print_str("PHY/Serdes");
    print_spaces(2);
#if defined(VTSS_ARCH_OCELOT)
    print_str("CRC uPatch");
    print_spaces(1);
#endif
    println_str("Link Status");
    print_line(78);
    print_cr_lf();

    for (uport_idx = 1; uport_idx <= NO_OF_BOARD_PORTS; uport_idx++) {
        iport = uport2iport(uport_idx);
        chip_port = iport2cport(iport);
        phy_read_id(chip_port, &phy_id);
        fdata[0] = uport_idx;
        fdata[1] = iport;
        fdata[2] = chip_port;
        fdata[3] = phy_map_miim_no(chip_port);
        fdata[4] = phy_map_phy_no(chip_port);
        fdata[5] = phy_id.model;
        fdata[6] = port_link_mode_get(chip_port);
        H2_READ(VTSS_SYS_PAUSE_CFG_MAC_FC_CFG(chip_port), reg_val);
        fdata[7] = VTSS_X_SYS_PAUSE_CFG_MAC_FC_CFG_TX_FC_ENA(reg_val) ? 1 : 0;
        port_info_format_output(fdata);
    }
}
#endif

#ifndef NO_DEBUG_IF

#if TRANSIT_UNMANAGED_MAC_OPER_GET
/* Show MAC address entries, chip_port=0xFF for all ports */
static void cli_show_mac_addr(vtss_cport_no_t chip_port)
{

}
#endif // TRANSIT_UNMANAGED_MAC_OPER_GET

/* ************************************************************************ */
static void cli_show_sw_ver(void)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
#if defined(BRINGUP)
    return;
#else
#ifndef UNMANAGED_REDUCED_DEBUG_IF
    vtss_cport_no_t chip_port;
    uchar port_ext;
    //ushort dat;
#endif

    /* Chip Family */
    sysutil_show_chip_id();

    /* Software version */
    sysutil_show_sw_ver();

    /* Image build time */
    sysutil_show_compile_date();

    /* HW Revision */
    sysutil_show_hw_ver();

#if defined(JUMBO)
    print_str("MaxFrame Size   :");
    print_spaces(1);
    print_dec(MAX_FRAME_SIZE);
    print_cr_lf();
#endif

#if TRANSIT_THERMAL
    /* chip temperature */
    print_chips_temp();
#endif

#ifndef UNMANAGED_REDUCED_DEBUG_IF
    /* Info about ports */
    print_cr_lf();
    println_str("uPort SMAC              MIIM PHY");
    println_str("----- ----------------- ---- ---");
    for (port_ext = 1; port_ext <= NO_OF_BOARD_PORTS; port_ext++) {
        chip_port = uport2cport(port_ext);
        if(!phy_map(chip_port)
#if MAC_TO_MEDIA
                && !phy_map_serdes(chip_port)
#endif
          ) {
            continue;
        }
        print_spaces(3);
        print_dec_8_right_2(port_ext);
        print_spaces(1);

        /* miim and phy number */
        print_spaces(1);
        print_dec_8_right_2(phy_map_miim_no(chip_port));
        print_spaces(1);
        print_dec_8_right_2(phy_map_phy_no(chip_port));
        print_cr_lf();
    }
#endif
#endif /* BRINGUP */
}
#endif

/****************************************************************************/
/*                                                                          */
/*  End of file.                                                            */
/*                                                                          */
/****************************************************************************/
