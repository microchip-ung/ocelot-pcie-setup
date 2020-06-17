//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT

#include "common.h"     /* Always include common.h at the first place of user-defined herder files */
#include "vtss_api_base_regs.h"
#include "h2gpios.h"
#include "h2io.h"
#include "hwport.h"
#include "main.h"
#include "ledtsk.h"
#include "string.h"

#if defined(LEDTSK_DEBUG_ENABLE)
#include "print.h"
#endif /* LEDTSK_DEBUG_ENABLE */


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
typedef enum {
    VTSS_LED_TOWER_MODE_LINK_SPEED,     /**< Green: 1G link/activity; Orange: 10/100 link/activity */
    VTSS_LED_TOWER_MODE_DUPLEX,         /**< Green: FDX; Orange: HDX + Collisions */
    VTSS_LED_TOWER_MODE_LINK_STATUS,    /**< Green: Link/activity; Orange: port disabled/errors */
    VTSS_LED_TOWER_MODE_POWER_SAVE,     /**< Disabled to save power */
    VTSS_LED_TOWER_MODE_END
} vtss_led_tower_mode_t;

/*****************************************************************************
 *
 *
 * Prototypes for local functions
 *
 *
 *
 ****************************************************************************/
static void _led_update_port_by_tower_mode();

/*****************************************************************************
 *
 *
 * Local data
 *
 *
 *
 ****************************************************************************/

#if FRONT_LED_PRESENT

static uchar led_mode_timer;
static vtss_led_tower_mode_t curr_tower_mode = VTSS_LED_TOWER_MODE_LINK_SPEED; /* Default twoer mode */
static BOOL is_refresh_led = FALSE;
static char led_port_event[NO_OF_BOARD_PORTS + 1][VTSS_LED_EVENT_END];
static char curr_led_port_event[NO_OF_BOARD_PORTS + 1];

// The port_LED SGPIO mapping is different with system_LED mapping on some specific board. i.e. Ocelot reference boards
// So we have 'is_front_port' parameter to distinguish it.
static void _led_mode_set(uchar sgpio_no, vtss_led_mode_type_t mode)
{
    vtss_sgpio_mode_t sgpio_bit_0_mode, sgpio_bit_1_mode;
    bool valid_mode = TRUE;

    switch(mode) {
#if defined(OCELOT_F11) || defined(OCELOT_F10P) || defined(OCELOT_F5) || defined(OCELOT_F4P)
    // Light system LED (needs to refer to hardware schematic)
    // bit[1:0] 01 => green, 10 => red, 11 => off
    case VTSS_LED_MODE_OFF:
        sgpio_bit_1_mode = VTSS_SGPIO_MODE_ON;
        sgpio_bit_0_mode = VTSS_SGPIO_MODE_ON;
        break;
    case VTSS_LED_MODE_ON_RED:
        sgpio_bit_1_mode = VTSS_SGPIO_MODE_ON;
        sgpio_bit_0_mode = VTSS_SGPIO_MODE_OFF;
        break;
    case VTSS_LED_MODE_BLINK_RED:
        sgpio_bit_1_mode = VTSS_SGPIO_MODE_ON;
        sgpio_bit_0_mode = VTSS_SGPIO_MODE_BL_0;
        break;
    case VTSS_LED_MODE_ON_GREEN:
        sgpio_bit_1_mode = VTSS_SGPIO_MODE_OFF;
        sgpio_bit_0_mode = VTSS_SGPIO_MODE_ON;
        break;
    case VTSS_LED_MODE_BLINK_GREEN:
        sgpio_bit_1_mode = VTSS_SGPIO_MODE_BL_0;
        sgpio_bit_0_mode = VTSS_SGPIO_MODE_ON;
        break;
    case VTSS_LED_MODE_LINK_ACTIVITY_GREEN:
        sgpio_bit_1_mode = VTSS_SGPIO_MODE_LACT_0;
        sgpio_bit_0_mode = VTSS_SGPIO_MODE_ON;
        break;
    case VTSS_LED_MODE_ON_YELLOW:
        sgpio_bit_1_mode = VTSS_SGPIO_MODE_OFF;
        sgpio_bit_0_mode = VTSS_SGPIO_MODE_OFF;
        break;
    case VTSS_LED_MODE_BLINK_YELLOW:
        sgpio_bit_1_mode = sgpio_bit_0_mode = VTSS_SGPIO_MODE_BL_0;
        break;
    case VTSS_LED_MODE_LINK_ACTIVITY_YELLOW:
        sgpio_bit_1_mode = sgpio_bit_0_mode = VTSS_SGPIO_MODE_LACT_0;
        break;

#endif

    default :
#if defined(LEDTSK_DEBUG_ENABLE)
        print_str("%% Error: Wrong parameter when calling _led_mode_set(FALSE, ), mode=0x");
        print_hex_b(mode);
        print_cr_lf();
#endif /* LEDTSK_DEBUG_ENABLE */
        valid_mode = FALSE;
        break;
    }

    if (valid_mode) {
        h2_sgpio_write(sgpio_no, VTSS_SGPIO_BIT_1, sgpio_bit_1_mode);
        h2_sgpio_write(sgpio_no, VTSS_SGPIO_BIT_0, sgpio_bit_0_mode);
    }
}

