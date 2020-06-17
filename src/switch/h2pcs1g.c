//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT

#include "common.h"     /* Always include common.h at the first place of user-defined herder files */

#if MAC_TO_MEDIA

#include "vtss_api_base_regs.h"
#include "h2pcs1g.h"
#include "main.h"
#include "timer.h"
#include "misc2.h"
#include "h2io.h"
#include "h2sdcfg.h"
#include "print.h"


#if TRANSIT_LACP
#include "vtss_lacp.h"
#endif /* TRANSIT_LACP */

/*****************************************************************************
 *
 *
 * Defines
 *
 *
 *
 ****************************************************************************/
#if defined(H2_PCS1G_DEBUG_ENABLE)
#include "print.h"
#endif /* H2_PCS1G_DEBUG_ENABLE */


/**
 * Test whether a bitfield is set in value.
 */
#define BF(__field__, __value__) (((__field__ & __value__) == __field__) ? 1 : 0)

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
 * Local data
 *
 *
 *
 ****************************************************************************/

static uchar xdata clause_37_flowcontrol[NO_OF_CHIP_PORTS];

#ifdef SGMII_SERDES_FORCE_1G
/* ************************************************************************ */
uchar h2_pcs1g_status_get(const vtss_cport_no_t chip_port)
/* ------------------------------------------------------------------------ --
 * Purpose     : Get PCS1G Status ANEG disabled
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    ulong   value;
    uchar   link,lm = LINK_MODE_DOWN;
    ulong   tgt = VTSS_TO_DEV(chip_port);

    /* 1. Read PCS link status */
    H2_READ(VTSS_DEV_PCS1G_CFG_STATUS_PCS1G_LINK_STATUS(tgt), value);

    /* Get PCS link status bit(4)*/
    link = VTSS_X_DEV_PCS1G_CFG_STATUS_PCS1G_LINK_STATUS_LINK_STATUS(value);

    if (link) {
        lm = LINK_MODE_FDX_1000;
		lm |= LINK_MODE_PAUSE_MASK;
    } else if (!link) {
		lm = LINK_MODE_DOWN;
	}

    return lm;
}
#endif

/* ************************************************************************ */
uchar h2_pcs1g_100fx_status_get(const vtss_cport_no_t chip_port)
/* ------------------------------------------------------------------------ --
 * Purpose     : Get the 100FX (fiber) port status (no autonegotiation)
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    ulong value;
    ulong tgt = VTSS_TO_DEV(chip_port);
    uchar link_mode = LINK_MODE_DOWN;

    /* Get the PCS status  */
    H2_READ(VTSS_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS(tgt), value);

    if (BF(VTSS_M_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_SYNC_LOST_STICKY, value) ||
        BF(VTSS_M_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_SSD_ERROR_STICKY, value) ||
        BF(VTSS_M_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_FEF_FOUND_STICKY, value) ||
        BF(VTSS_M_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_PCS_ERROR_STICKY, value) ||
        BF(VTSS_M_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_FEF_STATUS, value))

    {
#if defined(H2_PCS1G_DEBUG_ENABLE)
        if (port_link_mode_get(chip_port) != LINK_MODE_DOWN) {
            print_str("Calling h2_pcs1g_100fx_status_get(), chip_port=0x");
            print_hex_b(chip_port);
            print_str(", value=0x");
            print_hex_dw(value);
            print_cr_lf();
        }
#endif // H2_PCS1G_DEBUG_ENABLE

        /* The link has been down. Clear the sticky bit */
        H2_WRITE_MASKED(VTSS_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS(tgt),
                        VTSS_F_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_SYNC_LOST_STICKY(1) |
                        VTSS_F_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_SSD_ERROR_STICKY(1) |
                        VTSS_F_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_FEF_FOUND_STICKY(1) |
                        VTSS_F_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_PCS_ERROR_STICKY(1),
                        VTSS_M_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_SYNC_LOST_STICKY |
                        VTSS_M_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_SSD_ERROR_STICKY |
                        VTSS_M_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_FEF_FOUND_STICKY |
                        VTSS_M_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_PCS_ERROR_STICKY);
        delay_1(1); // BZ18779
        H2_READ(VTSS_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS(tgt), value);
    }

    if (BF(VTSS_M_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_SIGNAL_DETECT, value) &&
        BF(VTSS_M_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_SYNC_STATUS, value) &&
        !BF(VTSS_M_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_SYNC_LOST_STICKY, value) &&
        !BF(VTSS_M_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_SSD_ERROR_STICKY, value) &&
        !BF(VTSS_M_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_FEF_FOUND_STICKY, value) &&
        !BF(VTSS_M_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_PCS_ERROR_STICKY, value) &&
        !BF(VTSS_M_DEV_PCS_FX100_STATUS_PCS_FX100_STATUS_FEF_STATUS, value))
    {
        link_mode = LINK_MODE_FDX_100;
    }
    return link_mode;
}

