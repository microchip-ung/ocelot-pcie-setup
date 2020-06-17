//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT

#include "common.h"     /* Always include common.h at the first place of user-defined herder files */
#include "sysutil.h"
#include "interrupt.h"
#include "hwport.h"
#include "timer.h"
#include "uartdrv.h"
#include "print.h"
#include "clihnd.h"
#include "h2.h"
#include "h2gpios.h"
#include "misc2.h"
#include "h2sdcfg.h"

#if FRONT_LED_PRESENT
#include "ledtsk.h"
#endif

#include "main.h"
#include "misc2.h"  
#include "h2io.h"   

/*
 * Debug enable/disable on local file
 */
#define MAIN_DEBUG_ENABLE
#if defined(MAIN_DEBUG_ENABLE)
#include "version.h"
#endif
#define MAIN_LOOP_ENTER()      {}
#define MAIN_LOOP_EXIT()       {}

/*****************************************************************************
 *
 *
 * Public data
 *
 *
 ****************************************************************************/

/*****************************************************************************
 *
 *
 * Defines
 *
 *
 ****************************************************************************/


/*****************************************************************************
 *
 *
 * Typedefs and enums
 *
 *
 ****************************************************************************/


/*****************************************************************************
 *
 *
 * Local data
 *
 *
 ****************************************************************************/
static ulong up_time = 0; // the unit is second


/*****************************************************************************
 *
 *
 * Local Functions
 *
 *
 ****************************************************************************/
#if defined(HW_TEST_UART)
void sleep_ms(u32 ms)
{
  /* Set the timer value (the default timer ticks every 100 us) */
  H2_WRITE(VTSS_ICPU_CFG_TIMERS_TIMER_VALUE(0), ms * 10);

  /* Enable timer 0 for one-shot */
  H2_WRITE(VTSS_ICPU_CFG_TIMERS_TIMER_CTRL(0),
         VTSS_F_ICPU_CFG_TIMERS_TIMER_CTRL_ONE_SHOT_ENA(1) |
         VTSS_F_ICPU_CFG_TIMERS_TIMER_CTRL_TIMER_ENA(1));

  /* Wait for timer 0 to reach 0 */
  while (H2_READ(VTSS_ICPU_CFG_TIMERS_TIMER_VALUE(0)));
}
#endif /* HW_TEST_UART */

#if 0  //uncall functions
char getchar() {
  /* Wait for Data Ready */
  while (!VTSS_X_UART_UART_LSR_DR(H2_READ(VTSS_UART_UART_LSR(VTSS_TO_UART))));

  /* Read Rx data */
  return H2_READ(VTSS_UART_UART_RBR_THR(VTSS_TO_UART));
}
#endif

#if !defined(NO_DEBUG_IF) && defined(HW_TEST_TIMTER)
void debug_test_timer(void)
{
    //timer
    if (ms_10_timeout_flag) {
        ms_10_timeout_flag = 0;
        println_str("ms_10_timeout_flag*");
    }
    if (ms_100_timeout_flag) {
        ms_100_timeout_flag = 0;
        println_str("ms_100_timeout_flag**");
    }
    if (sec_1_timeout_flag) {
        sec_1_timeout_flag = 0;
        println_str("sec_1_timeout_flag***");
    }
}
#endif /* HW_TEST_TIMTER */