#if defined(HW_LED_TOWER_PRESENT)
static void _led_update_tower(uchar mode)
/* ------------------------------------------------------------------------ --
 * Purpose     : Setup mode LED mode
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
  
}
#endif /* HW_LED_TOWER_PRESENT */

/* ************************************************************************ */
void led_tsk(void)
/* ------------------------------------------------------------------------ --
 * Purpose     : Detects button and setup port led accordingly
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
#if defined(HW_LED_TOWER_PRESENT)
    /* GPIO bit 16 is for push button */
    if (h2_gpio_read(16)) {
        curr_tower_mode = (++curr_tower_mode) % VTSS_LED_TOWER_MODE_END;

        /* Mode C not supported in the unmanaged solution */
        if (curr_tower_mode == VTSS_LED_TOWER_MODE_LINK_STATUS) {
            curr_tower_mode++;
        }
        led_mode_timer = LED_MODE_DEFAULT_TIME;
    } else if (led_mode_timer == 0) {
        curr_tower_mode = VTSS_LED_TOWER_MODE_POWER_SAVE;

    }

    _led_update_tower(curr_tower_mode);
    _led_update_port_by_tower_mode();
#endif /* HW_LED_TOWER_PRESENT */

    if (is_refresh_led && curr_tower_mode != VTSS_LED_TOWER_MODE_POWER_SAVE) {
        /* Update front LEDs */
        _led_update_port_by_tower_mode();
    }

    is_refresh_led = FALSE;

    /*
    **  Fixme:
    **  1) Setup other led/sgpio outputs, such as LED tower
    **  and sgpio port 26-31 for general purpose in the function
    **  or a new function
    **  2) To implement a callback function to update port led
    **  output for link change (up/down)
    **  3) To implement polling for switch counters to detect
    **  collisions at HDX for VTSS_LED_TOWER_MODE_DUPLEX mode and detect
    **  errors for VTSS_LED_TOWER_MODE_LINK_STATUS mode.
    **  4) Possibily create API for sgpio read. (Note: to read data
    **  in you need to issue two bursts, one for LD and one for
    **  clocking in)
    */
}

/* ************************************************************************ */
static void _led_update_port_by_tower_mode(void)
/* ------------------------------------------------------------------------ --
 * Purpose     : Setup port LED mode
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    vtss_iport_no_t iport_idx;
    vtss_cport_no_t chip_port;
    uchar link_mode;

    for (iport_idx = MIN_PORT; iport_idx < MAX_PORT; iport_idx++) {
        if (curr_led_port_event[iport_idx] != VTSS_LED_MODE_NORMAL) {
            /* at least one of error events occurs, just show the error status */
            continue;
        }

        chip_port = iport2cport(iport_idx);
        link_mode = port_link_mode_get(chip_port);

#if defined(LEDTSK_DEBUG_ENABLE)
    print_str("Calling _led_update_port_by_tower_mode(): iport_idx=0x");
    print_hex_b(iport_idx);

    print_str(", chip_port=0x");
    print_hex_b(chip_port);

    print_str(", link_mode=0x");
    print_hex_b(link_mode);
    print_str(", curr_tower_mode=0x");
    print_hex_b(curr_tower_mode);
    print_cr_lf();
