//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT

#include "common.h"     /* Always include common.h at the first place of user-defined herder files */

#ifndef NO_DEBUG_IF

#include <string.h>
#include "misc1.h"
#include "txt.h"
#include "print.h"
#include "txt_moredef.h"


#if 0 // Uncalled function
char code txt_01 [] = "Invalid command\r\n";

#ifndef UNMANAGED_REDUCED_DEBUG_IF
char code txt_02 [] = "Chip ID: ";
char code txt_03 [] = "Port SMAC              MIIM PHY\r\n";

char code txt_05 [] = "Port ";
char code txt_06 [] = ", MIIM ";
char code txt_07 [] = ", PHY ";
#endif // UNMANAGED_REDUCED_DEBUG_IF

#endif // Uncalled function

#if LOOPBACK_TEST
char code txt_08 [] = "Internal loopback on PHYs:\r\n";
char code txt_09 [] = "External loopback on PHYs:\r\n";

char code txt_11 [] = "\r\n    Port  @10     @100    @1000";
char code txt_12 [] = "Ok      ";
char code txt_13 [] = "Error ";
char code txt_14 [] = "\r\nTest completed\r\n";
#endif // LOOPBACK_TEST

#endif // NO_DEBUG_IF


/*****************************************************************************
 *
 *
 * Interface functions
 *
 *
 *
 ****************************************************************************/
#if TRANSIT_UNMANAGED_SYS_MAC_CONF
uchar cmp_cmd_txt (cmd_txt_t cmd_txt_no, char xdata *s1)
{
    uchar count;
    uchar ch1;
    uchar ch2;
    char code *s2;
    uchar prev_ch;

    prev_ch = 0;
    count = 0;
    s2 = cmd_txt_tab[cmd_txt_no].str_ptr;
    for (;;) {
        ch2 = conv_to_upper_case(*s2++);
        if (ch2 == 0) {
            return count;
        }

        ch1 = conv_to_upper_case(*s1++);
        if (ch1 != ch2) {
            if (count >= cmd_txt_tab[cmd_txt_no].min_match) {
                if (prev_ch == ' ') {
                    count--;
                }
                return count;
            }
            else {
                return 0;
            }
        }
        else {
            prev_ch = ch1;
        }
       // Increment count and make sure that we don't run forever.
       if (count++ > 254) {
           return 0;
        }
    }
}
#endif // TRANSIT_UNMANAGED_SYS_MAC_CONF
