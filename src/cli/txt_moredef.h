//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT

#ifndef TXT_MOREDEF_H
#define TXT_MOREDEF_H

/* ************************************************************************ **
 *
 *
 * cmd texts
 *
 *
 *
 * ************************************************************************ */
#if TRANSIT_UNMANAGED_SYS_MAC_CONF
extern const char txt_CMD_TXT_NO_CONFIG [];
extern const char txt_CMD_TXT_NO_MAC [];
extern const char txt_CMD_TXT_NO_SAVE [];
#endif
extern const char txt_CMD_TXT_NO_END [];


typedef enum {
#if TRANSIT_UNMANAGED_SYS_MAC_CONF
    CMD_TXT_NO_CONFIG,
    CMD_TXT_NO_MAC,
    CMD_TXT_NO_SAVE,
#endif
    CMD_TXT_NO_END,
    END_CMD_TXT,
} cmd_txt_t;




extern const struct {
    char *str_ptr;
    uchar min_match;  /* Minimum number of characters that must be present */
} cmd_txt_tab [END_CMD_TXT];



/* ************************************************************************ **
 *
 *
 * std texts
 *
 *
 *
 * ************************************************************************ */
extern const char txt_TXT_NO_WRONG_CHIP_ID [];
extern const char txt_TXT_NO_TEMPERATURE [];
extern const char txt_TXT_NO_COMPILE_DATE [];


typedef enum {
#if TRANSIT_LLDP
    TXT_NO_CHIP_NAME,
#if UNMANAGED_LLDP_DEBUG_IF
#if 0
    TXT_NO_LLDP_OPTIONAL_TLVS,
#endif
    TXT_NO_LLDP_REMOTEMIB_HDR,
    TXT_NO_LLDP_CHASSIS_ID,
    TXT_NO_LLDP_CHASSIS_TYPE,
    TXT_NO_LLDP_PORT_TYPE,
    TXT_NO_LLDP_PORT_ID,
    TXT_NO_LLDP_SYSTEM_NAME,
    TXT_NO_LLDP_SYSTEM_DESCR,
    TXT_NO_LLDP_PORT_DESCR,
    TXT_NO_LLDP_SYSTEM_CAPA,
    TXT_NO_LLDP_MGMT_ADDR,
#if 0
    TXT_NO_LLDP_STATHDR1,
    TXT_NO_LLDP_STATHDR2,
#endif
#if UNMANAGED_EEE_DEBUG_IF
    TXT_NO_EEE_STAT,
#endif
    TXT_NO_LLDP_NO_ENTRIES,
    TXT_NO_LLDP_LOCAL_PORT,
#endif
#endif /* TRANSIT_LLDP */
    TXT_NO_WRONG_CHIP_ID,
    TXT_NO_TEMPERATURE,
    TXT_NO_COMPILE_DATE,

    /* Add new string definition above this line
     *
     * And notice that each field should have the same order sequence in
     * the string arrary td_txt_tab[END_STD_TXT] (txt_moredef.c)
     */
    END_STD_TXT
} std_txt_t;




extern const struct {
    char *str_ptr;
} std_txt_tab [END_STD_TXT];


#endif  // TXT_MOREDEF_H