#endif /* LEDTSK_DEBUG_ENABLE */

        switch (curr_tower_mode) {
#if defined(HW_LED_TOWER_PRESENT)
        case VTSS_LED_TOWER_MODE_POWER_SAVE:
            /* Force off no matter link is up or not */
            _led_mode_set(chip_port, VTSS_LED_MODE_OFF);
            break;

        case VTSS_LED_TOWER_MODE_DUPLEX:
            /* Duplex mode; Green for FDX and Yellow for HDX */
            if (link_mode == LINK_MODE_DOWN) {
                /* Link down */
                _led_mode_set(chip_port, VTSS_LED_MODE_OFF);
            } else if (link_mode & LINK_MODE_FDX_MASK) {
                /* Green: FDX */
                _led_mode_set(chip_port, VTSS_LED_MODE_ON_GREEN);
            } else {
                {
                    /* no collision, turn on LED - Yellow/On: HDX */
                    _led_mode_set(chip_port, VTSS_LED_MODE_ON_YELLOW);
                }
            }
            break;

        case VTSS_LED_TOWER_MODE_LINK_STATUS:
            /* Green for link/activity; Yellow: Port disabled */
            if (link_mode == LINK_MODE_DOWN) {
                /* Link down */
                _led_mode_set(chip_port, VTSS_LED_MODE_OFF);
            } else if (link_mode & LINK_MODE_SPEED_MASK) {
                /* Green: Link/activity */
                _led_mode_set(chip_port, VTSS_LED_MODE_LINK_ACTIVITY_GREEN);
            } else {
                /* Yellow: Port disabled */
                _led_mode_set(chip_port, VTSS_LED_MODE_ON_YELLOW);
            }
            break;

#endif /* HW_LED_TOWER_PRESENT */

        case VTSS_LED_TOWER_MODE_LINK_SPEED:
            /* Link/activity; Green for 1G and Yellow for 10/100 */
            if (link_mode == LINK_MODE_DOWN) {
                /* Link down */
                _led_mode_set(chip_port, VTSS_LED_MODE_OFF);
            } else if ((link_mode & LINK_MODE_SPEED_MASK) == LINK_MODE_SPEED_10 ||
                       (link_mode & LINK_MODE_SPEED_MASK) == LINK_MODE_SPEED_100) {
                /* Yellow: 100/10 link/activity */
                _led_mode_set(chip_port, VTSS_LED_MODE_LINK_ACTIVITY_YELLOW);
            } else {
                /* Green: 1G/2.5G link/activity */
                _led_mode_set(chip_port, VTSS_LED_MODE_LINK_ACTIVITY_GREEN);
            }
            break;

        default:
            break;
        }
    }
}

void led_refresh(void)
{
    is_refresh_led = TRUE;
}


/* ************************************************************************ */
void led_init(void)
/* ------------------------------------------------------------------------ --
 * Purpose     : SGPIO controller setup based on board
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{

    /* Given an initial state/value */
    memset(curr_led_port_event, VTSS_LED_MODE_NORMAL, sizeof(curr_led_port_event));
    memset(led_port_event, 0, sizeof(led_port_event));

    led_mode_timer = LED_MODE_DEFAULT_TIME;

    /* Light status LED green */
    led_update_system(VTSS_LED_MODE_ON_GREEN);

#if defined(HW_LED_TOWER_PRESENT)
    /* Light tower LED */
    _led_update_tower(VTSS_LED_TOWER_MODE_LINK_SPEED);
#endif /* HW_LED_TOWER_PRESENT */

    /* Light port LED */
    _led_update_port_by_tower_mode();
}


void led_update_system(vtss_led_mode_type_t mode)
{
#if defined(SYS_LED_SGPIO_PORT)
    _led_mode_set(SYS_LED_SGPIO_PORT, mode);
#endif /* SYS_LED_SGPIO_PORT */
}

void led_1s_timer(void)
{
    static uchar i = 0;
    
    led_update_system(i++ % 2 ? VTSS_LED_MODE_ON_GREEN : VTSS_LED_MODE_OFF);   
   
    if (led_mode_timer != 0)
        led_mode_timer--;
}
#endif //FRONT_LED_PRESENT
