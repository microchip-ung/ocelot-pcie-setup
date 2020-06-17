//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT
#include <string.h>

#include "common.h"     /* Always include common.h at the first place of user-defined herder files */
#include "misc1.h"
#include "misc2.h"
#include "misc3.h"
#include "hwport.h"

#ifndef NO_DEBUG_IF
#ifndef BOOTLOADER
/* ************************************************************************ */
uchar ascii_to_hex_nib (uchar ch)
/* ------------------------------------------------------------------------ --
 * Purpose     : Convert an ASCII hex digit to a hex digit.
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    ch = conv_to_upper_case(ch);

    if (('0' <= ch) && (ch <= '9')) {
        return (ch - '0');
    } else if (('A' <= ch) && (ch <= 'F')) {
        return (ch - 'A' + 10);
    } else {
        return 0xff;
    }
}

/* ************************************************************************ */
uchar hex_to_ascii_nib (uchar nib)
/* ------------------------------------------------------------------------ --
 * Purpose     : Convert a hex nibble in binary (0-f) to ASCII.
 * Remarks     : nib holds nibble to convert (must be in range 0-f).
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    if (nib < 10) {
        return nib + '0';
    } else {
        return (nib - 10) + 'a';
    }
}

/* ************************************************************************ */
char conv_to_upper_case (char ch)
/* ------------------------------------------------------------------------ --
 * Purpose     : Convert a char to upper case.
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 ****************************************************************************/
{
    if (('a' <= ch) && (ch <= 'z')) {
        return (ch - 0x20);
    } else {
        return ch;
    }
}
#endif //BOOTLOADER
#endif