#if !defined(NO_DEBUG_IF) && defined(HW_TEST_UART)
void debug_test_uart(void)
{
    static char toggle_cnt = 0;

    println_str("*********************************");
    print_str("VTSS_DEVCPU_GCB_GPIO_GPIO_ALT(0):0x");
    print_hex_dw(H2_READ(VTSS_DEVCPU_GCB_GPIO_GPIO_ALT(0)));
    print_cr_lf();
    print_str("VTSS_DEVCPU_GCB_GPIO_GPIO_ALT(1):0x");
    print_hex_dw(H2_READ(VTSS_DEVCPU_GCB_GPIO_GPIO_ALT(1)));
    print_cr_lf();

    //THR
    print_str("VTSS_UART_UART_RBR_THR(VTSS_TO_UART):0x");
    print_hex_dw(H2_READ(VTSS_UART_UART_RBR_THR(VTSS_TO_UART)));
    print_spaces(4);
    print_ch(H2_READ(VTSS_UART_UART_RBR_THR(VTSS_TO_UART)));
    print_cr_lf();

    //IER
    print_str("VTSS_UART_UART_IER(VTSS_TO_UART):0x");
    print_hex_dw(H2_READ(VTSS_UART_UART_IER(VTSS_TO_UART)));
    print_cr_lf();

    //FCR
    print_str("VTSS_UART_UART_IIR_FCR(VTSS_TO_UART):0x");
    print_hex_dw(H2_READ(VTSS_UART_UART_IIR_FCR(VTSS_TO_UART)));
    print_cr_lf();

    //LCR
    print_str("VTSS_UART_UART_LCR(VTSS_TO_UART):0x");
    print_hex_dw(H2_READ(VTSS_UART_UART_LCR(VTSS_TO_UART)));
    print_cr_lf();

    //MCR
    print_str("VTSS_UART_UART_MCR(VTSS_TO_UART):0x");
    print_hex_dw(H2_READ(VTSS_UART_UART_MCR(VTSS_TO_UART)));
    print_cr_lf();

    //LSR
    print_str("VTSS_UART_UART_LSR(VTSS_TO_UART):0x");
    print_hex_dw(H2_READ(VTSS_UART_UART_LSR(VTSS_TO_UART)));
    print_cr_lf();

    //MSR
    print_str("VTSS_UART_UART_MSR(VTSS_TO_UART):0x");
    print_hex_dw(H2_READ(VTSS_UART_UART_MSR(VTSS_TO_UART)));
    print_cr_lf();

    //SCR
    print_str("VTSS_UART_UART_SCR(VTSS_TO_UART):0x");
    print_hex_dw(H2_READ(VTSS_UART_UART_SCR(VTSS_TO_UART)));
    print_cr_lf();

    //RESERVED1
    print_str("VTSS_UART_UART_RESERVED1(VTSS_TO_UART,0):0x");
    print_hex_dw(H2_READ(VTSS_UART_UART_RESERVED1(VTSS_TO_UART,0)));
    print_cr_lf();

    //USR
    print_str("VTSS_UART_UART_USR(VTSS_TO_UART):0x");
    print_hex_dw(H2_READ(VTSS_UART_UART_USR(VTSS_TO_UART)));
    print_cr_lf();

    //VTSS_UART_UART_RESERVED2
    print_str("VTSS_UART_UART_RESERVED2(VTSS_TO_UART, 0):0x");
    print_hex_dw(H2_READ(VTSS_UART_UART_RESERVED2(VTSS_TO_UART, 0)));
    print_cr_lf();


    //VTSS_UART_UART_RESERVED2
    print_str("VTSS_UART_UART_HTX(VTSS_TO_UART):0x");
    print_hex_dw(H2_READ(VTSS_UART_UART_HTX(VTSS_TO_UART)));
    print_cr_lf();
    print_cr_lf();
    print_cr_lf();

    sleep_ms(5000);
    if (++toggle_cnt % 2) {
        H2_WRITE_MASKED(VTSS_UART_UART_MCR(VTSS_TO_UART), VTSS_F_UART_UART_MCR_LB(1), VTSS_M_UART_UART_MCR_LB);
    }   else {
        H2_WRITE_MASKED(VTSS_UART_UART_MCR(VTSS_TO_UART), 0, VTSS_M_UART_UART_MCR_LB);
    }
}
#endif /* HW_TEST_UART */


#if defined(OCELOT_6P)
static void wait_bit(u32 address, u8 bit_nr, u8 expected_value) {
    u32 value;

    do {
        value = h2_read(address);
    } while (VTSS_EXTRACT_BITFIELD(value, bit_nr, 1) != expected_value);

    return;
}


static bool take_sema0(void)
{
    u32 reg_val;
    H2_READ(VTSS_DEVCPU_ORG_DEVCPU_ORG_SEMA0, reg_val);
    if (VTSS_X_DEVCPU_ORG_DEVCPU_ORG_SEMA0_SEMA0(reg_val)) {
        return TRUE;
    } else {
        return FALSE;
    }
}


static void release_sema0(void)
{
	H2_WRITE_MASKED(VTSS_DEVCPU_ORG_DEVCPU_ORG_SEMA0,
				VTSS_F_DEVCPU_ORG_DEVCPU_ORG_SEMA0_SEMA0(1),
				VTSS_M_DEVCPU_ORG_DEVCPU_ORG_SEMA0_SEMA0);
}

