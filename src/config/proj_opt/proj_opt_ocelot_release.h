//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT


/* Define the below to run with ANEG disabled and forced 1Gfdx speed for SGMII/SERDES interfaces
 * of type MAC_IF_SGMII or MAC_IF_SERDES_1G.
 * This will also make sure that SFP detection is disabled.
 */
#define SGMII_SERDES_FORCE_1G

/****************************************************************************
 * MAC configuration
 ****************************************************************************/
/* System MAC configuration */
#define TRANSIT_UNMANAGED_SYS_MAC_CONF          1

/* MAC address entry operations: GET/GETNEXT */
#define TRANSIT_UNMANAGED_MAC_OPER_GET          1

/* MAC address entry operations: ADD/DELETE */
#define TRANSIT_UNMANAGED_MAC_OPER_SET          1


/****************************************************************************
 * TCAM
 ****************************************************************************/
#define TRANSIT_TCAM_IS2                        0

