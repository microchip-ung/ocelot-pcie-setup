//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT

#include "common.h"     /* Always include common.h at the first place of user-defined herder files */

#include "hwport.h"

#include "main.h"
#include "vtss_api_base_regs.h"
#include "h2gpios.h"
#include "h2io.h"
#include "timer.h"
#include "version.h"

#if defined(HWPORT_DEBUG_ENABLE)
#include "print.h"
#endif /* HWPORT_DEBUG_ENABLE */

/*****************************************************************************
 *
 *
 * Defines
 *
 *
 *
 ****************************************************************************/

/*****************************************************************************
 *
 *
 * Typedefs and enums
 *
 *
 *
 ****************************************************************************/

/*****************************************************************************
 *
 *
 * Prototypes for local functions
 *
 *
 *
 ****************************************************************************/

/*****************************************************************************
 *
 *
 * Public data
 *
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
static code uchar port2ext_tab [NO_OF_CHIP_PORTS] = CPORT_MAPTO_UPORT;
static code uchar port2int_tab [NO_OF_BOARD_PORTS] = UPORT_MAPTO_CPORT;

/*****************************************************************************
 *
 *
 * Public Functions
 *
 *
 ****************************************************************************/

// Chip/Switch port (zero-based) --> User/Front port (one-based)
vtss_uport_no_t cport2uport(vtss_cport_no_t chip_port)
{
    if (chip_port < NO_OF_CHIP_PORTS) { // Avoid memory leak issue
        return port2ext_tab[chip_port];
    }

#if defined(HWPORT_DEBUG_ENABLE)
    print_str("%% Error: Wrong parameter when calling cport2uport(), chip_port=0x");
    print_hex_b(chip_port);
    print_cr_lf();
#endif /* HWPORT_DEBUG_ENABLE */
    return 0xFF; // Failed case
}

// User/Front port (one-based) --> Chip/Switch port (zero-based)
vtss_cport_no_t uport2cport(vtss_uport_no_t uport)
{
    if (uport > 0 && uport <= NO_OF_BOARD_PORTS) { // Avoid memory leak issue
        return port2int_tab[uport - 1];
    }

#if defined(HWPORT_DEBUG_ENABLE)
    print_str("%% Error: Wrong parameter when calling uport2cport(), uport=0x");
    print_hex_b(uport);
    print_cr_lf();
#endif /* HWPORT_DEBUG_ENABLE */
    return 0xFF; // Failed case
}


char get_hw_version(void)
{
    static char hw_ver = '\0'; // Initial value
    /*
     * Important !!!
     *
     * Don't access the switch register via APIs H2_READ()/H2_WRITE()/H2_WRITE_MASKED()
     * before the interrupt mechanism is ready
     */
#if defined(OCELOT_F11) || defined(OCELOT_F10P)
    /*Power: grid = 0x1d, level = 1, polarity = 1, lane = 2  */
    h2_write(VTSS_DEVCPU_GCB_CHIP_REGS_FEA_DIS, 0x1d<<10 | 0x1<<8 | 0x1<<4 | 0x2);
#elif defined(OCELOT_6P)
    /*Power: grid = 0x1d, level = 1, polarity = 1, lane = 4 */
    h2_write(VTSS_DEVCPU_GCB_CHIP_REGS_FEA_DIS, 0x1d<<10 | 0x1<<8 | 0x1<<4 | 0x4);
#else
    /*Power: grid = 0x1d, level = 1, polarity = 1, lane = 1 */
	  h2_write(VTSS_DEVCPU_GCB_CHIP_REGS_FEA_DIS, 0x1d<<10 | 0x1<<8 | 0x1<<4 | 0x1);
#endif
    /* Read GPIO_14 value to decide the HW Revision
     *  On current (rev.1) boards there is no external pull on Ocelot's MII_MDC output
     * (GPIO_14), hence when used as a GPIO (e.g. before using it as MII_MDC / alternate mode 01)
     * it will read as high due to the internal pullup resistor on the pin.
     *
     * On future (e.g. rev.2) boards I will add a 1K pulldown (R92 in the attached schematics)
     * to GPIO_14, so that it will read as low (until the pin is configured as MII_MDC output,
     * of course).
     */
    if (hw_ver == '\0') { // Only detect in the initial stage
        ulong mask = VTSS_BIT(14);
        ulong orig_reg_val, reg_val;
        ulong busy_loop = 10000; // Use busy loop to avoid timer not ready yet
        orig_reg_val = h2_read(VTSS_DEVCPU_GCB_GPIO_GPIO_ALT(0));
        h2_write(VTSS_DEVCPU_GCB_GPIO_GPIO_ALT(0), 0x0);
        while(busy_loop--);
        reg_val = h2_read(VTSS_DEVCPU_GCB_GPIO_GPIO_IN);
        h2_write(VTSS_DEVCPU_GCB_GPIO_GPIO_ALT(0), orig_reg_val);
        hw_ver = VTSS_BOOL(reg_val & mask) ? '1' : '2';
    }
    return hw_ver;
}


/* GPIO/SGPIO initialization */
void gpio_init(void)
{
#if !defined(CUSTOM_BOARD)
    h2_sgpio_enable();
#endif /* !defined(CUSTOM_BOARD) */
}

/*****************************************************************************
 *                                                                           *
 *  End of file.                                                             *
 *                                                                           *
 *****************************************************************************/

