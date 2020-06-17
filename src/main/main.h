//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT

#ifndef __MAIN_H__
#define __MAIN_H__
#include "vtss_api_base_regs.h"

/*
 * Power up error codes.
 */
#define POWER_UP_ERROR_FLASH_CHECKSUM 4
#define POWER_UP_ERROR_PHY            5
#define POWER_UP_ERROR_H2             6

/*
 * Run-time error codes.
 */
#define ERROR_RX_BUF_OVERRUN          1
#define ERROR_UART_FRAMING            3
#define ERROR_FATAL                   7

#define CSR_RD(reg, value) (*(value) = reg_rd(reg))
#define CSR_WR(reg, value, mask) reg_wrm(reg, value, mask)
#define DEV(i) (VTSS_TO_DEV_0 + (0x10000*(i)))

u32 reg_rd(u32 reg) ;
void reg_wr(u32 reg, u32 value) ;
void reg_wrm(u32 reg, u32 value, u32 mask) ;

#endif

/****************************************************************************/
/*                                                                          */
/*  End of file.                                                            */
/*                                                                          */
/****************************************************************************/
