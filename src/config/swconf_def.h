//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT


/* ===========================================================================
 *
 * Normally, all features should be disabled by default.
 * Refer to the project configured file under directory src/config/proj_opt/
 * It lists the features which you want to enable, i.e. proj_opt_ocelot_develop.h
 *
 * ==========================================================================/
 

/****************************************************************************
 * Debug
 ****************************************************************************/
/* Enable debug in h2port.c */
//#define HWPORT_DEBUG_ENABLE

/* Enable debug in phymap.c */
// #define PHYMAP_DEBUG_ENABLE

/* Enable debug in phydrv.c */
// #define PHYDRV_DEBUG_ENABLE

/* Enable debug in phytsk.c */
//#define PHYTSK_DEBUG_ENABLE

/* Enable debug in ledtsk.c */
//#define LEDTSK_DEBUG_ENABLE

/* Enable debug in h2pcs1g.c */
//#define H2_PCS1G_DEBUG_ENABLE

/* Enable debug in h2sdcfg.c */
//#define H2_DEBUG_ENABLE

/* Enable debug in h2sdcfg.c */
//#define H2_SD6G_DEBUG_ENABLE

/* Enable debug in h2txtx.c */
// #define H2TXRX_DEBUG_ENABLE

/* Enable debug in h2mailc.c */
// #define H2_MAILC_DEBUG_ENABLE

/* Enable debug for buffer resource (watermark) */
// #define BUFFER_RESOURCE_DEBUG_ENABLE

/* Define NO_DEBUG_IF to disable the UIs debug message */
// TODO, cannot define it
// #define NO_DEBUG_IF

/* Define NDEBUG to disable asserts and trace */
// TODO, cannot undefine it
#define NDEBUG

// TODO, cannot define 1
#ifndef UNMANAGED_PORT_MAPPINGS
#define UNMANAGED_PORT_MAPPINGS                 1   /* Enable print APIs in print.c */
#endif

#ifndef UNMANAGED_LLDP_DEBUG_IF
#define UNMANAGED_LLDP_DEBUG_IF                 0
#endif

#ifndef UNMANAGED_EEE_DEBUG_IF
#define UNMANAGED_EEE_DEBUG_IF                  0
#endif

#ifndef UNMANAGED_FAN_DEBUG_IF
#define UNMANAGED_FAN_DEBUG_IF                  0
#endif


/****************************************************************************
 * MAC configuration
 ****************************************************************************/
/* System MAC configuration */
#ifndef TRANSIT_UNMANAGED_SYS_MAC_CONF
#define TRANSIT_UNMANAGED_SYS_MAC_CONF          0
#endif

/* MAC address entry operations: GET/GETNEXT */
#ifndef TRANSIT_UNMANAGED_MAC_OPER_GET
#define TRANSIT_UNMANAGED_MAC_OPER_GET          0
#endif

/* MAC address entry operations: ADD/DELETE */
#ifndef TRANSIT_UNMANAGED_MAC_OPER_SET
#define TRANSIT_UNMANAGED_MAC_OPER_SET          0
#endif


/****************************************************************************
 * Flow control default setting
 ****************************************************************************/
#define TRANSIT_FLOW_CTRL_DEFAULT               0 /* Disabled */


/****************************************************************************
 * LACP
 ****************************************************************************/
#define TRANSIT_LAG                             0
#define TRANSIT_LACP                            0

/****************************************************************************
 * Enable/Disable Loop Detection / Protection
 ****************************************************************************/
#ifndef TRANSIT_LOOPDETECT
#define TRANSIT_LOOPDETECT                      0
#endif


/****************************************************************************
 * ActiPHY
 ****************************************************************************/
#ifndef TRANSIT_ACTIPHY
#define TRANSIT_ACTIPHY                         0   /* Not implemented yet */
#endif

/****************************************************************************
 * TCAM
 ****************************************************************************/
#ifndef TRANSIT_TCAM_IS2
#define TRANSIT_TCAM_IS2                        0
#endif

#ifndef UNMANAGED_TCAM_DEBUG_IF 
#define UNMANAGED_TCAM_DEBUG_IF                 0 
#endif

/****************************************************************************
 * End to End transparent clock
 ****************************************************************************/
#define TRANSIT_E2ETC                           0

/****************************************************************************
 * MAILBOX communication - Configure the switch operation by the external CPU
 *                         interface through mailbox register
 *
 * The 32-bit register value is split into three parts:
 * <conf_oper>( 2-bit) - The operation between the embedded 8051 iCPU and external CPU
 * <conf_type>( 6-bit) - Configure type.
 * <conf_data>(24-bit) - Configure data, it depends on which configured type is defined.
 *
 * Only two features are supported now.
 *
 * 1. Set system MAC address.
 *    Possible value of <conf_type>( 6-bit) - H2MAILC_TYPE_SYS_MAC_SET_LOW(0), H2MAILC_TYPE_SYS_MAC_SET_HIGH(1)
 *    Format of <conf_data>(24-bit) - <sys_mac_higher_3_bytes>(24-bit) when <conf_type> = 0
 *                                  - <sys_mac_lower_3_bytes>(24-bit)  when <conf_type> = 1
 *    For local testing, type the following commands to set the system MAC address
      to 00-01-02-03-04-05
 *      1.1 w 0x71000000 0x0 0x20 0x80000102 --> Set the higher 3 bytes of the MAC address
 *      1.2 w 0x71000000 0x0 0x20 0x81030405 --> Set the lower 3 bytes of the MAC address
 *      1.3 w 0x71000000 0x0 0x20 0x82000000 --> Apply the new configuration
 *    After that, use command 'CONFIG' to check if the new configuration is applied.
 *
 * 2. Set LACP configuration.
 *    Possible value of <conf_type>( 6-bit) - H2MAILC_TYPE_LACP_ENABLE(3), H2MAILC_TYPE_LACP_DISABLE(4)
 *    Format of <conf_data>(24-bit) - <uport>(8-bit), <key>(16-bit)
 *    For local testing, type the following command to enable/disable LACP on uport 1.
 *      2.1 w 0x71000000 0x0 0x20 0x83010064 --> Enable with key 100(ox64) LACP on uport 1.
 *      2.2 w 0x71000000 0x0 0x20 0x84010064 --> Disable LACP on uport 1.
 *    After that, use command 'F' to check if the new configuration is applied.
 ****************************************************************************/
