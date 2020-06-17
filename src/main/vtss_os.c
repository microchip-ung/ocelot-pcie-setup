//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT

#include "common.h"     /* Always include common.h at the first place of user-defined herder files */
#include "vtss_common_os.h"
#include "sysutil.h"

#include "main.h"

#include "hwport.h"
#include "h2.h"
#include "print.h"
#include "timer.h"
#include "uartdrv.h"

vtss_common_trlevel_t vtss_os_trace_level = VTSS_COMMON_TRLVL_DEBUG;

#ifndef VTSS_COMMON_NDEBUG
VTSS_COMMON_DATA_ATTRIB char _common_file[80] = __FILE__;
ushort _common_line = 0;
ushort _common_retaddr = 0;
vtss_common_trlevel_t _common_lvl = VTSS_COMMON_TRLVL_NOISE;

static const char *basenm(const char *fname)
{
    const char *cp;

    cp = strrchr(fname, '\\');
    if (cp == NULL)
        cp = strrchr(fname, '/');
    return (cp == NULL) ? fname : cp + 1;
}

void vtss_os_trace(const char *fmt, ...)
{
    va_list ap;

    if (_common_lvl > vtss_os_trace_level)
        return;

    vtss_printf("%s(%u) %c: ", basenm(_common_file),
                (unsigned)_common_line,
                "0EWDN"[_common_lvl]);
    va_start(ap, fmt);
    vtss_vprintf(fmt, ap);
    va_end(ap);
    if (fmt[strlen(fmt) - 1] != '\n')
        print_cr_lf();
}

void vtss_os_assert(unsigned line_number)
{
    uchar ch;

    vtss_printf("\nAssert file %s line %u called from 0x%x failed.\nType c - continue, r - reboot h - hang: ",
                (const char *)basenm(_common_file), (unsigned)line_number,
                (unsigned)_common_retaddr);
    do {
        while (!uart_byte_ready())
            /* Wait for it */;
        ch = uart_get_byte();
        switch (ch) {
        case 'c' :
        case 'C' :
            vtss_printf("\n Continuing execution\n");
            return;
        case 'r' :
        case 'R' :
            sysutil_reboot();
            break;
        }
    } while (ch != 'h' && ch != 'H');
    vtss_printf("\n hanging.\n");
    sysutil_assert_event_set(SYS_ASSERT_EVENT_OS);
    sysutil_hang();
}

void vtss_common_dump_frame(const vtss_common_octet_t VTSS_COMMON_PTR_ATTRIB *frame, vtss_common_framelen_t len)
{
#define MBUF    ((const vtss_common_macheader_t VTSS_COMMON_PTR_ATTRIB *)frame)
    vtss_common_framelen_t i;

    vtss_printf("Frame len %u dst %s",
                (unsigned)len, vtss_common_str_macaddr(&MBUF->dst_mac));
    vtss_printf(" src %s type 0x%x",
                vtss_common_str_macaddr(&MBUF->src_mac), (unsigned)MBUF->eth_type);
    for (i = 0; i < len; i++) {
        if ((i & 0xF) == 0) {
            print_cr_lf();
            print_dec_16_right(i, 5);
            print_ch(':');
            print_spaces(1);
        }
        print_hex_b(frame[i]);
        print_spaces(1);
    }
    print_cr_lf();
#undef MBUF
}
#endif /* !VTSS_COMMON_NDEBUG */

#ifndef NDEBUG
const char *vtss_common_str_macaddr(const vtss_common_macaddr_t VTSS_COMMON_PTR_ATTRIB *mac)
{
    static char VTSS_COMMON_DATA_ATTRIB buf[24];

    uart_redirect(buf);

    uart_redirect(NULL);
    return buf;
}
#endif

/****************************************************************************/
/*                                                                          */
/*  End of file.                                                            */
/*                                                                          */
/****************************************************************************/
