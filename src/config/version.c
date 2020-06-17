//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT

#include "version.h"
#include "code_revision.c"


/* 
 * Local Definition
 */
/* Software version suffix string */
#if defined(PROJ_OPT)
    #if (PROJ_OPT == 0)
        #define VER_SUFFIX_TXT      " - Engineer Developed"
    #elif (PROJ_OPT == 99999)
        #define VER_SUFFIX_TXT      "_PCIe_Setup 1.0.1"
    #elif (PROJ_OPT == 99998)
        #define VER_SUFFIX_TXT      "_Eval"
    #elif (PROJ_OPT == 99997)
        #define VER_SUFFIX_TXT      "_Abil_Bringup"
    #elif (PROJ_OPT == 99996)
        #define VER_SUFFIX_TXT      "_Abil"
    #endif
#else
    #define VER_SUFFIX_TXT          ""
#endif


/* 
 * Local Variables
 */
const char code *SW_COMPILE_DATE = __DATE__ " " __TIME__;

/* Notice that text 'TEST-N' should be excluded from the software version string */
const char code *SW_VERSION = "Ocelot" VER_SUFFIX_TXT
;