static u32  owner_sema0(void)
{
    u32 reg_val;
    H2_READ(VTSS_DEVCPU_ORG_DEVCPU_ORG_SEMA0_OWNER, reg_val);
	return reg_val;
}

#if 0

static bool take_sema1(void)
{
    u32 reg_val;
    H2_READ(VTSS_DEVCPU_ORG_DEVCPU_ORG_SEMA1, reg_val);
    if (VTSS_X_DEVCPU_ORG_DEVCPU_ORG_SEMA1_SEMA1(reg_val)) {
        return TRUE;
    } else {
        return FALSE;
    }
}


static void release_sema1(void)
{
	H2_WRITE_MASKED(VTSS_DEVCPU_ORG_DEVCPU_ORG_SEMA1,
				VTSS_F_DEVCPU_ORG_DEVCPU_ORG_SEMA1_SEMA1(1),
				VTSS_M_DEVCPU_ORG_DEVCPU_ORG_SEMA1_SEMA1);
}

static u32  owner_sema1(void)
{
    u32 reg_val;
    H2_READ(VTSS_DEVCPU_ORG_DEVCPU_ORG_SEMA1_OWNER, reg_val);
	return reg_val;
}

#endif



static void update_pcie_termination_mode(bool interrupts)
{
    static u32 term_mode_old = 2;
    u32 value, term_mode_new;


    // Disable interrupts if they are enabled
    // because we will be using the unguarded
    // h2_read/h2_write functions.
    if (interrupts) {
        EA = 0;
    }

    value = h2_read(VTSS_ICPU_CFG_PCIE_PCIE_STAT);
    value = VTSS_X_ICPU_CFG_PCIE_PCIE_STAT_LTSSM_STATE(value);
    switch (value) {
    // We set termination mode to VCM only when reaching the L0
    // state of LTSSM. For all other states we use the VDD
    // termination mode.
    case 0x11:
        // VCM termination mode
        term_mode_new = 1;
        break;
    default:
        // VDD termination mode
        term_mode_new = 2;
        break;
    }

    // We trust that this application is the only one to
    // control the PCIe SerDes termination mode and this
    // way we can avoid checking the HW register and instead
    // rely on the SW stored value. We do this to reduce the
    // accesses to the MCB bus.
    if (term_mode_old == term_mode_new) {
        goto exit;
    }


    if ( term_mode_new == 1) {
	  println_str("new term_mode :VCM");
    } else if ( term_mode_new == 2) {
	  println_str("new term_mode :VDD");
    } else {
	  println_str("new term_mode :??");
    }


#if 0
    // Get the GRP lock
    do {
        do {
        } while (h2_read(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_GPR(6)) != 0x0);
        h2_write(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_GPR(6), 0xFF);
        EA = 1;
        delay_1(1);
        EA = 0;
    } while (h2_read(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_GPR(6)) != 0xFF);
#else
    // Get the SEMA0 lock
    do {
//        print_cr_lf();
//    	print_str(" show SEMA0_OWNER:");
//  	    print_hex_dw(owner_sema0());
    } while (take_sema0() != TRUE);
#endif

    // Update the PCIe SerDes termination mode
    h2_write(VTSS_HSIO_MCB_SERDES6G_CFG_MCB_SERDES6G_ADDR_CFG, 0x40000004);
    wait_bit(VTSS_HSIO_MCB_SERDES6G_CFG_MCB_SERDES6G_ADDR_CFG, 30, 0);
    h2_write_masked(VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_IB_CFG,
                    VTSS_F_HSIO_SERDES6G_ANA_CFG_SERDES6G_IB_CFG_IB_TERM_MODE_SEL(term_mode_new),
                    VTSS_M_HSIO_SERDES6G_ANA_CFG_SERDES6G_IB_CFG_IB_TERM_MODE_SEL);
    h2_write(VTSS_HSIO_MCB_SERDES6G_CFG_MCB_SERDES6G_ADDR_CFG, 0x80000004);
    wait_bit(VTSS_HSIO_MCB_SERDES6G_CFG_MCB_SERDES6G_ADDR_CFG, 31, 0);
    term_mode_old = term_mode_new;
#if 0
    // Release the GRP lock
    h2_write(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_GPR(6), 0x0);
#else
    release_sema0();
#endif

exit:
    // Enable interrupts again if they were
    // enabled in the first place.
    if (interrupts) {
        EA = 1;
    }

    return;
}
#endif // defined(OCELOT_6P)