#ifndef TRANSIT_MAILBOX_COMM
#define TRANSIT_MAILBOX_COMM                    0
#endif


/****************************************************************************
 * LLDP - IEEE802.1AB
 ****************************************************************************/
#ifndef TRANSIT_LLDP
#define TRANSIT_LLDP                            0
#endif

#ifndef TRANSIT_LLDP_REDUCED
#define TRANSIT_LLDP_REDUCED                    0
#endif


/****************************************************************************
 * Software upgrade
 ****************************************************************************/
#ifndef TRANSIT_UNMANAGED_SWUP
#define TRANSIT_UNMANAGED_SWUP                  0   /* Not implemented yet */
#endif


/****************************************************************************
 * SPI Flash
 ****************************************************************************/
#ifndef TRANSIT_SPI_FLASH
#define TRANSIT_SPI_FLASH                       0   /* Not implemented yet */
#endif


/****************************************************************************
 * PCIE
 ****************************************************************************/
#ifndef ECPU_HANDSHAKE
#define ECPU_HANDSHAKE                          0 //handover switch control to eCPU
#endif


/****************************************************************************
 * CUSTOM CONFIG
 ****************************************************************************/
#ifndef CUSTOM_CONFIG
#define CUSTOM_CONFIG                           0
#endif


/****************************************************************************
 * FTIME
 ****************************************************************************/
/**
 * Set TRANSIT_FTIME to 1 to enable system uptime tracking and provide
 * an API ftime() to get the uptime of the system.
 *
 * @note ftime is a 4.2BSD, POSIX.1-2001 API.
 */
#ifndef TRANSIT_FTIME
#define TRANSIT_FTIME                           0   /* Not implemented yet */
#endif


/****************************************************************************
 * FAN S/W Control
 ****************************************************************************/
/* FAN specifications is defined in fan_custom_api.h */
#ifndef TRANSIT_FAN_CONTROL
#define TRANSIT_FAN_CONTROL                     0   /* Not implemented yet */
#endif


/****************************************************************************
 * Thermal Control - This is de-speced from VSC7420, VSC7421, VSC7422
 ****************************************************************************/
#ifndef TRANSIT_THERMAL
#define TRANSIT_THERMAL                         0   /* Not implemented yet */
#endif


/****************************************************************************
 * PoE
 ****************************************************************************/
#ifndef TRANSIT_POE
#define TRANSIT_POE                             0   /* Not implemented yet */
#endif

#ifndef TRANSIT_POE_LLDP
#define TRANSIT_POE_LLDP                        0   /* Not implemented yet */
#endif


/****************************************************************************
 * Allow/Disable BPDU pass through the switch.
 ****************************************************************************/
#ifndef TRANSIT_BPDU_PASS_THROUGH
#define TRANSIT_BPDU_PASS_THROUGH               0   /* Not implemented yet */
#endif


/****************************************************************************
 * realated compling flags for LACP/trunk driver. Consider to remove later. !!!
 ****************************************************************************/
/* Set if Static trunk should load balancing when RSTP enabled */
#ifndef TRANSIT_RSTP_TRUNK_COWORK
#define TRANSIT_RSTP_TRUNK_COWORK               0   /* Not implemented yet */
#endif


/****************************************************************************
 * IEEE 802.1w protocol
 ****************************************************************************/
#ifndef TRANSIT_RSTP
#define TRANSIT_RSTP                            0   /* Not implemented yet */
#endif


/****************************************************************************
 * DOT1X
 ****************************************************************************/
#ifndef TRANSIT_DOT1X
#define TRANSIT_DOT1X                           0   /* Not implemented yet */
#endif


/****************************************************************************
 * SNMP
 ****************************************************************************/
#ifndef TRANSIT_SNMP
#define TRANSIT_SNMP                            0   /* Not implemented yet */
#endif


/****************************************************************************
 * Enable the switch initial procedure based on verification team's source code
 ****************************************************************************/
#if defined(VTSS_ARCH_OCELOT)
// Execute the initial procedure that provided by verification team
// Undefined OCELOT_MAIN_ENABLE now since we done the task now.
// #define OCELOT_MAIN_ENABLE
#endif // VTSS_ARCH_OCELOT


/****************************************************************************
 *
 * Do the cross check last
 *
 ****************************************************************************/
// Dependence checking
// Mailbox communication
#if TRANSIT_MAILBOX_COMM
    #if TRANSIT_UNMANAGED_SYS_MAC_CONF == 0
    #error "Require TRANSIT_UNMANAGED_MAC_OPER_SET"
    #endif

    #if TRANSIT_UNMANAGED_MAC_OPER_SET == 0
    #error "Require TRANSIT_UNMANAGED_MAC_OPER_SET"
    #endif
#endif // TRANSIT_MAILBOX_COMM

