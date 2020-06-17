//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT

#include "common.h"
#include "swconf.h"
#include "txt_moredef.h"


/* ************************************************************************ **
 *
 *
 * cmd texts
 *
 *
 *
 * ************************************************************************ */
#if TRANSIT_UNMANAGED_SYS_MAC_CONF
const char txt_CMD_TXT_NO_CONFIG [] = {"CONFIG"};
const char txt_CMD_TXT_NO_MAC [] = {"MAC"};
const char txt_CMD_TXT_NO_SAVE [] = {"SAVE"};
#endif // TRANSIT_UNMANAGED_SYS_MAC_CONF

const char txt_CMD_TXT_NO_END [] = {"END"};



const struct {
    char *str_ptr;
    uchar min_match;  /* Minimum number of characters that must be present */
} cmd_txt_tab [END_CMD_TXT] = {
#if TRANSIT_UNMANAGED_SYS_MAC_CONF
    txt_CMD_TXT_NO_CONFIG,                     6,
    txt_CMD_TXT_NO_MAC,                        3,
    txt_CMD_TXT_NO_SAVE,                       4,
#endif // TRANSIT_UNMANAGED_SYS_MAC_CONF
    txt_CMD_TXT_NO_END,                        3,
};



/* ************************************************************************ **
 *
 *
 * std texts
 *
 *
 *
 * ************************************************************************ */

const char txt_TXT_NO_CHIP_NAME [] = {"Ocelot"};


#if defined(OCELOT_F11)
const char txt_TXT_NO_SWITCH_DESCRIPTION [] = {" - 11 Port Gigabit Ethernet Switch"};
#elif defined(OCELOT_F10P)
const char txt_TXT_NO_SWITCH_DESCRIPTION [] = {" - 10 Port Gigabit Ethernet Switch"};
#elif defined(OCELOT_6P)
const char txt_TXT_NO_SWITCH_DESCRIPTION [] = {" - 6 Port Gigabit Ethernet Switch"};
#elif defined(OCELOT_F5)
const char txt_TXT_NO_SWITCH_DESCRIPTION [] = {" - 5 Port Gigabit Ethernet Switch"};
#elif defined(OCELOT_F4P)
const char txt_TXT_NO_SWITCH_DESCRIPTION [] = {" - 4 Port Gigabit Ethernet Switch"};
#else
const char txt_TXT_NO_SWITCH_DESCRIPTION [] = {" - Unknown switch description"};
#endif 


#if defined(OCELOT_F11)
const char txt_TXT_NO_SWITCH_NAME [] = {"VSC7412 11 Port Switch"};
#elif defined(OCELOT_F10P)
const char txt_TXT_NO_SWITCH_NAME [] = {"VSC7412 10 Port Switch"};
#elif defined(OCELOT_6P)
const char txt_TXT_NO_SWITCH_NAME [] = {"VSC7514 6 Port Switch"};
#elif defined(OCELOT_F5)
const char txt_TXT_NO_SWITCH_NAME [] = {"VSC7411 5 Port Switch"};
#elif defined(OCELOT_F4P)
const char txt_TXT_NO_SWITCH_NAME [] = {"VSC7411 4 Port Switch"};
#else
const char txt_TXT_NO_SWITCH_NAME [] = {"Unknown switch name"};
#endif 

#if TRANSIT_LLDP
// const char txt_TXT_NO_LLDP_OPTIONAL_TLVS [] = {"Optional TLVs"};
const char txt_TXT_NO_LLDP_REMOTEMIB_HDR [] = {"Port    Chassis ID                Port ID                System Name\r\n"};
const char txt_TXT_NO_LLDP_CHASSIS_ID [] = {"Chassis ID:"};
const char txt_TXT_NO_LLDP_CHASSIS_TYPE [] = {"Chassis Type:"};
const char txt_TXT_NO_LLDP_PORT_TYPE [] = {"Port Type:"};
const char txt_TXT_NO_LLDP_PORT_ID [] = {"Port ID"};
const char txt_TXT_NO_LLDP_SYSTEM_NAME [] = {"System Name:"};
const char txt_TXT_NO_LLDP_SYSTEM_DESCR [] = {"System Description:"};
const char txt_TXT_NO_LLDP_PORT_DESCR [] = {"Port Description:"};
const char txt_TXT_NO_LLDP_SYSTEM_CAPA [] = {"System Capabilities:"};
const char txt_TXT_NO_LLDP_MGMT_ADDR [] = {"Management Address:"};
// const char txt_TXT_NO_LLDP_STATHDR1 [] = {"         Tx           Recieved Frames                   TLVs"};
// const char txt_TXT_NO_LLDP_STATHDR2 [] = {"Port   Frames   Total   Errors   Discards   Discards   Unrecog.  Org.    Ageouts"};

#if UNMANAGED_EEE_DEBUG_IF
const char txt_TXT_NO_EEE_STAT [] = {"    Tx_tw   Rx_tw   Fb Rx_tw   Echo Tx_tw   Echo Rx_tw   Resolved Tx   Resolved Rx\r\n"};
#endif //UNMANAGED_EEE_DEBUG_IF

const char txt_TXT_NO_LLDP_NO_ENTRIES [] = {"No entries found"};
const char txt_TXT_NO_LLDP_LOCAL_PORT [] = {"Local port"};
#endif // TRANSIT_LLDP



const char txt_TXT_NO_WRONG_CHIP_ID [] = {"Wrong Chip ID"};
const char txt_TXT_NO_TEMPERATURE [] = {"Temperature"};
const char txt_TXT_NO_COMPILE_DATE [] = {"Compile Date: "};


const struct {
    char *str_ptr;
} std_txt_tab [END_STD_TXT] = {
#if TRANSIT_LLDP
    txt_TXT_NO_CHIP_NAME,
#if UNMANAGED_LLDP_DEBUG_IF
#if 0
    txt_TXT_NO_LLDP_OPTIONAL_TLVS,
#endif
    txt_TXT_NO_LLDP_REMOTEMIB_HDR,
    txt_TXT_NO_LLDP_CHASSIS_ID,
    txt_TXT_NO_LLDP_CHASSIS_TYPE,
    txt_TXT_NO_LLDP_PORT_TYPE,
    txt_TXT_NO_LLDP_PORT_ID,
    txt_TXT_NO_LLDP_SYSTEM_NAME,
    txt_TXT_NO_LLDP_SYSTEM_DESCR,
    txt_TXT_NO_LLDP_PORT_DESCR,
    txt_TXT_NO_LLDP_SYSTEM_CAPA,
    txt_TXT_NO_LLDP_MGMT_ADDR,
#if 0
    txt_TXT_NO_LLDP_STATHDR1,
    txt_TXT_NO_LLDP_STATHDR2,
#endif
#if UNMANAGED_EEE_DEBUG_IF
    txt_TXT_NO_EEE_STAT,
#endif
    txt_TXT_NO_LLDP_NO_ENTRIES,
    txt_TXT_NO_LLDP_LOCAL_PORT,
#endif
#endif /* TRANSIT_LLDP */

    txt_TXT_NO_WRONG_CHIP_ID,
    txt_TXT_NO_TEMPERATURE,
    txt_TXT_NO_COMPILE_DATE,
};