/*****************************************************************************
 *
 *
 * Public Functions
 *
 *
 ****************************************************************************/
#if defined(OCELOT_F11) || defined(OCELOT_F10P) || defined(OCELOT_F4P)
static void _ocelot_serdes1g_4_patch(void)
{
    /* Bugzilla#20911 - Hardware pins S4_RXN#3 and S4_RXP#3 are swapped on SERDES1G_4 interface.
     *
     *  On current (rev.1) boards there is no external pull on Ocelot's MII_MDC output
     * (GPIO_14), hence when used as a GPIO (e.g. before using it as MII_MDC / alternate mode 01)
     * it will read as high due to the internal pullup resistor on the pin.
     *
     * On future (e.g. rev.2) boards I will add a 1K pulldown (R92 in the attached schematics)
     * to GPIO_14, so that it will read as low (until the pin is configured as MII_MDC output,
     * of course).
     *
     * Notice the patch only be executed when SERDES1G_4 is in used and GPIO_14 = high.
     */
    ulong addr = 1 << 4;
    ulong dat;

    // The same as h2_sd1g_read()
    h2_write(VTSS_HSIO_MCB_SERDES1G_CFG_MCB_SERDES1G_ADDR_CFG,
             VTSS_F_HSIO_MCB_SERDES1G_CFG_MCB_SERDES1G_ADDR_CFG_SERDES1G_ADDR(addr) |
             VTSS_F_HSIO_MCB_SERDES1G_CFG_MCB_SERDES1G_ADDR_CFG_SERDES1G_RD_ONE_SHOT(1));

    /* Wait until write operation is completed  */
    do {
        dat = h2_read(VTSS_HSIO_MCB_SERDES1G_CFG_MCB_SERDES1G_ADDR_CFG);
    } while(VTSS_X_HSIO_MCB_SERDES1G_CFG_MCB_SERDES1G_ADDR_CFG_SERDES1G_RD_ONE_SHOT(dat));

    h2_write_masked(VTSS_HSIO_SERDES1G_DIG_CFG_SERDES1G_MISC_CFG,
                    VTSS_F_HSIO_SERDES1G_DIG_CFG_SERDES1G_MISC_CFG_RX_DATA_INV_ENA(1),
                    VTSS_M_HSIO_SERDES1G_DIG_CFG_SERDES1G_MISC_CFG_RX_DATA_INV_ENA);

    // The same as h2_sd1g_write()
    h2_write(VTSS_HSIO_MCB_SERDES1G_CFG_MCB_SERDES1G_ADDR_CFG,
             VTSS_F_HSIO_MCB_SERDES1G_CFG_MCB_SERDES1G_ADDR_CFG_SERDES1G_ADDR(addr) |
             VTSS_F_HSIO_MCB_SERDES1G_CFG_MCB_SERDES1G_ADDR_CFG_SERDES1G_WR_ONE_SHOT(1));

    /* Wait until write operation is completed  */
    do {
        dat = h2_read(VTSS_HSIO_MCB_SERDES1G_CFG_MCB_SERDES1G_ADDR_CFG);
    } while(VTSS_X_HSIO_MCB_SERDES1G_CFG_MCB_SERDES1G_ADDR_CFG_SERDES1G_WR_ONE_SHOT(dat));
}
#endif // OCELOT_F11 || OCELOT_F10P || OCELOT_F4P

/**
 * Control initialization sequence and control round-robin loop.
 */
#if defined(OCELOT_MAIN_ENABLE)
extern void ocelot_main(void);
#endif // OCELOT_MAIN_ENABLE

