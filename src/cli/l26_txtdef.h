// This file was created by the txt2c.pl utility based on file l26_txtdef.txt
//


#ifndef L26_TXTDEF_H_INC
#define L26_TXTDEF_H_INC




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
    TXT_NO_WRONG_CHIP_ID,
    TXT_NO_TEMPERATURE,
    TXT_NO_COMPILE_DATE,
    END_STD_TXT,
} std_txt_t;




extern const struct {
    char *str_ptr;
} std_txt_tab [END_STD_TXT];


#endif  // L26_TXTDEF_H_INC

