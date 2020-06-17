//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT

#include "common.h"     /* Always include common.h at the first place of user-defined herder files */

#include "vtss_api_base_regs.h"
#include "h2gpios.h"
#include "h2io.h"
#include "timer.h" // delay()

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
 *
 ****************************************************************************/

#if !defined(OCELOT_6P)
/* ************************************************************************ */
void h2_gpio_mode_set(uchar gpio_no, vtss_gpio_mode_t mode)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    ulong mask = VTSS_BIT(gpio_no);

    H2_WRITE_MASKED(VTSS_DEVCPU_GCB_GPIO_GPIO_INTR_ENA, 0, mask); /* Disable IRQ */
    switch(mode) {
    case VTSS_GPIO_OUT:
    case VTSS_GPIO_IN:
    case VTSS_GPIO_IN_INT:
        H2_WRITE_MASKED(VTSS_DEVCPU_GCB_GPIO_GPIO_ALT(0), 0, mask); /* GPIO mode 0b00 */
        H2_WRITE_MASKED(VTSS_DEVCPU_GCB_GPIO_GPIO_ALT(1), 0, mask); /* -"- */
        H2_WRITE_MASKED(VTSS_DEVCPU_GCB_GPIO_GPIO_OE, mode == VTSS_GPIO_OUT ? mask : 0, mask);
        if (mode == VTSS_GPIO_IN_INT)
            H2_WRITE_MASKED(VTSS_DEVCPU_GCB_GPIO_GPIO_INTR_ENA, mask, mask);
        break;
    case VTSS_GPIO_ALT_0:
        H2_WRITE_MASKED(VTSS_DEVCPU_GCB_GPIO_GPIO_ALT(0), mask, mask); /* GPIO mode 0b01 */
        H2_WRITE_MASKED(VTSS_DEVCPU_GCB_GPIO_GPIO_ALT(1), 0,    mask); /* -"- */
        break;
    case VTSS_GPIO_ALT_1:
        H2_WRITE_MASKED(VTSS_DEVCPU_GCB_GPIO_GPIO_ALT(0), 0,    mask); /* GPIO mode 0b10 */
        H2_WRITE_MASKED(VTSS_DEVCPU_GCB_GPIO_GPIO_ALT(1), mask, mask); /* -"- */
        break;
    }
}

/* ************************************************************************ */
uchar h2_gpio_read(uchar gpio_no)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    ulong mask = VTSS_BIT(gpio_no);
    ulong value;
    H2_READ(VTSS_DEVCPU_GCB_GPIO_GPIO_IN, value);
    return VTSS_BOOL(value & mask);
}

/* ************************************************************************ */
void h2_gpio_write(uchar gpio_no, BOOL output_high)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
#if defined(VTSS_ARCH_OCELOT)
    if (output_high) {
        H2_WRITE_MASKED(VTSS_DEVCPU_GCB_GPIO_GPIO_OUT_SET,
                        VTSS_F_DEVCPU_GCB_GPIO_GPIO_OUT_SET_G_OUT_SET(VTSS_BIT(gpio_no)),
                        VTSS_M_DEVCPU_GCB_GPIO_GPIO_OUT_SET_G_OUT_SET);
    } else {
        H2_WRITE_MASKED(VTSS_DEVCPU_GCB_GPIO_GPIO_OUT_CLR,
                        VTSS_F_DEVCPU_GCB_GPIO_GPIO_OUT_CLR_G_OUT_CLR(VTSS_BIT(gpio_no)),
                        VTSS_M_DEVCPU_GCB_GPIO_GPIO_OUT_SET_G_OUT_SET);
    }

#endif // VTSS_ARCH_OCELOT
}
#endif /* !defined(OCELOT_6P) */


#if !defined(CUSTOM_BOARD)
/* ************************************************************************ */
void h2_sgpio_write(uchar sgpio_no, uchar bit_no, ushort mode)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
#if defined(VTSS_ARCH_OCELOT)
    BOOL inversed_polarity = FALSE; /* (needs to refer to hardware schematic) */
#endif

    switch (bit_no) {
    /* Inversed polarity (needs to refer to hardware schematic) */
    case VTSS_SGPIO_BIT_0:
        H2_WRITE_MASKED(VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG(sgpio_no),
                        VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_BIT_SOURCE(mode) |
                        VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_BIT_POLARITY(inversed_polarity),
                        VTSS_ENCODE_BITMASK(12, 3) |
                        VTSS_ENCODE_BITMASK(0, 1));
        break;
    case VTSS_SGPIO_BIT_1:
        H2_WRITE_MASKED(VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG(sgpio_no),
                        VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_BIT_SOURCE(mode << 3) |
                        VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_BIT_POLARITY(inversed_polarity << 1),
                        VTSS_ENCODE_BITMASK(15, 3) |
                        VTSS_ENCODE_BITMASK(1, 1));
        break;
    case VTSS_SGPIO_BIT_2:
        H2_WRITE_MASKED(VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG(sgpio_no),
                        VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_BIT_SOURCE(mode << 6) |
                        VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_BIT_POLARITY(inversed_polarity << 2),
                        VTSS_ENCODE_BITMASK(18, 3) |
                        VTSS_ENCODE_BITMASK(2, 1));
        break;
    case VTSS_SGPIO_BIT_3:
        H2_WRITE_MASKED(VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG(sgpio_no),
                        VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_BIT_SOURCE(mode << 9) |
                        VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_BIT_POLARITY(inversed_polarity << 3),
                        VTSS_ENCODE_BITMASK(21, 3) |
                        VTSS_ENCODE_BITMASK(3, 1));
        break;

    default:
        break;
    }

    delay_1(1);
}
#endif /* !defined(CUSTOM_BOARD) */