void main (void)
{
//    char hw_ver;
	u32  value;
    bool warm_start = FALSE;

    /*
     * Important !!!
     *
     * Don't access the switch register via APIs H2_READ()/H2_WRITE()/H2_WRITE_MASKED()
     * before the interrupt mechanism is ready
     */

#if 1
    if (h2_read(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_GPR(7)) == 0x7) {
      warm_start = TRUE;
    }
#endif
    /* Determine hardware version */
    // Add something here to determine rev.A/rev. B board BZ#20911
//    hw_ver = get_hw_version();

    if (!warm_start) {
        /* Choice of overlaid functions
         * (rest of the GPIOs are in default mode):
         * GPIO_0  - SG0_CLK
         * GPIO_1  - SG0_DO
         * GPIO_2  - SG0_DI
         * GPIO_3  - SG0_LD
         * GPIO_6  - UART_RXD
         * GPIO_7  - UART_TXD
         * GPIO_14 - MIIM1_MDC
         * GPIO_15 - MIIM1_MDIO
         */
        h2_write(VTSS_DEVCPU_GCB_GPIO_GPIO_ALT(0), 0x0000C0CF);
    }

    /* Set up timer 0 for system tick */
    timer_1_init();

    /* Initialize drivers */
#if !defined(NO_DEBUG_IF)
    uart_init();
#endif

    /* Setup interrupts */
    ext_interrupt_init();

    /*
     * Enable global interrupt
     *
     * The interrupt mechanism is ready now.
     * Use APIs H2_READ()/H2_WRITE()/H2_WRITE_MASKED() to access switch register.
     */
    EA = 1;

    /* Wait 20 msec before accessing chip and PHYs */
    delay_1(20);

#if defined(MAIN_DEBUG_ENABLE)
    print_cr_lf();
    print_cr_lf();
    sysutil_show_chip_id();
    sysutil_show_sw_ver();
    sysutil_show_compile_date();
    sysutil_show_hw_ver();
    if (warm_start) {
      print_str("Warm start.");
    } else {
	  print_str("Cold start.");
    }  

    // Read the PCIe SerDes termination mode
	h2_sd6g_read(0x04);
	H2_READ(VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_IB_CFG, value);
	print_str(" Current PCIe termination mode :");
	print_dec(VTSS_X_HSIO_SERDES6G_ANA_CFG_SERDES6G_IB_CFG_IB_TERM_MODE_SEL(value));
	print_cr_lf();
#endif /* MAIN_DEBUG_ENABLE */





    /* Initialize memory
     * Setup SerDes macros
     * Enable PCIe (if applicable)
     * Enable the switch core */
    if (!warm_start) {
        print_cr_lf();
        h2_post_reset();
    } else {
    // Setup the 6G_2 SerDes as a PCIe interface
    // This setup must take place before we are able to
    // access the PCIe controller configuration,
    // VTSS_ICPU_CFG_PCIE, because the controller requires
    // a clock from the SerDes.
	H2_WRITE_MASKED(VTSS_HSIO_HW_CFGSTAT_HW_CFG,
                         VTSS_F_HSIO_HW_CFGSTAT_HW_CFG_PCIE_ENA(1),
								VTSS_M_HSIO_HW_CFGSTAT_HW_CFG_PCIE_ENA);

    /* Setup serdes mode (SGMII/QSGMII/2.5G and etc.) */
    h2_serdes_macro_config();

    /* Initialize memories */
    H2_WRITE(VTSS_SYS_SYSTEM_RESET_CFG,
					 VTSS_F_SYS_SYSTEM_RESET_CFG_MEM_ENA(1) |
					 VTSS_F_SYS_SYSTEM_RESET_CFG_MEM_INIT(1));
    {
      ulong cmd;

      /* Wait done flag */
      start_timer(MSEC_100);
	  do {
        H2_READ(VTSS_SYS_SYSTEM_RESET_CFG, cmd);
        } while (VTSS_X_SYS_SYSTEM_RESET_CFG_MEM_INIT(cmd) && !timeout());
    }
    if (timeout()) {
        println_str("%% Timeout for initializing memeories!");
		return;
    }

    /* Enable the switch core */
    H2_WRITE_MASKED(VTSS_SYS_SYSTEM_RESET_CFG,
                     VTSS_F_SYS_SYSTEM_RESET_CFG_CORE_ENA(1),
							VTSS_M_SYS_SYSTEM_RESET_CFG_CORE_ENA);
    }


#   if ECPU_HANDSHAKE
//#error "Handover Ocelot to eCPU.";
				/* Use a GPR to signal that the eCPU can request a takeover
				 * This register is written right after the PCIe interface
				 * is configured, in h2_post_reset(), so that the moment
				 * the eCPU has access to chip registers, it will also be able
				 * to make a takeover request. That way, the eCPU will not need
				 * to wait any amount of time for issuing the request.
				 * The iCPU will still perform all initialization tasks before
				 * replying to the eCPUs request, and that is ensured by
				 * reading this GPR only after all init tasks are completed.
				 */
				H2_WRITE(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_GPR(0), 0x01);
#   endif // ECPU_HANDSHAKE

		/* GPIO/SGPIO initialization */
		if (!warm_start) {
			gpio_init();
		}

#if 0
    // Read the PCIe SerDes termination mode
	h2_sd6g_read(0x04);
	H2_READ(VTSS_HSIO_SERDES6G_ANA_CFG_SERDES6G_IB_CFG, value);
	print_str("PCIe termination mode :");
	print_dec(VTSS_X_HSIO_SERDES6G_ANA_CFG_SERDES6G_IB_CFG_IB_TERM_MODE_SEL(value));
	print_cr_lf();
#endif

    /************************************************************************
     *
     *
     * Loop forever
     *
     *
     *
     ************************************************************************/


    while (TRUE) {
        /* For profiling/debug purposes */
        MAIN_LOOP_ENTER();

        H2_READ(VTSS_ICPU_CFG_PCIE_PCIE_STAT, value);
        /*
        The following code is needed to detect if the external CPU
        has been reset. We've to handle two main cases:
            (1) external CPU soft reset
                in that case, the read value equal 0x444 meaning
                    PM_STATE   b2..b0 = D0-Uninitialized stage.
                    LINK_STATE b5..b3 = L0 stage or not working so check LTSSM.
                    LTSSM     b11..b6 = 11Hex so LTSSM in L0 stage.
            (2) external CPU hard reset
                in that case, the read value equal 0C4hex meaning
                    PM_STATE   b2..b0 = D0-Uninitialized stage.
                    LINK_STATE b5..b3 = L0 stage or not working so check LTSSM
                    LTSSM     b11..b6 = 03Hex so LTSSM in POLL-COMPLIANCE stage.
        */
        if ((value == 0x000000c4) || (value == 0x00000444)) {
            H2_READ(VTSS_PCIE_PCIE_TYPE0_HDR_BAR0, value);
            if (value == 0) {
                if (!warm_start) {
					H2_WRITE(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_GPR(7), 0x0);
                    // This it to signal that the next start will be warm
                    H2_WRITE(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_GPR(7), 0x7);

                    println_str("eCPU reset detected. Set GPR(7)=0x7 to signal a warm start");

					// This is for the eCPU, in case it tries to connect earlier
                    H2_WRITE(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_GPR(0), 0x01);


                    println_str("Resetting switch core...");
#if 0 //reset CPU only
                    H2_WRITE_MASKED(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_RESET,
                                    VTSS_F_ICPU_CFG_CPU_SYSTEM_CTRL_RESET_CORE_RST_CPU_ONLY(0),
                                    VTSS_M_ICPU_CFG_CPU_SYSTEM_CTRL_RESET_CORE_RST_CPU_ONLY
                                   );
                    H2_WRITE_MASKED(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_RESET,
                                    VTSS_F_ICPU_CFG_CPU_SYSTEM_CTRL_RESET_CORE_RST_FORCE(1),
                                    VTSS_M_ICPU_CFG_CPU_SYSTEM_CTRL_RESET_CORE_RST_FORCE
                                   );
#else
					/*Reset switch core */
                    h2_reset();
#endif

                }
            }
        /*
        The following code is needed to reset the warm_start flag used,
        by the iCPU to avoid L2 switch reconfiguration. On ABIL we've
        ASPM running in external master CPU BIOS, so two values are checked.
            (1) when PCIE_STAT value equals 440Hex
                PM_STATE   b2..b0 = D0 stage.
                LINK_STATE b5..b3 = L0 stage or not working so check LTSSM
                LTSSM     b11..b6 = 11Hex so LTSSM in L0 stage.
            (2) when PCIE_STAT value equals 510Hex
                PM_STATE   b2..b0 = D0-Uninitialized stage.
                LINK_STATE b5..b3 = L0s stage.
                LTSSM     b11..b6 = 14Hex so LTSSM in L1_IDLE stage.
        */
        } else if ((value == 0x00000440) || (value == 0x00000510)) {
			println_str("Reset warm_start flag.  Set GPR(7)=0.");
            warm_start = FALSE;
            H2_WRITE(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_GPR(7), 0x0);
        }

        /* Handle any commands received on RS232 interface */

        // Handle 10ms timeout event
//        handle_timeout_event_10ms();

        // Handle 100ms timeout event
  //      handle_timeout_event_100ms();

        // Handle 1 second timeout event
    //    handle_timeout_event_1sec();

        /* For profiling/debug purposes */
        MAIN_LOOP_EXIT();

#   if 1
        // The application needs to constantly check
        // the state of the PCIe link state machine
        // and update the PCIe SerDes termination
        // mode accordingly.
        update_pcie_termination_mode(1);
#   endif // defined(OCELOT_6P)

#   if ECPU_HANDSHAKE
        /* Check to see if an eCPU has requested to takeover.
         * This is only done now that all initialization tasks are
         * completed by the iCPU.
         */
        H2_READ(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_GPR(0), value);
        if (value == 0x02) {
            // eCPU will take over, so disable all interrupts
            EA = 0;
            // Signal to eCPU that it can now take over
            h2_write(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_GPR(0), 0x03);
            // Although the eCPU now takes over, we still want the
            // iCPU to process one and only one thing: check
            // the state of the PCIe link state machine
            // and update the PCIe SerDes termination
            // mode accordingly. This will be needed when the
            // eCPU is rebooted and tries to re-establish
            // the PCIe link.
			print_ch('$');
            goto loop_pcie_ltssm_poll;
        }
#   endif /* ECPU_HANDSHAKE */

        /*
         * Sleep until next interrupt
         * Make sure to keep it as the last command
         */
        PCON = 0x1;
    }

#  if ECPU_HANDSHAKE
loop_pcie_ltssm_poll:
		println_str("loop_pcie_ltssm_poll");
		while (TRUE) {
#   if 1
				value = h2_read(VTSS_ICPU_CFG_PCIE_PCIE_STAT);
				/*
				The following code is needed to detect if the external CPU
				has been reset. We've to handle two main cases:
					(1) external CPU soft reset
						in that case, the read value equal 0x444 meaning
							PM_STATE   b2..b0 = D0-Uninitialized stage.
							LINK_STATE b5..b3 = L0 stage or not working so check LTSSM.
							LTSSM	  b11..b6 = 11Hex so LTSSM in L0 stage.
					(2) external CPU hard reset
						in that case, the read value equal 0C4hex meaning
							PM_STATE   b2..b0 = D0-Uninitialized stage.
							LINK_STATE b5..b3 = L0 stage or not working so check LTSSM
							LTSSM	  b11..b6 = 03Hex so LTSSM in POLL-COMPLIANCE stage.
				*/
				if ((value == 0x000000c4) || (value == 0x00000444)) {
					if (h2_read(VTSS_PCIE_PCIE_TYPE0_HDR_BAR0) == 0) {
						if (!warm_start) {
							print_str("eCPU reset detected.");
							print_cr_lf();
							h2_write(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_GPR(7), 0x7);
							h2_write_masked(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_RESET,
											VTSS_F_ICPU_CFG_CPU_SYSTEM_CTRL_RESET_CORE_RST_CPU_ONLY(0),
											VTSS_M_ICPU_CFG_CPU_SYSTEM_CTRL_RESET_CORE_RST_CPU_ONLY
										   );
							h2_write_masked(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_RESET,
											VTSS_F_ICPU_CFG_CPU_SYSTEM_CTRL_RESET_CORE_RST_FORCE(1),
											VTSS_M_ICPU_CFG_CPU_SYSTEM_CTRL_RESET_CORE_RST_FORCE
										   );
						}
					}
				/*
				The following code is needed to reset the warm_start flag used,
				by the iCPU to avoid L2 switch reconfiguration. On ABIL we've
				ASPM running in external master CPU BIOS, so two values are checked.
					(1) when PCIE_STAT value equals 440Hex
						PM_STATE   b2..b0 = D0 stage.
						LINK_STATE b5..b3 = L0 stage or not working so check LTSSM
						LTSSM	  b11..b6 = 11Hex so LTSSM in L0 stage.
					(2) when PCIE_STAT value equals 510Hex
						PM_STATE   b2..b0 = D0-Uninitialized stage.
						LINK_STATE b5..b3 = L0s stage.
						LTSSM	  b11..b6 = 14Hex so LTSSM in L1_IDLE stage.
				*/
				} else if ((value == 0x00000440) || (value == 0x00000510)) {
					warm_start = FALSE;
					h2_write(VTSS_ICPU_CFG_CPU_SYSTEM_CTRL_GPR(7), 0x0);
				}
				update_pcie_termination_mode(0);
#   endif // defined(OCELOT_6P)
			}
#  endif
}

/****************************************************************************/
/*                                                                          */
/*  End of file.                                                            */
/*                                                                          */
/****************************************************************************/