/* ************************************************************************ */
void h2_pcs1g_clock_set(vtss_cport_no_t chip_port, BOOL enable)
/* ------------------------------------------------------------------------ --
 * Purpose     : Set PCS clock
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    // EA = 0; // Disable interrupt while doing the clock reset.
    H2_WRITE_MASKED(VTSS_DEV_PORT_MODE_CLOCK_CFG( VTSS_TO_DEV(chip_port)),
                    VTSS_F_DEV_PORT_MODE_CLOCK_CFG_PCS_TX_RST(!enable) |
                    VTSS_F_DEV_PORT_MODE_CLOCK_CFG_PCS_RX_RST(!enable) |
                    VTSS_F_DEV_PORT_MODE_CLOCK_CFG_PORT_RST(!enable),
                    VTSS_M_DEV_PORT_MODE_CLOCK_CFG_PCS_TX_RST |
                    VTSS_M_DEV_PORT_MODE_CLOCK_CFG_PCS_RX_RST |
                    VTSS_M_DEV_PORT_MODE_CLOCK_CFG_PORT_RST);
    // EA = 1; // Enable interrupt

    delay_1(1); // Small delay after clock reset
}

/* ************************************************************************ */
void h2_pcs1g_setup(vtss_cport_no_t chip_port, mac_if_type_t if_type)
/* ------------------------------------------------------------------------ --
 * Purpose     : Enable psc1g serdes, sgmii or 100fx
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    ulong tgt = VTSS_TO_DEV(chip_port);

    switch(if_type) {
    case MAC_IF_SERDES_2_5G:
    case MAC_IF_SERDES_1G: {
        /* Speed setup and enable PCS clock */
        H2_WRITE_MASKED(VTSS_DEV_PORT_MODE_CLOCK_CFG(tgt),
                        VTSS_F_DEV_PORT_MODE_CLOCK_CFG_LINK_SPEED(1) /* 1000/2500 Mbps */,
                        VTSS_M_DEV_PORT_MODE_CLOCK_CFG_LINK_SPEED);
        h2_pcs1g_clock_set(chip_port, TRUE);

        /* Set MAC Mode Configuration */
        H2_WRITE_MASKED(VTSS_DEV_MAC_CFG_STATUS_MAC_MODE_CFG(tgt),
                        VTSS_F_DEV_MAC_CFG_STATUS_MAC_MODE_CFG_GIGA_MODE_ENA(1) |
                        VTSS_F_DEV_MAC_CFG_STATUS_MAC_MODE_CFG_FDX_ENA(1),
                        VTSS_M_DEV_MAC_CFG_STATUS_MAC_MODE_CFG_GIGA_MODE_ENA |
                        VTSS_M_DEV_MAC_CFG_STATUS_MAC_MODE_CFG_FDX_ENA); // giga & fdx

        /* Enable PCS */
        H2_WRITE_MASKED(VTSS_DEV_PCS1G_CFG_STATUS_PCS1G_CFG(tgt),
                        VTSS_F_DEV_PCS1G_CFG_STATUS_PCS1G_CFG_PCS_ENA(1),
                        VTSS_M_DEV_PCS1G_CFG_STATUS_PCS1G_CFG_PCS_ENA);

        /* Set PCS1G mode configuration: SERDES mode */
        H2_WRITE_MASKED(VTSS_DEV_PCS1G_CFG_STATUS_PCS1G_MODE_CFG(tgt),
                        VTSS_F_DEV_PCS1G_CFG_STATUS_PCS1G_MODE_CFG_UNIDIR_MODE_ENA(0) |
                        VTSS_F_DEV_PCS1G_CFG_STATUS_PCS1G_MODE_CFG_SGMII_MODE_ENA(0),
                        VTSS_M_DEV_PCS1G_CFG_STATUS_PCS1G_MODE_CFG_UNIDIR_MODE_ENA |
                        VTSS_M_DEV_PCS1G_CFG_STATUS_PCS1G_MODE_CFG_SGMII_MODE_ENA);

        /* Set PCS1G Auto-negotiation configuration: Software Resolve Abilities */
        H2_WRITE_MASKED(VTSS_DEV_PCS1G_CFG_STATUS_PCS1G_ANEG_CFG(tgt),
                        VTSS_F_DEV_PCS1G_CFG_STATUS_PCS1G_ANEG_CFG_SW_RESOLVE_ENA(0),
                        VTSS_M_DEV_PCS1G_CFG_STATUS_PCS1G_ANEG_CFG_SW_RESOLVE_ENA);

        /* Set Configuration bit groups for 100Base-FX PCS: Disable 100FX PCS */
        H2_WRITE_MASKED(VTSS_DEV_PCS_FX100_CONFIGURATION_PCS_FX100_CFG(tgt),
                        VTSS_F_DEV_PCS_FX100_CONFIGURATION_PCS_FX100_CFG_PCS_ENA(0),
                        VTSS_M_DEV_PCS_FX100_CONFIGURATION_PCS_FX100_CFG_PCS_ENA);
        return;
    }

    case MAC_IF_SGMII: {
        /* Speed setup and enable PCS clock */
        H2_WRITE_MASKED(VTSS_DEV_PORT_MODE_CLOCK_CFG(tgt),
                        VTSS_F_DEV_PORT_MODE_CLOCK_CFG_LINK_SPEED(1) /* 1000/2500 Mbps */,
                        VTSS_M_DEV_PORT_MODE_CLOCK_CFG_LINK_SPEED);
        h2_pcs1g_clock_set(chip_port, TRUE);

        /* Enable PCS */
        H2_WRITE_MASKED(VTSS_DEV_PCS1G_CFG_STATUS_PCS1G_CFG(tgt),
                        VTSS_F_DEV_PCS1G_CFG_STATUS_PCS1G_CFG_PCS_ENA(1),
                        VTSS_M_DEV_PCS1G_CFG_STATUS_PCS1G_CFG_PCS_ENA);

        /* Set PCS1G mode configuration: SGMII mode */
        H2_WRITE_MASKED(VTSS_DEV_PCS1G_CFG_STATUS_PCS1G_MODE_CFG(tgt),
                        VTSS_F_DEV_PCS1G_CFG_STATUS_PCS1G_MODE_CFG_UNIDIR_MODE_ENA(0) |
                        VTSS_F_DEV_PCS1G_CFG_STATUS_PCS1G_MODE_CFG_SGMII_MODE_ENA(1),
                        VTSS_M_DEV_PCS1G_CFG_STATUS_PCS1G_MODE_CFG_UNIDIR_MODE_ENA |
                        VTSS_M_DEV_PCS1G_CFG_STATUS_PCS1G_MODE_CFG_SGMII_MODE_ENA);

        /* Set PCS1G Auto-negotiation configuration: Software Resolve Abilities */
        H2_WRITE_MASKED(VTSS_DEV_PCS1G_CFG_STATUS_PCS1G_ANEG_CFG(tgt),
                        VTSS_F_DEV_PCS1G_CFG_STATUS_PCS1G_ANEG_CFG_SW_RESOLVE_ENA(1),
                        VTSS_M_DEV_PCS1G_CFG_STATUS_PCS1G_ANEG_CFG_SW_RESOLVE_ENA);

        /* Set Configuration bit groups for 100Base-FX PCS: Disable 100FX PCS */
        H2_WRITE_MASKED(VTSS_DEV_PCS_FX100_CONFIGURATION_PCS_FX100_CFG(tgt),
                        VTSS_F_DEV_PCS_FX100_CONFIGURATION_PCS_FX100_CFG_PCS_ENA(0),
                        VTSS_M_DEV_PCS_FX100_CONFIGURATION_PCS_FX100_CFG_PCS_ENA);

        return;
    }

    case MAC_IF_100FX: {
        /* Speed setup and enable PCS clock */
        H2_WRITE_MASKED(VTSS_DEV_PORT_MODE_CLOCK_CFG(tgt),
                        VTSS_F_DEV_PORT_MODE_CLOCK_CFG_LINK_SPEED(2) /* 100 Mbps */,
                        VTSS_M_DEV_PORT_MODE_CLOCK_CFG_LINK_SPEED);
        h2_pcs1g_clock_set(chip_port, TRUE);

        /* Set MAC Mode Configuration */
        H2_WRITE_MASKED(VTSS_DEV_MAC_CFG_STATUS_MAC_MODE_CFG(tgt),
                        VTSS_F_DEV_MAC_CFG_STATUS_MAC_MODE_CFG_GIGA_MODE_ENA(0) |
                        VTSS_F_DEV_MAC_CFG_STATUS_MAC_MODE_CFG_FDX_ENA(1),
                        VTSS_M_DEV_MAC_CFG_STATUS_MAC_MODE_CFG_GIGA_MODE_ENA |
                        VTSS_M_DEV_MAC_CFG_STATUS_MAC_MODE_CFG_FDX_ENA);  // 10/100 & fdx

        /* Set PCS1G Auto-negotiation configuration: Software Resolve Abilities */
        H2_WRITE_MASKED(VTSS_DEV_PCS1G_CFG_STATUS_PCS1G_ANEG_CFG(tgt),
                        VTSS_F_DEV_PCS1G_CFG_STATUS_PCS1G_ANEG_CFG_SW_RESOLVE_ENA(0),
                        VTSS_M_DEV_PCS1G_CFG_STATUS_PCS1G_ANEG_CFG_SW_RESOLVE_ENA);

        /* Set Configuration bit groups for 100Base-FX PCS: Enable 100FX PCS */
        H2_WRITE_MASKED(VTSS_DEV_PCS_FX100_CONFIGURATION_PCS_FX100_CFG(tgt),
                        VTSS_F_DEV_PCS_FX100_CONFIGURATION_PCS_FX100_CFG_PCS_ENA(1),
                        VTSS_M_DEV_PCS_FX100_CONFIGURATION_PCS_FX100_CFG_PCS_ENA);

        return;
    }

    default:
#if defined(H2_PCS1G_DEBUG_ENABLE)
        print_str("%% Error: Wrong parameter when calling h2_pcs1g_setup(), chip_port=0x");
        print_hex_b(chip_port);
        print_str(", mode=0x");
        print_hex_b(if_type);
        print_cr_lf();
#endif /* H2_PCS1G_DEBUG_ENABLE */
        break;
    }
}

/* Get the PCS1G link status */
uchar h2_pcs1g_2_5g_link_status_get(vtss_cport_no_t chip_port)
{
    ulong tgt = VTSS_TO_DEV(chip_port);
    ulong reg_val;
    uchar link_mode = LINK_MODE_DOWN;

    /* Read PCS1G sticky register */
    H2_READ(VTSS_DEV_PCS1G_CFG_STATUS_PCS1G_STICKY(tgt), reg_val);
    if (VTSS_X_DEV_PCS1G_CFG_STATUS_PCS1G_STICKY_OUT_OF_SYNC_STICKY(reg_val)) {
        /* Clear sticky bit then re-enable PCS */
        H2_WRITE_MASKED(VTSS_DEV_PCS1G_CFG_STATUS_PCS1G_STICKY(tgt),
                        VTSS_X_DEV_PCS1G_CFG_STATUS_PCS1G_STICKY_OUT_OF_SYNC_STICKY(1),
                        VTSS_M_DEV_PCS1G_CFG_STATUS_PCS1G_STICKY_OUT_OF_SYNC_STICKY);
        H2_WRITE_MASKED(VTSS_DEV_PCS1G_CFG_STATUS_PCS1G_CFG(tgt),
                        VTSS_F_DEV_PCS1G_CFG_STATUS_PCS1G_CFG_PCS_ENA(0),
                        VTSS_M_DEV_PCS1G_CFG_STATUS_PCS1G_CFG_PCS_ENA);
        delay_1(5);
        H2_WRITE_MASKED(VTSS_DEV_PCS1G_CFG_STATUS_PCS1G_CFG(tgt),
                        VTSS_F_DEV_PCS1G_CFG_STATUS_PCS1G_CFG_PCS_ENA(1),
                        VTSS_M_DEV_PCS1G_CFG_STATUS_PCS1G_CFG_PCS_ENA);
    }

    H2_READ(VTSS_DEV_PCS1G_CFG_STATUS_PCS1G_STICKY(tgt), reg_val);
    if (VTSS_X_DEV_PCS1G_CFG_STATUS_PCS1G_STICKY_LINK_DOWN_STICKY(reg_val)) {
        /* The link has been down. Clear sticky bit by writing value 1 */
        H2_WRITE_MASKED(VTSS_DEV_PCS1G_CFG_STATUS_PCS1G_STICKY(tgt),
                        VTSS_F_DEV_PCS1G_CFG_STATUS_PCS1G_STICKY_LINK_DOWN_STICKY(1),
                        VTSS_M_DEV_PCS1G_CFG_STATUS_PCS1G_STICKY_LINK_DOWN_STICKY);
    }

    /* Read PCS1G link status register */
    H2_READ(VTSS_DEV_PCS1G_CFG_STATUS_PCS1G_LINK_STATUS(tgt), reg_val);
    if (VTSS_X_DEV_PCS1G_CFG_STATUS_PCS1G_LINK_STATUS_LINK_STATUS(reg_val)) {
        link_mode = LINK_MODE_FDX_2500;
    }

    return link_mode;
}

#endif // MAC_TO_MEDIA