#if !defined(FRONT_LED_PRESENT)
/* Set system LED
 * Only light system LED when FRONT_LED_PRESENT is undefined
 */
static void _h2_sgpio_sys_led_init(void)
{
#if defined(OCELOT_F11) || defined(OCELOT_F10P) || defined(OCELOT_F5) || defined(OCELOT_F4P)
    // Light system LED: Green (needs to refer to hardware schematic)
    // 2 SGPIO per port
    // bit[1:0] 00 => yellow, 01 => red, 10 => green, 11 => off
    h2_sgpio_write(SYS_LED_SGPIO_PORT, 0, VTSS_SGPIO_MODE_OFF);
    h2_sgpio_write(SYS_LED_SGPIO_PORT, 1, VTSS_SGPIO_MODE_ON);
#endif
}
#endif // !FRONT_LED_PRESENT

#if !defined(CUSTOM_BOARD)
/* ************************************************************************ */
void h2_sgpio_enable(void)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    uchar gpio;

    /* Setup SGPIO pins.
     * Before using SGPIO, we need to enable GPIO 0-3 as SGPIO pins. (needs to refer to hardware schematic)
     * This is done in 'main.c' before calling this function.
     */

    /* Setup SGPIO configuration
     * SIO_PORT_WIDTH   : 2 SGPIO per port (needs to refer to hardware schematic)
     * SIO_BMODE_0      : Blink speed to 0.625Hz
     * SIO_BMODE_1      : Blink speed to 10Hz
     * IO_BURST_GAP_DIS : Enable burst gap
     * SIO_BURST_GAP    : Burst gap to 53.69 ms
     * SIO_LD_POLARITY  : Active low mode (needs to refer to hardware schematic)
     * AUTO_REPEAT      : Enable
     */
    H2_WRITE(VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG,
             VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_PORT_WIDTH(1) |
             VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BMODE_0(3) |
             VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BMODE_1(1) |
             VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BURST_GAP_DIS(0) |
             VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BURST_GAP(31) |
             VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_LD_POLARITY(0) |
             VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_AUTO_REPEAT(1));

    /* Setup the SGPIO clock (needs to be between 1MHz and 10MHz) */
    H2_WRITE_MASKED(VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CLOCK,
                    VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CLOCK_SIO_CLK_FREQ(50),
                    VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CLOCK_SIO_CLK_FREQ);

#if defined(OCELOT_6P)
    H2_WRITE(VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR_POL(0), 0x1); //LOS active high
    H2_WRITE(VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR_POL(1), 0x2);
    H2_WRITE(VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR_POL(2), 0x2);
    H2_WRITE(VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR_POL(3), 0x2);
#endif /* defined(OCELOT_6P) */

    /* Enable SGPIO ports (needs to refer to hardware schematic) */
#if defined(OCELOT_F11) || defined(OCELOT_F10P) || defined(OCELOT_F5) || defined(OCELOT_F4P)
    H2_WRITE(VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PORT_ENA, LED_PORTS);
#elif defined(OCELOT_6P)
    /* Only using SGPIO ports 18-19 and 22-23 */
    H2_WRITE(VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PORT_ENA, 0x00CC1FFF);
#endif

#if defined(OCELOT_F11) || defined(OCELOT_F10P) || defined(OCELOT_F5) || defined(OCELOT_F4P)
    // Light off all front ports
    for (gpio = 0; gpio < NO_OF_CHIP_PORTS; gpio++) {
        if (VTSS_EXTRACT_BITFIELD(LED_PORTS, gpio, 1)) {
            h2_sgpio_write(gpio, 0, VTSS_SGPIO_MODE_ON);
            h2_sgpio_write(gpio, 1, VTSS_SGPIO_MODE_ON);
        }
    }
#endif // OCELOT_F11 || OCELOT_F10P || OCELOT_F5 || OCELOT_F4P

#if defined(OCELOT_6P)
    // Switch off all LEDs, this target does not offer LED support
    // LEDs are off when '1' is written to the respective SGPIO
    // pin, thus we use 'VTSS_SGPIO_MODE_ON'.
    for (gpio = 0; gpio <= 12; gpio++) {
        h2_sgpio_write(gpio, 0, VTSS_SGPIO_MODE_ON);
        h2_sgpio_write(gpio, 1, VTSS_SGPIO_MODE_ON);
    }
#endif

#if !defined(FRONT_LED_PRESENT)
    _h2_sgpio_sys_led_init();
#endif // !FRONT_LED_PRESENT
}
#endif /* !defined(CUSTOM_BOARD) */

