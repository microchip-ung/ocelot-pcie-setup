//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT

#ifndef __SWCONF_H__
#define __SWCONF_H__

#ifndef __INCLUDE_CONFIGS__
#error "swconf.h is for common.h only"
#endif

#if defined(PROJ_OPT)
#   if defined(OCELOT_6P)
#       include "proj_opt_ocelot_release.h"
#   endif /* defined(OCELOT_6P) */
#endif // PROJ_OPT

/* Default configuration */
#include "swconf_def.h"

#endif /* __SWCONF_H__ */
