// This file was created by the txt2c.pl utility based on file l26_txtdef.txt
//


#include "common.h"
#include "swconf.h"
#include "l26_txtdef.h"


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

#endif
const char txt_CMD_TXT_NO_END [] = {"END"};



const struct {
    char *str_ptr;
    uchar min_match;  /* Minimum number of characters that must be present */
} cmd_txt_tab [END_CMD_TXT] = {
#if TRANSIT_UNMANAGED_SYS_MAC_CONF
    txt_CMD_TXT_NO_CONFIG,                     6,
    txt_CMD_TXT_NO_MAC,                        3,
    txt_CMD_TXT_NO_SAVE,                       4,
#endif
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
#endif
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
