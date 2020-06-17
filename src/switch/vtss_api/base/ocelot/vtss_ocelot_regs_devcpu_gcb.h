#ifndef _VTSS_OCELOT_REGS_DEVCPU_GCB_H_
#define _VTSS_OCELOT_REGS_DEVCPU_GCB_H_

//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT

#include "vtss_ocelot_regs_common.h"

/*********************************************************************** 
 *
 * Target: \a DEVCPU_GCB
 *
 * General configuration block.
 *
 ***********************************************************************/

/**
 * Register Group: \a DEVCPU_GCB:CHIP_REGS
 *
 * Not documented
 */


/** 
 * \brief Chip ID register
 *
 * \details
 * Register: \a DEVCPU_GCB:CHIP_REGS:CHIP_ID
 */
#define VTSS_DEVCPU_GCB_CHIP_REGS_CHIP_ID    VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x0)

/** 
 * \brief
 * Revision ID : Chip revision starting from 0.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_CHIP_REGS_CHIP_ID . REV_ID
 */
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_CHIP_ID_REV_ID(x)  VTSS_ENCODE_BITFIELD(x,28,4)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_CHIP_ID_REV_ID     VTSS_ENCODE_BITMASK(28,4)
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_CHIP_ID_REV_ID(x)  VTSS_EXTRACT_BITFIELD(x,28,4)

/** 
 * \brief
 * Part ID: Part ID for identification of Microchip Chips, contents of this
 * field is updated when reset is released.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_CHIP_REGS_CHIP_ID . PART_ID
 */
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_CHIP_ID_PART_ID(x)  VTSS_ENCODE_BITFIELD(x,12,16)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_CHIP_ID_PART_ID     VTSS_ENCODE_BITMASK(12,16)
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_CHIP_ID_PART_ID(x)  VTSS_EXTRACT_BITFIELD(x,12,16)

/** 
 * \brief
 * Manufacturer ID.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_CHIP_REGS_CHIP_ID . MFG_ID
 */
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_CHIP_ID_MFG_ID(x)  VTSS_ENCODE_BITFIELD(x,1,11)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_CHIP_ID_MFG_ID     VTSS_ENCODE_BITMASK(1,11)
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_CHIP_ID_MFG_ID(x)  VTSS_EXTRACT_BITFIELD(x,1,11)

/** 
 * \brief
 * Always 1.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_CHIP_REGS_CHIP_ID . ONE
 */
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_CHIP_ID_ONE(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_CHIP_ID_ONE  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_CHIP_ID_ONE(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


/** 
 * \brief General purpose register
 *
 * \details
 * Register: \a DEVCPU_GCB:CHIP_REGS:GPR
 */
#define VTSS_DEVCPU_GCB_CHIP_REGS_GPR        VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x1)

/** 
 * \brief
 * General purpose register for software development.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_CHIP_REGS_GPR . GPR
 */
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_GPR_GPR(x)  (x)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_GPR_GPR     0xffffffff
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_GPR_GPR(x)  (x)


/** 
 * \brief Reset control register
 *
 * \details
 * Register: \a DEVCPU_GCB:CHIP_REGS:SOFT_RST
 */
#define VTSS_DEVCPU_GCB_CHIP_REGS_SOFT_RST   VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x2)

/** 
 * \brief
 * Set this field to reset everything but the chip configuration. The reset
 * remains asserted until this field is cleared.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_CHIP_REGS_SOFT_RST . SOFT_NON_CFG_RST
 */
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_SOFT_RST_SOFT_NON_CFG_RST(x)  VTSS_ENCODE_BITFIELD(!!(x),2,1)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_SOFT_RST_SOFT_NON_CFG_RST  VTSS_BIT(2)
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_SOFT_RST_SOFT_NON_CFG_RST(x)  VTSS_EXTRACT_BITFIELD(x,2,1)

/** 
 * \brief
 * Set this field to reset the switch core (everything except the SERDES IO
 * and PLL blocks.) This field is automatically cleared by the reset.
 * Note: It is possible for the VCore to protect itself from this
 * soft-reset, for more info see ICPU_CFG::RESET.CORE_RST_PROTECT inside
 * the VCore register space.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_CHIP_REGS_SOFT_RST . SOFT_SWC_RST
 */
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_SOFT_RST_SOFT_SWC_RST(x)  VTSS_ENCODE_BITFIELD(!!(x),1,1)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_SOFT_RST_SOFT_SWC_RST  VTSS_BIT(1)
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_SOFT_RST_SOFT_SWC_RST(x)  VTSS_EXTRACT_BITFIELD(x,1,1)

/** 
 * \brief
 * Set this field to reset the whole chip. This field is automatically
 * cleared by the reset.
 * Note: It is possible for the VCore to protect itself from this
 * soft-reset, for more info see ICPU_CFG::RESET.CORE_RST_PROTECT inside
 * the VCore register space.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_CHIP_REGS_SOFT_RST . SOFT_CHIP_RST
 */
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_SOFT_RST_SOFT_CHIP_RST(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_SOFT_RST_SOFT_CHIP_RST  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_SOFT_RST_SOFT_CHIP_RST(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


/** 
 * \brief Various configrations
 *
 * \details
 * Register: \a DEVCPU_GCB:CHIP_REGS:HW_CFG
 */
#define VTSS_DEVCPU_GCB_CHIP_REGS_HW_CFG     VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x3)

/** 
 * \brief
 * Set to enable the DFT STAToutput on the GPIOs.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_CHIP_REGS_HW_CFG . DFT_STAT_ENA
 */
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_HW_CFG_DFT_STAT_ENA(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_HW_CFG_DFT_STAT_ENA  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_HW_CFG_DFT_STAT_ENA(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


/** 
 * \brief Various status indications
 *
 * \details
 * Register: \a DEVCPU_GCB:CHIP_REGS:HW_STAT
 */
#define VTSS_DEVCPU_GCB_CHIP_REGS_HW_STAT    VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x4)

/** 
 * \brief
 * PLL_CONF strapping value from GPIOs sampled after reset release.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_CHIP_REGS_HW_STAT . PLL0_CONF
 */
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_HW_STAT_PLL0_CONF(x)  VTSS_ENCODE_BITFIELD(x,1,3)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_HW_STAT_PLL0_CONF     VTSS_ENCODE_BITMASK(1,3)
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_HW_STAT_PLL0_CONF(x)  VTSS_EXTRACT_BITFIELD(x,1,3)

/** 
 * \brief
 * This field is set if a hardware fail has been detected in any of the
 * memories during startup-initialization of the chip. This field is valid
 * after release of reset.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_CHIP_REGS_HW_STAT . MEM_FAIL
 */
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_HW_STAT_MEM_FAIL(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_HW_STAT_MEM_FAIL  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_HW_STAT_MEM_FAIL(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


/** 
 * \brief Encoded features
 *
 * \details
 * Register: \a DEVCPU_GCB:CHIP_REGS:FEA_STAT
 */
#define VTSS_DEVCPU_GCB_CHIP_REGS_FEA_STAT   VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x5)

/** 
 * \brief
 * Efuse values. Some of these bits controls the hardware of the chip,
 * others are free for SW to use.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_CHIP_REGS_FEA_STAT . FEA_STAT
 */
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_FEA_STAT_FEA_STAT(x)  (x)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_FEA_STAT_FEA_STAT     0xffffffff
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_FEA_STAT_FEA_STAT(x)  (x)


/** 
 * \brief Disable of features
 *
 * \details
 * Register: \a DEVCPU_GCB:CHIP_REGS:FEA_DIS
 */
#define VTSS_DEVCPU_GCB_CHIP_REGS_FEA_DIS    VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x6)

/** 
 * \brief
 * Efuse force values. These bits are or'ed together with the corresponding
 * efuse fields - setting bits here corresponds to burning efuses and can
 * be used for validation purposes.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_CHIP_REGS_FEA_DIS . FEA_DIS
 */
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_FEA_DIS_FEA_DIS(x)  (x)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_FEA_DIS_FEA_DIS     0xffffffff
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_FEA_DIS_FEA_DIS(x)  (x)

/**
 * Register Group: \a DEVCPU_GCB:SW_REGS
 *
 * Registers for software/software interaction
 */


/** 
 * \brief Manually assert software interrupt
 *
 * \details
 * This register provides a simple interface for interrupting on either
 * software interrupt 0 or 1, without implementing semaphore support. Note:
 * setting this field causes a short pulse on the corresponding interrupt
 * connection, this kind of interrupt cannot be used in combination with
 * the ICPU_CFG::INTR_BYPASS feature.
 *
 * Register: \a DEVCPU_GCB:SW_REGS:SW_INTR
 */
#define VTSS_DEVCPU_GCB_SW_REGS_SW_INTR      VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x7)

/** 
 * \brief
 * Set this field to inject software interrupt 1. This field is
 * automatically cleared after interrupt has been generated.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_SW_REGS_SW_INTR . SW1_INTR
 */
#define  VTSS_F_DEVCPU_GCB_SW_REGS_SW_INTR_SW1_INTR(x)  VTSS_ENCODE_BITFIELD(!!(x),1,1)
#define  VTSS_M_DEVCPU_GCB_SW_REGS_SW_INTR_SW1_INTR  VTSS_BIT(1)
#define  VTSS_X_DEVCPU_GCB_SW_REGS_SW_INTR_SW1_INTR(x)  VTSS_EXTRACT_BITFIELD(x,1,1)

/** 
 * \brief
 * Set this field to assert software interrupt 0. This field is
 * automatically cleared after interrupt has been generated.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_SW_REGS_SW_INTR . SW0_INTR
 */
#define  VTSS_F_DEVCPU_GCB_SW_REGS_SW_INTR_SW0_INTR(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_GCB_SW_REGS_SW_INTR_SW0_INTR  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_GCB_SW_REGS_SW_INTR_SW0_INTR(x)  VTSS_EXTRACT_BITFIELD(x,0,1)

/**
 * Register Group: \a DEVCPU_GCB:VCORE_ACCESS
 *
 * Registers for accessing the VCore
 */


/** 
 * \brief Control register for VCore accesses
 *
 * \details
 * Register: \a DEVCPU_GCB:VCORE_ACCESS:VA_CTRL
 */
#define VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x8)

/** 
 * \brief
 * Controls the size of the access inside VCore domain. It is possible to
 * do 32-bit, 16-bit and 8-bit accesses. For 8bit and 16bit write-accesses
 * data must be aligned appropriately inside the 32bit write-data word
 * (i.e. for a byte-write to address 0x20001003 data has to be placed in
 * [31:24]). Likewise for 8bit and 16bit read operations, here data is
 * alligned accordingly to address.
 *
 * \details 
 * 0: 32bit
 * 1: Reserved, do not use
 * 2: 8bit
 * 3: 16bit
 *
 * Field: ::VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL . VA_SIZE
 */
#define  VTSS_F_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL_VA_SIZE(x)  VTSS_ENCODE_BITFIELD(x,4,2)
#define  VTSS_M_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL_VA_SIZE     VTSS_ENCODE_BITMASK(4,2)
#define  VTSS_X_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL_VA_SIZE(x)  VTSS_EXTRACT_BITFIELD(x,4,2)

/** 
 * \brief
 * If the VCore access logic detects an error this field is set based on
 * the nature of the error. This is a read-only field which is cleared by
 * the VCore access logic when a new access is (sucessfully) accepted.
 *
 * \details 
 * 0: No errors detected.
 * 1: SBA not ready when accessed.
 * 2: SBA reported error.
 * 3: DATA or ADDR written during active access.
 *
 * Field: ::VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL . VA_ERR
 */
#define  VTSS_F_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL_VA_ERR(x)  VTSS_ENCODE_BITFIELD(x,2,2)
#define  VTSS_M_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL_VA_ERR     VTSS_ENCODE_BITMASK(2,2)
#define  VTSS_X_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL_VA_ERR(x)  VTSS_EXTRACT_BITFIELD(x,2,2)

/** 
 * \brief
 * This field is set to the value of VA_CTRL.VA_BUSY whenever one of the
 * data registers VA_DATA, VA_DATA_INCR, or VA_DATA_INERT is read. By
 * examining this field it is possible to determine if VA_BUSY was set at
 * the time a read from one of these registers was performed.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL . VA_BUSY_RD
 */
#define  VTSS_F_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL_VA_BUSY_RD(x)  VTSS_ENCODE_BITFIELD(!!(x),1,1)
#define  VTSS_M_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL_VA_BUSY_RD  VTSS_BIT(1)
#define  VTSS_X_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL_VA_BUSY_RD(x)  VTSS_EXTRACT_BITFIELD(x,1,1)

/** 
 * \brief
 * This field is set by hardware when an access into VCore domain is
 * started, and cleared when the access is done.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL . VA_BUSY
 */
#define  VTSS_F_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL_VA_BUSY(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL_VA_BUSY  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL_VA_BUSY(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


/** 
 * \brief Address register for VCore accesses
 *
 * \details
 * Register: \a DEVCPU_GCB:VCORE_ACCESS:VA_ADDR
 */
#define VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_ADDR  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x9)

/** 
 * \brief
 * The address to access in the VCore domain, all addresses must be 32-bit
 * alligned (i.e. the two least significant bit must always be 0).
 * When accesses are initiated using the VA_DATA_INCR register, then this
 * field is autoincremented by 4 at the end of the transfer.
 * The memory region of the VCore that maps to switch-core registers may
 * not be accessed by using these registers.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_ADDR . VA_ADDR
 */
#define  VTSS_F_DEVCPU_GCB_VCORE_ACCESS_VA_ADDR_VA_ADDR(x)  (x)
#define  VTSS_M_DEVCPU_GCB_VCORE_ACCESS_VA_ADDR_VA_ADDR     0xffffffff
#define  VTSS_X_DEVCPU_GCB_VCORE_ACCESS_VA_ADDR_VA_ADDR(x)  (x)


/** 
 * \brief Data register for VCore accesses
 *
 * \details
 * The VA_DATA, VA_DATA_INCR, and VA_DATA_INERT registers are used for
 * indirect access into the VCore domain. The functionality of the
 * VA_DATA_INCR and VA_DATA_INERT registers are similar to this register -
 * but with minor exceptions. These exceptions are fleshed out in the
 * description of the respective registers.
 *
 * Register: \a DEVCPU_GCB:VCORE_ACCESS:VA_DATA
 */
#define VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_DATA  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0xa)

/** 
 * \brief
 * Reading or writing from/to this field initiates accesses into the VCore
 * domain. While an access is ongoing (VA_CTRL.VA_BUSY is set) this field
 * may not be written. It is possible to read this field while an access is
 * ongoing, but the data returned will be 0x80000000.
 * When writing to this field; a write into the VCore domain is initiated
 * to the address specified in the VA_ADDR register, with the data that was
 * written to this field. Only 32-bit writes are supported. This field may
 * not be written to until the VA_CTRL.VA_BUSY indicates that no accesses
 * is ongoing.
 * When reading from this field; a read from the VCore domain is initiated
 * from the address specified in the VA_ADDR register. Important: The data
 * that is returned from reading this field (and stating an access) is not
 * the result of the newly initiated read, instead the data from the last
 * access is returned. The result of the newly initiated read access will
 * be ready once the VA_CTRL.VA_BUSY field shows that the access is done.
 * Note: When the result of a read-access is read from this field (the
 * second read), a new access will automatically be intiated. This is
 * desirable when reading a series of addresses from VCore domain. If a new
 * access is not desirable, then the result should be read from the
 * VA_DATA_INERT register instead of this field!
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_DATA . VA_DATA
 */
#define  VTSS_F_DEVCPU_GCB_VCORE_ACCESS_VA_DATA_VA_DATA(x)  (x)
#define  VTSS_M_DEVCPU_GCB_VCORE_ACCESS_VA_DATA_VA_DATA     0xffffffff
#define  VTSS_X_DEVCPU_GCB_VCORE_ACCESS_VA_DATA_VA_DATA(x)  (x)


/** 
 * \brief Data register for VCore accesses (w. auto increment of address)
 *
 * \details
 * Register: \a DEVCPU_GCB:VCORE_ACCESS:VA_DATA_INCR
 */
#define VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_DATA_INCR  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0xb)

/** 
 * \brief
 * This field behaves in the same way as VA_DATA. Except when an access is
 * initiated by using this field (either read or write); the address
 * register (VA_ADDR) is automatically incremented by 4 at the end of the
 * access, i.e. when VA_CTRL.VA_BUSY is deasserted.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_DATA_INCR . VA_DATA_INCR
 */
#define  VTSS_F_DEVCPU_GCB_VCORE_ACCESS_VA_DATA_INCR_VA_DATA_INCR(x)  (x)
#define  VTSS_M_DEVCPU_GCB_VCORE_ACCESS_VA_DATA_INCR_VA_DATA_INCR     0xffffffff
#define  VTSS_X_DEVCPU_GCB_VCORE_ACCESS_VA_DATA_INCR_VA_DATA_INCR(x)  (x)


/** 
 * \brief Data register for VCore accesses (will not initiate access)
 *
 * \details
 * Register: \a DEVCPU_GCB:VCORE_ACCESS:VA_DATA_INERT
 */
#define VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_DATA_INERT  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0xc)

/** 
 * \brief
 * This field behaves in the same way as VA_DATA. Except accesses (read or
 * write) does not initiate VCore accesses. Writing to this register just
 * overwrites the value currently held by all of the data registers
 * (VA_DATA, VA_DATA_INCR, and VA_DATA_INERT).
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_DATA_INERT . VA_DATA_INERT
 */
#define  VTSS_F_DEVCPU_GCB_VCORE_ACCESS_VA_DATA_INERT_VA_DATA_INERT(x)  (x)
#define  VTSS_M_DEVCPU_GCB_VCORE_ACCESS_VA_DATA_INERT_VA_DATA_INERT     0xffffffff
#define  VTSS_X_DEVCPU_GCB_VCORE_ACCESS_VA_DATA_INERT_VA_DATA_INERT(x)  (x)

/**
 * Register Group: \a DEVCPU_GCB:GPIO
 *
 * Not documented
 */


/** 
 * \brief GPIO output set
 *
 * \details
 * Register: \a DEVCPU_GCB:GPIO:GPIO_OUT_SET
 */
#define VTSS_DEVCPU_GCB_GPIO_GPIO_OUT_SET    VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0xd)

/** 
 * \brief
 * Setting a bit in this field will immediately set the corresponding bit
 * in GPIO_OUT.G_OUT. Reading this register always return 0.
 *
 * \details 
 * '0': No change
 * '1': Corresponding bit in GPIO_OUT.G_OUT is set.
 *
 * Field: ::VTSS_DEVCPU_GCB_GPIO_GPIO_OUT_SET . G_OUT_SET
 */
#define  VTSS_F_DEVCPU_GCB_GPIO_GPIO_OUT_SET_G_OUT_SET(x)  VTSS_ENCODE_BITFIELD(x,0,22)
#define  VTSS_M_DEVCPU_GCB_GPIO_GPIO_OUT_SET_G_OUT_SET     VTSS_ENCODE_BITMASK(0,22)
#define  VTSS_X_DEVCPU_GCB_GPIO_GPIO_OUT_SET_G_OUT_SET(x)  VTSS_EXTRACT_BITFIELD(x,0,22)


/** 
 * \brief GPIO output clear
 *
 * \details
 * Register: \a DEVCPU_GCB:GPIO:GPIO_OUT_CLR
 */
#define VTSS_DEVCPU_GCB_GPIO_GPIO_OUT_CLR    VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0xe)

/** 
 * \brief
 * Setting a bit in this field will immediately clear the corresponding bit
 * in GPIO_OUT.G_OUT. Reading this register always return 0.
 *
 * \details 
 * '0': No change
 * '1': Corresponding bit in GPIO_OUT.G_OUT is cleared.
 *
 * Field: ::VTSS_DEVCPU_GCB_GPIO_GPIO_OUT_CLR . G_OUT_CLR
 */
#define  VTSS_F_DEVCPU_GCB_GPIO_GPIO_OUT_CLR_G_OUT_CLR(x)  VTSS_ENCODE_BITFIELD(x,0,22)
#define  VTSS_M_DEVCPU_GCB_GPIO_GPIO_OUT_CLR_G_OUT_CLR     VTSS_ENCODE_BITMASK(0,22)
#define  VTSS_X_DEVCPU_GCB_GPIO_GPIO_OUT_CLR_G_OUT_CLR(x)  VTSS_EXTRACT_BITFIELD(x,0,22)


/** 
 * \brief GPIO output
 *
 * \details
 * In a multi-threaded software environment using the registers
 * GPIO_OUT_SET and GPIO_OUT_CLR for modifying GPIO values removes the need
 * for software-locked access.
 *
 * Register: \a DEVCPU_GCB:GPIO:GPIO_OUT
 */
#define VTSS_DEVCPU_GCB_GPIO_GPIO_OUT        VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0xf)

/** 
 * \brief
 * Controls the value on the GPIO pins enabled for output (via the GPIO_OE
 * register). This field can be modified directly or by using the
 * GPIO_O_SET and GPIO_O_CLR registers.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_GPIO_GPIO_OUT . G_OUT
 */
#define  VTSS_F_DEVCPU_GCB_GPIO_GPIO_OUT_G_OUT(x)  VTSS_ENCODE_BITFIELD(x,0,22)
#define  VTSS_M_DEVCPU_GCB_GPIO_GPIO_OUT_G_OUT     VTSS_ENCODE_BITMASK(0,22)
#define  VTSS_X_DEVCPU_GCB_GPIO_GPIO_OUT_G_OUT(x)  VTSS_EXTRACT_BITFIELD(x,0,22)


/** 
 * \brief GPIO input
 *
 * \details
 * Register: \a DEVCPU_GCB:GPIO:GPIO_IN
 */
#define VTSS_DEVCPU_GCB_GPIO_GPIO_IN         VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x10)

/** 
 * \brief
 * GPIO input register. Reflects the current state of the corresponding
 * GPIO pins.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_GPIO_GPIO_IN . G_IN
 */
#define  VTSS_F_DEVCPU_GCB_GPIO_GPIO_IN_G_IN(x)  VTSS_ENCODE_BITFIELD(x,0,22)
#define  VTSS_M_DEVCPU_GCB_GPIO_GPIO_IN_G_IN     VTSS_ENCODE_BITMASK(0,22)
#define  VTSS_X_DEVCPU_GCB_GPIO_GPIO_IN_G_IN(x)  VTSS_EXTRACT_BITFIELD(x,0,22)


/** 
 * \brief GPIO pin direction
 *
 * \details
 * Register: \a DEVCPU_GCB:GPIO:GPIO_OE
 */
#define VTSS_DEVCPU_GCB_GPIO_GPIO_OE         VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x11)

/** 
 * \brief
 * Configures the direction of the GPIO pins.
 *
 * \details 
 * '0': Input
 * '1': Output
 *
 * Field: ::VTSS_DEVCPU_GCB_GPIO_GPIO_OE . G_OE
 */
#define  VTSS_F_DEVCPU_GCB_GPIO_GPIO_OE_G_OE(x)  VTSS_ENCODE_BITFIELD(x,0,22)
#define  VTSS_M_DEVCPU_GCB_GPIO_GPIO_OE_G_OE     VTSS_ENCODE_BITMASK(0,22)
#define  VTSS_X_DEVCPU_GCB_GPIO_GPIO_OE_G_OE(x)  VTSS_EXTRACT_BITFIELD(x,0,22)


/** 
 * \brief GPIO interrupt
 *
 * \details
 * Register: \a DEVCPU_GCB:GPIO:GPIO_INTR
 */
#define VTSS_DEVCPU_GCB_GPIO_GPIO_INTR       VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x12)

/** 
 * \brief
 * Indicates whether a GPIO input has changed since last clear.
 *
 * \details 
 * '0': No change
 * '1': GPIO has changed
 *
 * Field: ::VTSS_DEVCPU_GCB_GPIO_GPIO_INTR . G_INTR
 */
#define  VTSS_F_DEVCPU_GCB_GPIO_GPIO_INTR_G_INTR(x)  VTSS_ENCODE_BITFIELD(x,0,22)
#define  VTSS_M_DEVCPU_GCB_GPIO_GPIO_INTR_G_INTR     VTSS_ENCODE_BITMASK(0,22)
#define  VTSS_X_DEVCPU_GCB_GPIO_GPIO_INTR_G_INTR(x)  VTSS_EXTRACT_BITFIELD(x,0,22)


/** 
 * \brief GPIO interrupt enable
 *
 * \details
 * Register: \a DEVCPU_GCB:GPIO:GPIO_INTR_ENA
 */
#define VTSS_DEVCPU_GCB_GPIO_GPIO_INTR_ENA   VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x13)

/** 
 * \brief
 * Enables individual GPIO pins for interrupt.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_GPIO_GPIO_INTR_ENA . G_INTR_ENA
 */
#define  VTSS_F_DEVCPU_GCB_GPIO_GPIO_INTR_ENA_G_INTR_ENA(x)  VTSS_ENCODE_BITFIELD(x,0,22)
#define  VTSS_M_DEVCPU_GCB_GPIO_GPIO_INTR_ENA_G_INTR_ENA     VTSS_ENCODE_BITMASK(0,22)
#define  VTSS_X_DEVCPU_GCB_GPIO_GPIO_INTR_ENA_G_INTR_ENA(x)  VTSS_EXTRACT_BITFIELD(x,0,22)


/** 
 * \brief GPIO interrupt identity
 *
 * \details
 * Register: \a DEVCPU_GCB:GPIO:GPIO_INTR_IDENT
 */
#define VTSS_DEVCPU_GCB_GPIO_GPIO_INTR_IDENT  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x14)

/** 
 * \brief
 * Shows which GPIO sources that are currently interrupting. This field is
 * the result of an AND-operation between the GPIO_INTR and the
 * GPIO_INTR_ENA registers.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_GPIO_GPIO_INTR_IDENT . G_INTR_IDENT
 */
#define  VTSS_F_DEVCPU_GCB_GPIO_GPIO_INTR_IDENT_G_INTR_IDENT(x)  VTSS_ENCODE_BITFIELD(x,0,22)
#define  VTSS_M_DEVCPU_GCB_GPIO_GPIO_INTR_IDENT_G_INTR_IDENT     VTSS_ENCODE_BITMASK(0,22)
#define  VTSS_X_DEVCPU_GCB_GPIO_GPIO_INTR_IDENT_G_INTR_IDENT(x)  VTSS_EXTRACT_BITFIELD(x,0,22)


/** 
 * \brief GPIO alternate functions
 *
 * \details
 * Register: \a DEVCPU_GCB:GPIO:GPIO_ALT
 *
 * @param ri Register: GPIO_ALT (??), 0-1
 */
#define VTSS_DEVCPU_GCB_GPIO_GPIO_ALT(ri)    VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x15 + (ri))

/** 
 * \brief
 * Configures alternate functions for individual GPIOs. See datasheet for
 * information on possible alternate functions.
 * The LSB of the GPIO encoding is placed in replication 0, MSB is placed
 * in replication 1. For example; to encode Alternate mode 2 for GPIO[n]
 * write DEVCPU_GCB::GPIO_ALT[0][n] = 0, and DEVCPU_GCB::GPIO_ALT[1][n] =
 * 1.
 * Note: This register is only reset by the device's reset input, i.e. it
 * is not affected by soft reset!
 *
 * \details 
 * 00: GPIO mode
 * 01: Alternate mode 1
 * 10: Alternate mode 2
 * 11: Alternate mode 3
 *
 * Field: ::VTSS_DEVCPU_GCB_GPIO_GPIO_ALT . G_ALT
 */
#define  VTSS_F_DEVCPU_GCB_GPIO_GPIO_ALT_G_ALT(x)  VTSS_ENCODE_BITFIELD(x,0,22)
#define  VTSS_M_DEVCPU_GCB_GPIO_GPIO_ALT_G_ALT     VTSS_ENCODE_BITMASK(0,22)
#define  VTSS_X_DEVCPU_GCB_GPIO_GPIO_ALT_G_ALT(x)  VTSS_EXTRACT_BITFIELD(x,0,22)


/** 
 * \brief GPIO Signal Detect Mapping
 *
 * \details
 * Register: \a DEVCPU_GCB:GPIO:GPIO_SD_MAP
 *
 * @param ri Register: GPIO_SD_MAP (??), 0-15
 */
#define VTSS_DEVCPU_GCB_GPIO_GPIO_SD_MAP(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x17 + (ri))

/** 
 * \brief
 * Set to map a specific GPIO mapped signal detect input to specific
 * front-port index. There is one replication for each GPIO mapped signal
 * detect input. If multiple signal detects are enabled and map to same
 * front-port index, then the higher replication index will take priority.
 * For example to map 3'rd signal detect input asif it was provided by 2'nd
 * SERDES; set DEVCPU_GCB::GPIO_SD_MAP[2].G_SD_MAP = 1 and enable SD2 via
 * DEVCPU_GCB::GPIO_ALT registers.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_GPIO_GPIO_SD_MAP . G_SD_MAP
 */
#define  VTSS_F_DEVCPU_GCB_GPIO_GPIO_SD_MAP_G_SD_MAP(x)  VTSS_ENCODE_BITFIELD(x,0,6)
#define  VTSS_M_DEVCPU_GCB_GPIO_GPIO_SD_MAP_G_SD_MAP     VTSS_ENCODE_BITMASK(0,6)
#define  VTSS_X_DEVCPU_GCB_GPIO_GPIO_SD_MAP_G_SD_MAP(x)  VTSS_EXTRACT_BITFIELD(x,0,6)

/**
 * Register Group: \a DEVCPU_GCB:MIIM
 *
 * Not documented
 */


/** 
 * \brief MIIM Status
 *
 * \details
 * Register: \a DEVCPU_GCB:MIIM:MII_STATUS
 *
 * @param gi Replicator: x_FFL_DEVCPU_MIIM_CNT (??), 0-1
 */
#define VTSS_DEVCPU_GCB_MIIM_MII_STATUS(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x27,gi,9,0,0)

/** 
 * \brief
 * Signals if all PHYs have been scanned ( with auto scan ) at least once.
 *
 * \details 
 * 0 : Auto scan has not scanned all PHYs.
 * 1 : Auto scan has scanned all PHY at least once.
 *
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_STATUS . MIIM_SCAN_COMPLETE
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_SCAN_COMPLETE(x)  VTSS_ENCODE_BITFIELD(!!(x),4,1)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_SCAN_COMPLETE  VTSS_BIT(4)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_SCAN_COMPLETE(x)  VTSS_EXTRACT_BITFIELD(x,4,1)

/** 
 * \brief
 * Indicates the current state of the MIIM controller. When read operations
 * are done (no longer busy), then read data is available via the
 * DEVCPU_GCB::MII_DATA register.
 *
 * \details 
 * 0: MIIM controller is in idle state
 * 1: MIIM controller is busy performing MIIM cmd (Either read or read
 * cmd).
 *
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_STATUS . MIIM_STAT_BUSY
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_STAT_BUSY(x)  VTSS_ENCODE_BITFIELD(!!(x),3,1)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_STAT_BUSY  VTSS_BIT(3)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_STAT_BUSY(x)  VTSS_EXTRACT_BITFIELD(x,3,1)

/** 
 * \brief
 * The MIIM controller has a CMD fifo of depth one. When this field is 0,
 * then it is safe to write another MIIM command to the MIIM controller.
 *
 * \details 
 * 0 : Read or write not pending
 * 1 : Read or write pending.
 *
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_STATUS . MIIM_STAT_OPR_PEND
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_STAT_OPR_PEND(x)  VTSS_ENCODE_BITFIELD(!!(x),2,1)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_STAT_OPR_PEND  VTSS_BIT(2)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_STAT_OPR_PEND(x)  VTSS_EXTRACT_BITFIELD(x,2,1)

/** 
 * \brief
 * Indicates whether a read operation via the MIIM interface is in progress
 * or not.
 *
 * \details 
 * 0 : Read not in progress
 * 1 : Read in progress.
 *
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_STATUS . MIIM_STAT_PENDING_RD
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_STAT_PENDING_RD(x)  VTSS_ENCODE_BITFIELD(!!(x),1,1)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_STAT_PENDING_RD  VTSS_BIT(1)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_STAT_PENDING_RD(x)  VTSS_EXTRACT_BITFIELD(x,1,1)

/** 
 * \brief
 * Indicates whether a write operation via the MIIM interface is in
 * progress or not.
 *
 * \details 
 * 0 : Write not in progress
 * 1 : Write in progress.
 *
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_STATUS . MIIM_STAT_PENDING_WR
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_STAT_PENDING_WR(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_STAT_PENDING_WR  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_STAT_PENDING_WR(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


/** 
 * \brief MIIM Configuration
 *
 * \details
 * Register: \a DEVCPU_GCB:MIIM:MII_CFG_7226
 *
 * @param gi Replicator: x_FFL_DEVCPU_MIIM_CNT (??), 0-1
 */
#define VTSS_DEVCPU_GCB_MIIM_MII_CFG_7226(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x27,gi,9,0,1)

/** 
 * \brief
 * Use of XAUI/XGMII translator device.
 *
 * \details 
 * 0 : Disable
 * 1 : Enable.
 *
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_CFG_7226 . MIIM_7226_CFG_FIELD
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CFG_7226_MIIM_7226_CFG_FIELD(x)  VTSS_ENCODE_BITFIELD(!!(x),9,1)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CFG_7226_MIIM_7226_CFG_FIELD  VTSS_BIT(9)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CFG_7226_MIIM_7226_CFG_FIELD(x)  VTSS_EXTRACT_BITFIELD(x,9,1)


/** 
 * \brief MIIM Command
 *
 * \details
 * Register: \a DEVCPU_GCB:MIIM:MII_CMD
 *
 * @param gi Replicator: x_FFL_DEVCPU_MIIM_CNT (??), 0-1
 */
#define VTSS_DEVCPU_GCB_MIIM_MII_CMD(gi)     VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x27,gi,9,0,2)

/** 
 * \brief
 * Must be set for starting a new PHY access. This bit is automatically
 * cleared.
 *
 * \details 
 * 0 : Write to this register is ignored.
 * 1 : Write to this register is processed.
 *
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_CMD . MIIM_CMD_VLD
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_VLD(x)  VTSS_ENCODE_BITFIELD(!!(x),31,1)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_VLD  VTSS_BIT(31)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_VLD(x)  VTSS_EXTRACT_BITFIELD(x,31,1)

/** 
 * \brief
 * Indicates the addressed PHY number.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_CMD . MIIM_CMD_PHYAD
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_PHYAD(x)  VTSS_ENCODE_BITFIELD(x,25,5)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_PHYAD     VTSS_ENCODE_BITMASK(25,5)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_PHYAD(x)  VTSS_EXTRACT_BITFIELD(x,25,5)

/** 
 * \brief
 * Indicates the addressed of the register within the PHY that shall be
 * accessed.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_CMD . MIIM_CMD_REGAD
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_REGAD(x)  VTSS_ENCODE_BITFIELD(x,20,5)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_REGAD     VTSS_ENCODE_BITMASK(20,5)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_REGAD(x)  VTSS_EXTRACT_BITFIELD(x,20,5)

/** 
 * \brief
 * Data to be written in the PHY register.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_CMD . MIIM_CMD_WRDATA
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_WRDATA(x)  VTSS_ENCODE_BITFIELD(x,4,16)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_WRDATA     VTSS_ENCODE_BITMASK(4,16)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_WRDATA(x)  VTSS_EXTRACT_BITFIELD(x,4,16)

/** 
 * \brief
 * Select if scanning of the PHY shall be done once, or scanning should be
 * done continuously.
 *
 * \details 
 * 0 : Do continuously PHY scanning 
 * 1 : Stop once all PHY have been scanned.
 *
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_CMD . MIIM_CMD_SINGLE_SCAN
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_SINGLE_SCAN(x)  VTSS_ENCODE_BITFIELD(!!(x),3,1)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_SINGLE_SCAN  VTSS_BIT(3)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_SINGLE_SCAN(x)  VTSS_EXTRACT_BITFIELD(x,3,1)

/** 
 * \brief
 * Indicates type of operation.
 *
 * \details 
 * Clause 22:
 * 
 * 01 : Write
 * 10 : Read
 * 
 * Clause 45:
 * 
 * 00 : Address
 * 01 : Write
 * 10 : Read inc.
 * 11 : Read.
 *
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_CMD . MIIM_CMD_OPR_FIELD
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_OPR_FIELD(x)  VTSS_ENCODE_BITFIELD(x,1,2)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_OPR_FIELD     VTSS_ENCODE_BITMASK(1,2)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_OPR_FIELD(x)  VTSS_EXTRACT_BITFIELD(x,1,2)

/** 
 * \brief
 * Indicates whether automatic scanning of PHY registers is enabled. When
 * enabled, the PHY-number for each automatic read is continuously
 * round-robined from PHY_ADDR_LOW through PHY_ADDR_HIGH. This function is
 * started upon a read operation (ACCESS_TYPE).
 * Scan MUST be disabled when doing any configuration of the MIIM
 * controller.
 *
 * \details 
 * 0 : Disabled
 * 1 : Enabled.
 *
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_CMD . MIIM_CMD_SCAN
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_SCAN(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_SCAN  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_SCAN(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


/** 
 * \brief MIIM Reply Data
 *
 * \details
 * Register: \a DEVCPU_GCB:MIIM:MII_DATA
 *
 * @param gi Replicator: x_FFL_DEVCPU_MIIM_CNT (??), 0-1
 */
#define VTSS_DEVCPU_GCB_MIIM_MII_DATA(gi)    VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x27,gi,9,0,3)

/** 
 * \brief
 * Indicates whether a read operation failed or succeeded.
 *
 * \details 
 * 00 : OK
 * 11 : Error
 *
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_DATA . MIIM_DATA_SUCCESS
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_DATA_MIIM_DATA_SUCCESS(x)  VTSS_ENCODE_BITFIELD(x,16,2)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_DATA_MIIM_DATA_SUCCESS     VTSS_ENCODE_BITMASK(16,2)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_DATA_MIIM_DATA_SUCCESS(x)  VTSS_EXTRACT_BITFIELD(x,16,2)

/** 
 * \brief
 * Data read from PHY register.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_DATA . MIIM_DATA_RDDATA
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_DATA_MIIM_DATA_RDDATA(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_DATA_MIIM_DATA_RDDATA     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_DATA_MIIM_DATA_RDDATA(x)  VTSS_EXTRACT_BITFIELD(x,0,16)


/** 
 * \brief MIIM Configuration
 *
 * \details
 * Register: \a DEVCPU_GCB:MIIM:MII_CFG
 *
 * @param gi Replicator: x_FFL_DEVCPU_MIIM_CNT (??), 0-1
 */
#define VTSS_DEVCPU_GCB_MIIM_MII_CFG(gi)     VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x27,gi,9,0,4)

/** 
 * \brief
 * Option to disable deadlock fix if it causes any troubles.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_CFG . DEADLOCK_FIX_DIS
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CFG_DEADLOCK_FIX_DIS(x)  VTSS_ENCODE_BITFIELD(!!(x),11,1)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CFG_DEADLOCK_FIX_DIS  VTSS_BIT(11)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CFG_DEADLOCK_FIX_DIS(x)  VTSS_EXTRACT_BITFIELD(x,11,1)

/** 
 * \brief
 * The ST (start-of-frame) field of the MIIM frame format adopts the value
 * of this field. This must be configured for either clause 22 or 45 MIIM
 * operation.
 *
 * \details 
 * "01": Clause 22
 * "00": Clause 45
 * Other values are reserved.
 *
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_CFG . MIIM_ST_CFG_FIELD
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CFG_MIIM_ST_CFG_FIELD(x)  VTSS_ENCODE_BITFIELD(x,9,2)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CFG_MIIM_ST_CFG_FIELD     VTSS_ENCODE_BITMASK(9,2)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CFG_MIIM_ST_CFG_FIELD(x)  VTSS_EXTRACT_BITFIELD(x,9,2)

/** 
 * \brief
 * Selects the interpretation of the BUSY_OR_IN_PROGRESS field in
 * MII_STATUS.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_CFG . MIIM_CFG_DBG
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CFG_MIIM_CFG_DBG(x)  VTSS_ENCODE_BITFIELD(!!(x),8,1)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CFG_MIIM_CFG_DBG  VTSS_BIT(8)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CFG_MIIM_CFG_DBG(x)  VTSS_EXTRACT_BITFIELD(x,8,1)

/** 
 * \brief
 * Configures the MIIM clock frequency. This is computed as
 * system_clk/(2*(1+X)), where X is the value written to this register.
 * Note : Setting X to 0 is invalid and will result in the same frequency
 * as setting X to 1.
 *
 * \details 
 * Values less than 4 are reserved and must not be used.
 *
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_CFG . MIIM_CFG_PRESCALE
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CFG_MIIM_CFG_PRESCALE(x)  VTSS_ENCODE_BITFIELD(x,0,8)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CFG_MIIM_CFG_PRESCALE     VTSS_ENCODE_BITMASK(0,8)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CFG_MIIM_CFG_PRESCALE(x)  VTSS_EXTRACT_BITFIELD(x,0,8)


/** 
 * \brief MIIM Scan 0
 *
 * \details
 * Register: \a DEVCPU_GCB:MIIM:MII_SCAN_0
 *
 * @param gi Replicator: x_FFL_DEVCPU_MIIM_CNT (??), 0-1
 */
#define VTSS_DEVCPU_GCB_MIIM_MII_SCAN_0(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x27,gi,9,0,5)

/** 
 * \brief
 * Indicates the high PHY number to scan during automatic scanning.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_SCAN_0 . MIIM_SCAN_PHYADHI
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_SCAN_0_MIIM_SCAN_PHYADHI(x)  VTSS_ENCODE_BITFIELD(x,5,5)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_SCAN_0_MIIM_SCAN_PHYADHI     VTSS_ENCODE_BITMASK(5,5)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_SCAN_0_MIIM_SCAN_PHYADHI(x)  VTSS_EXTRACT_BITFIELD(x,5,5)

/** 
 * \brief
 * Indicates the low PHY number to scan during automatic scanning.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_SCAN_0 . MIIM_SCAN_PHYADLO
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_SCAN_0_MIIM_SCAN_PHYADLO(x)  VTSS_ENCODE_BITFIELD(x,0,5)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_SCAN_0_MIIM_SCAN_PHYADLO     VTSS_ENCODE_BITMASK(0,5)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_SCAN_0_MIIM_SCAN_PHYADLO(x)  VTSS_EXTRACT_BITFIELD(x,0,5)


/** 
 * \brief MIIM Scan 1
 *
 * \details
 * Register: \a DEVCPU_GCB:MIIM:MII_SCAN_1
 *
 * @param gi Replicator: x_FFL_DEVCPU_MIIM_CNT (??), 0-1
 */
#define VTSS_DEVCPU_GCB_MIIM_MII_SCAN_1(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x27,gi,9,0,6)

/** 
 * \brief
 * Indicates the mask for comparing the PHY registers during automatic
 * scan.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_SCAN_1 . MIIM_SCAN_MASK
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_SCAN_1_MIIM_SCAN_MASK(x)  VTSS_ENCODE_BITFIELD(x,16,16)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_SCAN_1_MIIM_SCAN_MASK     VTSS_ENCODE_BITMASK(16,16)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_SCAN_1_MIIM_SCAN_MASK(x)  VTSS_EXTRACT_BITFIELD(x,16,16)

/** 
 * \brief
 * Indicates the expected value for comparing the PHY registers during
 * automatic scan.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_SCAN_1 . MIIM_SCAN_EXPECT
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_SCAN_1_MIIM_SCAN_EXPECT(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_SCAN_1_MIIM_SCAN_EXPECT     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_SCAN_1_MIIM_SCAN_EXPECT(x)  VTSS_EXTRACT_BITFIELD(x,0,16)


/** 
 * \brief MIIM Results
 *
 * \details
 * Register: \a DEVCPU_GCB:MIIM:MII_SCAN_LAST_RSLTS
 *
 * @param gi Replicator: x_FFL_DEVCPU_MIIM_CNT (??), 0-1
 */
#define VTSS_DEVCPU_GCB_MIIM_MII_SCAN_LAST_RSLTS(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x27,gi,9,0,7)

/** 
 * \brief
 * Indicates for each PHY if a PHY register has matched the expected value
 * (with mask).
 * This register reflects the value of the last reading of the phy
 * register.
 *
 * \details 
 * 0 : Mismatch.
 * 1 : Match.
 *
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_SCAN_LAST_RSLTS . MIIM_LAST_RSLT
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_SCAN_LAST_RSLTS_MIIM_LAST_RSLT(x)  (x)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_SCAN_LAST_RSLTS_MIIM_LAST_RSLT     0xffffffff
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_SCAN_LAST_RSLTS_MIIM_LAST_RSLT(x)  (x)


/** 
 * \brief MIIM Results
 *
 * \details
 * Register: \a DEVCPU_GCB:MIIM:MII_SCAN_LAST_RSLTS_VLD
 *
 * @param gi Replicator: x_FFL_DEVCPU_MIIM_CNT (??), 0-1
 */
#define VTSS_DEVCPU_GCB_MIIM_MII_SCAN_LAST_RSLTS_VLD(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x27,gi,9,0,8)

/** 
 * \brief
 * Indicates for each PHY if a PHY register matched are valid or not.
 *
 * \details 
 * 0 : Scan result not valid. 
 * 1 : Scan result valid.
 *
 * Field: ::VTSS_DEVCPU_GCB_MIIM_MII_SCAN_LAST_RSLTS_VLD . MIIM_LAST_RSLT_VLD
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_SCAN_LAST_RSLTS_VLD_MIIM_LAST_RSLT_VLD(x)  (x)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_SCAN_LAST_RSLTS_VLD_MIIM_LAST_RSLT_VLD     0xffffffff
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_SCAN_LAST_RSLTS_VLD_MIIM_LAST_RSLT_VLD(x)  (x)

/**
 * Register Group: \a DEVCPU_GCB:MIIM_READ_SCAN
 *
 * Not documented
 */


/** 
 * \brief MIIM Results
 *
 * \details
 * Register: \a DEVCPU_GCB:MIIM_READ_SCAN:MII_SCAN_RSLTS_STICKY
 *
 * @param ri Replicator: x_FFL_DEVCPU_MIIM_CNT (??), 0-1
 */
#define VTSS_DEVCPU_GCB_MIIM_READ_SCAN_MII_SCAN_RSLTS_STICKY(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x39 + (ri))

/** 
 * \brief
 * Indicates for each PHY if a PHY register has had a mismatch of the
 * expected value (with mask) since last reading of MIIM_SCAN_RSLTS_STICKY.
 * 
 * Result is sticky, and result will indicate if there has been a mismatch
 * since the last reading of this register.
 * 
 * Upon reading this register, all bits are reset to '1'.
 *
 * \details 
 * 0 : Mismatch
 * 1 : Match.
 *
 * Field: ::VTSS_DEVCPU_GCB_MIIM_READ_SCAN_MII_SCAN_RSLTS_STICKY . MIIM_SCAN_RSLTS_STICKY
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_READ_SCAN_MII_SCAN_RSLTS_STICKY_MIIM_SCAN_RSLTS_STICKY(x)  (x)
#define  VTSS_M_DEVCPU_GCB_MIIM_READ_SCAN_MII_SCAN_RSLTS_STICKY_MIIM_SCAN_RSLTS_STICKY     0xffffffff
#define  VTSS_X_DEVCPU_GCB_MIIM_READ_SCAN_MII_SCAN_RSLTS_STICKY_MIIM_SCAN_RSLTS_STICKY(x)  (x)

/**
 * Register Group: \a DEVCPU_GCB:MIIM_SLAVE
 *
 * Not documented
 */


/** 
 * \brief MIIM Configuration
 *
 * \details
 * Register: \a DEVCPU_GCB:MIIM_SLAVE:MIIM_SLAVE_CFG
 */
#define VTSS_DEVCPU_GCB_MIIM_SLAVE_MIIM_SLAVE_CFG  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x3b)

/** 
 * \brief
 * Configuration of the spike filter width on the MDC and MDIO inputs.
 * Filters spikes with a width of (SPIKE_FILTER_CFG+1)*SYSTEM_CLK or less.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MIIM_SLAVE_MIIM_SLAVE_CFG . SPIKE_FILTER_CFG
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_SLAVE_MIIM_SLAVE_CFG_SPIKE_FILTER_CFG(x)  VTSS_ENCODE_BITFIELD(x,1,5)
#define  VTSS_M_DEVCPU_GCB_MIIM_SLAVE_MIIM_SLAVE_CFG_SPIKE_FILTER_CFG     VTSS_ENCODE_BITMASK(1,5)
#define  VTSS_X_DEVCPU_GCB_MIIM_SLAVE_MIIM_SLAVE_CFG_SPIKE_FILTER_CFG(x)  VTSS_EXTRACT_BITFIELD(x,1,5)

/** 
 * \brief
 * Set this field to enable the spike filter on the MDC and MDIO inputs.
 * When enabled the MIIM_SLAVE_CFG.SPIKE_FILTER_CFG field determines the
 * width of the spike filter.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MIIM_SLAVE_MIIM_SLAVE_CFG . SPIKE_FILTER_ENA
 */
#define  VTSS_F_DEVCPU_GCB_MIIM_SLAVE_MIIM_SLAVE_CFG_SPIKE_FILTER_ENA(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_GCB_MIIM_SLAVE_MIIM_SLAVE_CFG_SPIKE_FILTER_ENA  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_GCB_MIIM_SLAVE_MIIM_SLAVE_CFG_SPIKE_FILTER_ENA(x)  VTSS_EXTRACT_BITFIELD(x,0,1)

/**
 * Register Group: \a DEVCPU_GCB:PHY
 *
 * PHY configuration and status registers
 */


/** 
 * \brief PHY configuration register
 *
 * \details
 * Register: \a DEVCPU_GCB:PHY:PHY_CFG
 */
#define VTSS_DEVCPU_GCB_PHY_PHY_CFG          VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x3c)

/** 
 * \brief
 * PHY COMA input.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_PHY_PHY_CFG . PHY_COMA
 */
#define  VTSS_F_DEVCPU_GCB_PHY_PHY_CFG_PHY_COMA(x)  VTSS_ENCODE_BITFIELD(!!(x),12,1)
#define  VTSS_M_DEVCPU_GCB_PHY_PHY_CFG_PHY_COMA  VTSS_BIT(12)
#define  VTSS_X_DEVCPU_GCB_PHY_PHY_CFG_PHY_COMA(x)  VTSS_EXTRACT_BITFIELD(x,12,1)

/** 
 * \brief
 * PHY address input.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_PHY_PHY_CFG . PHY_ADDR
 */
#define  VTSS_F_DEVCPU_GCB_PHY_PHY_CFG_PHY_ADDR(x)  VTSS_ENCODE_BITFIELD(x,9,3)
#define  VTSS_M_DEVCPU_GCB_PHY_PHY_CFG_PHY_ADDR     VTSS_ENCODE_BITMASK(9,3)
#define  VTSS_X_DEVCPU_GCB_PHY_PHY_CFG_PHY_ADDR(x)  VTSS_EXTRACT_BITFIELD(x,9,3)

/** 
 * \details 
 * Set to 1 to release reset.
 *
 * Field: ::VTSS_DEVCPU_GCB_PHY_PHY_CFG . PHY_RESET
 */
#define  VTSS_F_DEVCPU_GCB_PHY_PHY_CFG_PHY_RESET(x)  VTSS_ENCODE_BITFIELD(x,5,4)
#define  VTSS_M_DEVCPU_GCB_PHY_PHY_CFG_PHY_RESET     VTSS_ENCODE_BITMASK(5,4)
#define  VTSS_X_DEVCPU_GCB_PHY_PHY_CFG_PHY_RESET(x)  VTSS_EXTRACT_BITFIELD(x,5,4)

/** 
 * \details 
 * Set to 1 to release reset.
 *
 * Field: ::VTSS_DEVCPU_GCB_PHY_PHY_CFG . PHY_COMMON_RESET
 */
#define  VTSS_F_DEVCPU_GCB_PHY_PHY_CFG_PHY_COMMON_RESET(x)  VTSS_ENCODE_BITFIELD(!!(x),4,1)
#define  VTSS_M_DEVCPU_GCB_PHY_PHY_CFG_PHY_COMMON_RESET  VTSS_BIT(4)
#define  VTSS_X_DEVCPU_GCB_PHY_PHY_CFG_PHY_COMMON_RESET(x)  VTSS_EXTRACT_BITFIELD(x,4,1)

/** 
 * \brief
 * Enable PHY interface for Device 0 to 3
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_PHY_PHY_CFG . PHY_ENA
 */
#define  VTSS_F_DEVCPU_GCB_PHY_PHY_CFG_PHY_ENA(x)  VTSS_ENCODE_BITFIELD(x,0,4)
#define  VTSS_M_DEVCPU_GCB_PHY_PHY_CFG_PHY_ENA     VTSS_ENCODE_BITMASK(0,4)
#define  VTSS_X_DEVCPU_GCB_PHY_PHY_CFG_PHY_ENA(x)  VTSS_EXTRACT_BITFIELD(x,0,4)


/** 
 * \brief PHY status register
 *
 * \details
 * Register: \a DEVCPU_GCB:PHY:PHY_STAT
 */
#define VTSS_DEVCPU_GCB_PHY_PHY_STAT         VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x3d)

/** 
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_PHY_PHY_STAT . PHY_COMA_OE
 */
#define  VTSS_F_DEVCPU_GCB_PHY_PHY_STAT_PHY_COMA_OE(x)  VTSS_ENCODE_BITFIELD(!!(x),22,1)
#define  VTSS_M_DEVCPU_GCB_PHY_PHY_STAT_PHY_COMA_OE  VTSS_BIT(22)
#define  VTSS_X_DEVCPU_GCB_PHY_PHY_STAT_PHY_COMA_OE(x)  VTSS_EXTRACT_BITFIELD(x,22,1)

/** 
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_PHY_PHY_STAT . PHY_COMA_O
 */
#define  VTSS_F_DEVCPU_GCB_PHY_PHY_STAT_PHY_COMA_O(x)  VTSS_ENCODE_BITFIELD(!!(x),21,1)
#define  VTSS_M_DEVCPU_GCB_PHY_PHY_STAT_PHY_COMA_O  VTSS_BIT(21)
#define  VTSS_X_DEVCPU_GCB_PHY_PHY_STAT_PHY_COMA_O(x)  VTSS_EXTRACT_BITFIELD(x,21,1)

/** 
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_PHY_PHY_STAT . FAST_LINK_STATUS
 */
#define  VTSS_F_DEVCPU_GCB_PHY_PHY_STAT_FAST_LINK_STATUS(x)  VTSS_ENCODE_BITFIELD(x,17,4)
#define  VTSS_M_DEVCPU_GCB_PHY_PHY_STAT_FAST_LINK_STATUS     VTSS_ENCODE_BITMASK(17,4)
#define  VTSS_X_DEVCPU_GCB_PHY_PHY_STAT_FAST_LINK_STATUS(x)  VTSS_EXTRACT_BITFIELD(x,17,4)

/** 
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_PHY_PHY_STAT . LINK_STAT_DUPLEX
 */
#define  VTSS_F_DEVCPU_GCB_PHY_PHY_STAT_LINK_STAT_DUPLEX(x)  VTSS_ENCODE_BITFIELD(x,13,4)
#define  VTSS_M_DEVCPU_GCB_PHY_PHY_STAT_LINK_STAT_DUPLEX     VTSS_ENCODE_BITMASK(13,4)
#define  VTSS_X_DEVCPU_GCB_PHY_PHY_STAT_LINK_STAT_DUPLEX(x)  VTSS_EXTRACT_BITFIELD(x,13,4)

/** 
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_PHY_PHY_STAT . LINK_STAT_SPEED_1000
 */
#define  VTSS_F_DEVCPU_GCB_PHY_PHY_STAT_LINK_STAT_SPEED_1000(x)  VTSS_ENCODE_BITFIELD(x,9,4)
#define  VTSS_M_DEVCPU_GCB_PHY_PHY_STAT_LINK_STAT_SPEED_1000     VTSS_ENCODE_BITMASK(9,4)
#define  VTSS_X_DEVCPU_GCB_PHY_PHY_STAT_LINK_STAT_SPEED_1000(x)  VTSS_EXTRACT_BITFIELD(x,9,4)

/** 
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_PHY_PHY_STAT . LINK_STAT_SPEED_100
 */
#define  VTSS_F_DEVCPU_GCB_PHY_PHY_STAT_LINK_STAT_SPEED_100(x)  VTSS_ENCODE_BITFIELD(x,5,4)
#define  VTSS_M_DEVCPU_GCB_PHY_PHY_STAT_LINK_STAT_SPEED_100     VTSS_ENCODE_BITMASK(5,4)
#define  VTSS_X_DEVCPU_GCB_PHY_PHY_STAT_LINK_STAT_SPEED_100(x)  VTSS_EXTRACT_BITFIELD(x,5,4)

/** 
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_PHY_PHY_STAT . LINK_STAT_SPEED_10
 */
#define  VTSS_F_DEVCPU_GCB_PHY_PHY_STAT_LINK_STAT_SPEED_10(x)  VTSS_ENCODE_BITFIELD(x,1,4)
#define  VTSS_M_DEVCPU_GCB_PHY_PHY_STAT_LINK_STAT_SPEED_10     VTSS_ENCODE_BITMASK(1,4)
#define  VTSS_X_DEVCPU_GCB_PHY_PHY_STAT_LINK_STAT_SPEED_10(x)  VTSS_EXTRACT_BITFIELD(x,1,4)

/** 
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_PHY_PHY_STAT . SUPERVISOR_COMPLETE
 */
#define  VTSS_F_DEVCPU_GCB_PHY_PHY_STAT_SUPERVISOR_COMPLETE(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_GCB_PHY_PHY_STAT_SUPERVISOR_COMPLETE  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_GCB_PHY_PHY_STAT_SUPERVISOR_COMPLETE(x)  VTSS_EXTRACT_BITFIELD(x,0,1)

/**
 * Register Group: \a DEVCPU_GCB:SIO_CTRL
 *
 * Serial IO control configuration
 */


/** 
 * \brief Last value at SGPIO pins
 *
 * \details
 * Register: \a DEVCPU_GCB:SIO_CTRL:SIO_INPUT_DATA
 *
 * @param ri Replicator: x_FFL_DEVCPU_SIO_IOS_PR_PORT (??), 0-3
 */
#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INPUT_DATA(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x3e + (ri))

/** 
 * \brief
 * Serial input data. Each replication, N, holds bit N from all ports - bit
 * N from port M is mapped to replication N bit M. Values of disabled gpios
 * are undefined.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INPUT_DATA . SIO_INPUT_DATA
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_INPUT_DATA_SIO_INPUT_DATA(x)  (x)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_INPUT_DATA_SIO_INPUT_DATA     0xffffffff
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_INPUT_DATA_SIO_INPUT_DATA(x)  (x)


/** 
 * \brief General configurations
 *
 * \details
 * Register: \a DEVCPU_GCB:SIO_CTRL:SIO_CFG
 */
#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG     VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x42)

/** 
 * \brief
 * Configure the size of the PWM window.
 *
 * \details 
 * 0 : 255 cycles
 * 1-254 : 2-255 cycles
 * 255 : Reserved.
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG . SIO_PWM_WINDOW
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_PWM_WINDOW(x)  VTSS_ENCODE_BITFIELD(x,24,8)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_PWM_WINDOW     VTSS_ENCODE_BITMASK(24,8)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_PWM_WINDOW(x)  VTSS_EXTRACT_BITFIELD(x,24,8)

/** 
 * \brief
 * When set, the SIO_BURST_GAP is divided by 32.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG . SIO_REDUCED_GAP
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_REDUCED_GAP(x)  VTSS_ENCODE_BITFIELD(!!(x),23,1)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_REDUCED_GAP  VTSS_BIT(23)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_REDUCED_GAP(x)  VTSS_EXTRACT_BITFIELD(x,23,1)

/** 
 * \brief
 * Configuration for blink mode 1.
 * Supports three different blink modes and a "burst toggle" mode in which
 * blink mode 1 will alternate for each burst.
 *
 * \details 
 * 0: Blink freq appr. 20Hz
 * 1: Blink freq appr. 10Hz
 * 2: Blink freq appr. 5Hz
 * 3: Burst toggle
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG . SIO_BMODE_1
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BMODE_1(x)  VTSS_ENCODE_BITFIELD(x,21,2)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BMODE_1     VTSS_ENCODE_BITMASK(21,2)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BMODE_1(x)  VTSS_EXTRACT_BITFIELD(x,21,2)

/** 
 * \brief
 * Configuration of blink mode 0. Supports four different blink modes.
 *
 * \details 
 * 0 : Blink freq appr. 5Hz.
 * 1 : Blink freq appr. 2.5Hz.
 * 2 : Blink freq appr. 1.25Hz.
 * 3 : Blink freq appr. 0.625Hz.
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG . SIO_BMODE_0
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BMODE_0(x)  VTSS_ENCODE_BITFIELD(x,19,2)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BMODE_0     VTSS_ENCODE_BITMASK(19,2)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BMODE_0(x)  VTSS_EXTRACT_BITFIELD(x,19,2)

/** 
 * \brief
 * Reset the blink counters. Used to synchronize the blink modes between
 * different chips.
 *
 * \details 
 * 0: Blink counter is running
 * 1: Blink counter is reset until sio_blink_reset is unset again
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG . SIO_BLINK_RESET
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BLINK_RESET(x)  VTSS_ENCODE_BITFIELD(!!(x),18,1)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BLINK_RESET  VTSS_BIT(18)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BLINK_RESET(x)  VTSS_EXTRACT_BITFIELD(x,18,1)

/** 
 * \brief
 * Set to disable burst gap.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG . SIO_BURST_GAP_DIS
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BURST_GAP_DIS(x)  VTSS_ENCODE_BITFIELD(!!(x),17,1)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BURST_GAP_DIS  VTSS_BIT(17)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BURST_GAP_DIS(x)  VTSS_EXTRACT_BITFIELD(x,17,1)

/** 
 * \brief
 * Configures the length of burst gap in steps of approx. 1.68 ms. Burst
 * gap can be disabled by setting DEVCPU_GCB::SIO_CFG.SIO_BURST_GAP_DIS.
 * For smaller burst gap set DEVCPU_GCB::SIO_CFG.SIO_REDUCED_GAP. The gap
 * is calculated by (Value+1) * (2^18) * (system clock period).
 *
 * \details 
 * 0: 1.68 ms burst gap
 * 1: 3.36 ms burst gap
 * ...
 * 31: 53.69 ms burst gap
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG . SIO_BURST_GAP
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BURST_GAP(x)  VTSS_ENCODE_BITFIELD(x,12,5)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BURST_GAP     VTSS_ENCODE_BITMASK(12,5)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_BURST_GAP(x)  VTSS_EXTRACT_BITFIELD(x,12,5)

/** 
 * \brief
 * Use this to output a single burst. Will be cleared by hardware when the
 * burst has finished.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG . SIO_SINGLE_SHOT
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_SINGLE_SHOT(x)  VTSS_ENCODE_BITFIELD(!!(x),11,1)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_SINGLE_SHOT  VTSS_BIT(11)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_SINGLE_SHOT(x)  VTSS_EXTRACT_BITFIELD(x,11,1)

/** 
 * \brief
 * Use this to output repeated bursts interleaved with burst gaps. Must be
 * manually reset again to stop output of bursts.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG . SIO_AUTO_REPEAT
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_AUTO_REPEAT(x)  VTSS_ENCODE_BITFIELD(!!(x),10,1)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_AUTO_REPEAT  VTSS_BIT(10)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_AUTO_REPEAT(x)  VTSS_EXTRACT_BITFIELD(x,10,1)

/** 
 * \brief
 * Polarity of the "Ld" signal
 *
 * \details 
 * 0: load signal is active low
 * 1: load signal is active high
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG . SIO_LD_POLARITY
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_LD_POLARITY(x)  VTSS_ENCODE_BITFIELD(!!(x),9,1)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_LD_POLARITY  VTSS_BIT(9)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_LD_POLARITY(x)  VTSS_EXTRACT_BITFIELD(x,9,1)

/** 
 * \brief
 * Number of SGPIOs pr. port.
 *
 * \details 
 * 0: 1 gpio pr. port
 * 1: 2 gpios pr. port
 * 2: 3 gpios pr. port
 * 3: 4 gpios pr. port
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG . SIO_PORT_WIDTH
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_PORT_WIDTH(x)  VTSS_ENCODE_BITFIELD(x,7,2)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_PORT_WIDTH     VTSS_ENCODE_BITMASK(7,2)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_PORT_WIDTH(x)  VTSS_EXTRACT_BITFIELD(x,7,2)

/** 
 * \brief
 * Reverse the output bitstream.
 * The default order of the output bit stream is (displayed in transmitted
 * order):
 * (portN bit3, portN bit2, ...., port0 bit1, port0 bit0)
 * The reverse order of the output bit stream is (displayed in transmitted
 * order):
 * (port0 bit0, port0 bit1, ...., portN bit2, portN bit3)
 *
 * \details 
 * 0: Do not reverse
 * 1: Reverse
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG . SIO_REVERSE_OUTPUT
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_REVERSE_OUTPUT(x)  VTSS_ENCODE_BITFIELD(!!(x),6,1)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_REVERSE_OUTPUT  VTSS_BIT(6)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_REVERSE_OUTPUT(x)  VTSS_EXTRACT_BITFIELD(x,6,1)

/** 
 * \brief
 * Reverse the input bitstream.
 * The default order of the input bit stream is (displayed in received
 * order):
 * (port0 bit0, port0 bit1, ...., portN bit2, portN bit3)
 * The reverse order of the input bit stream is (displayed in received
 * order):
 * (portN bit3, portN bit2, ...., port0 bit1, port0 bit0)
 *
 * \details 
 * 0: Do not reverse
 * 1: Reverse
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG . SIO_REVERSE_INPUT
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_REVERSE_INPUT(x)  VTSS_ENCODE_BITFIELD(!!(x),5,1)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_REVERSE_INPUT  VTSS_BIT(5)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_REVERSE_INPUT(x)  VTSS_EXTRACT_BITFIELD(x,5,1)

/** 
 * \brief
 * Bit interrupt enable. Enables interrupts for the four gpios in a port.
 * Is applied to all ports.
 *
 * \details 
 * 0: Interrupt is disabled for bit n for all ports
 * 1: Interrupt is enabled for bit n for all ports
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG . SIO_GPIO_INTR_ENA
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_GPIO_INTR_ENA(x)  VTSS_ENCODE_BITFIELD(x,1,4)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_GPIO_INTR_ENA     VTSS_ENCODE_BITMASK(1,4)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_GPIO_INTR_ENA(x)  VTSS_EXTRACT_BITFIELD(x,1,4)

/** 
 * \brief
 * Master interrupt enable. Enables interrupts. Is applied to all gpios on
 * all ports. This field only has effect on the interrupt output signal of
 * the sio_ctrl block. It has no effect on the interrupt registers.
 *
 * \details 
 * 0: Interrupt is disabled for all bits for all ports
 * 1: Interrupt is enabled for all bits for all ports
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CFG . SIO_MASTER_INTR_ENA
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_MASTER_INTR_ENA(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_MASTER_INTR_ENA  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CFG_SIO_MASTER_INTR_ENA(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


/** 
 * \brief SGPIO shift clock frequency
 *
 * \details
 * Register: \a DEVCPU_GCB:SIO_CTRL:SIO_CLOCK
 */
#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CLOCK   VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x43)

/** 
 * \brief
 * SIO controller clock frequency. Divides the 250 MHz system clk with the
 * value of this field. E.g. field is set to 10, the output frequency will
 * be 25 MHz.
 *
 * \details 
 * 0: Disable clock
 * 1: Reserved, do not use
 * Others : Clock divider value.
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CLOCK . SIO_CLK_FREQ
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CLOCK_SIO_CLK_FREQ(x)  VTSS_ENCODE_BITFIELD(x,8,12)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CLOCK_SIO_CLK_FREQ     VTSS_ENCODE_BITMASK(8,12)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CLOCK_SIO_CLK_FREQ(x)  VTSS_EXTRACT_BITFIELD(x,8,12)

/** 
 * \brief
 * The system clock period given in the clock period in PS divided by 100.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CLOCK . SYS_CLK_PERIOD
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CLOCK_SYS_CLK_PERIOD(x)  VTSS_ENCODE_BITFIELD(x,0,8)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CLOCK_SYS_CLK_PERIOD     VTSS_ENCODE_BITMASK(0,8)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CLOCK_SYS_CLK_PERIOD(x)  VTSS_EXTRACT_BITFIELD(x,0,8)


/** 
 * \brief Output configuration
 *
 * \details
 * Register: \a DEVCPU_GCB:SIO_CTRL:SIO_PORT_CFG
 *
 * @param ri Replicator: x_FFL_DEVCPU_SIO_PORT_CNT (??), 0-31
 */
#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x44 + (ri))

/** 
 * \brief
 * Output source select for the four outputs from each port.The source
 * select is encoded using three bits for each output bit: Output bit0 is
 * defined by (2 down to 0), output bit1 is defined by (5 down to 3),
 * output bit2 is defined by (8 down to 6), and output bit3 is defined by
 * (11 down to 9).
 *
 * \details 
 * 0: Forced 0
 * 1: Forced 1
 * 2: Blink mode 0
 * 3: Blink mode 1
 * 4: Link activity blink mode 0
 * 5: Link activity blink mode 1
 * 6: Reserved
 * 7: Reserved
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG . BIT_SOURCE
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_BIT_SOURCE(x)  VTSS_ENCODE_BITFIELD(x,12,12)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_BIT_SOURCE     VTSS_ENCODE_BITMASK(12,12)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_BIT_SOURCE(x)  VTSS_EXTRACT_BITFIELD(x,12,12)

/** 
 * \brief
 * PWM source select for the four outputs from each port.The PWM source
 * select is encoded using two bits for each output bit: Output bit0 is
 * defined by (1 down to 0), output bit1 is defined by (3 down to 2),
 * output bit2 is defined by (5 down to 4), and output bit3 is defined by
 * (7 down to 6).
 *
 * \details 
 * 0: PWM disabled
 * 1: PWM 0 used
 * 2: PWM 1 used
 * 3: PWM 2 used
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG . PWM_SOURCE
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_PWM_SOURCE(x)  VTSS_ENCODE_BITFIELD(x,4,8)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_PWM_SOURCE     VTSS_ENCODE_BITMASK(4,8)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_PWM_SOURCE(x)  VTSS_EXTRACT_BITFIELD(x,4,8)

/** 
 * \brief
 * Output polarity select for the four outputs from each port.The polarity
 * select is encoded using one bit for each output bit.
 *
 * \details 
 * 0: Normal polarity
 * 1: Inversed polarity
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG . BIT_POLARITY
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_BIT_POLARITY(x)  VTSS_ENCODE_BITFIELD(x,0,4)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_BIT_POLARITY     VTSS_ENCODE_BITMASK(0,4)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CFG_BIT_POLARITY(x)  VTSS_EXTRACT_BITFIELD(x,0,4)


/** 
 * \brief Port enable
 *
 * \details
 * Register: \a DEVCPU_GCB:SIO_CTRL:SIO_PORT_ENA
 */
#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PORT_ENA  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x64)

/** 
 * \brief
 * Port enable vector with one enable bit for each port.
 * Port order: (portN down to port0)
 *
 * \details 
 * 0: Port is disabled
 * 1: Port is enabled
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PORT_ENA . SIO_PORT_ENA
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_PORT_ENA_SIO_PORT_ENA(x)  (x)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_PORT_ENA_SIO_PORT_ENA     0xffffffff
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_PORT_ENA_SIO_PORT_ENA(x)  (x)


/** 
 * \brief Pulse-width modulation configuration
 *
 * \details
 * Register: \a DEVCPU_GCB:SIO_CTRL:SIO_PWM_CFG
 *
 * @param ri Register: SIO_PWM_CFG (??), 0-2
 */
#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PWM_CFG(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x65 + (ri))

/** 
 * \brief
 * Define the duty cycle for the PWMs.
 *
 * \details 
 * 0x00: Always "off"
 * 0xFF: Always "on"
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PWM_CFG . PWM_DUTY_CYCLE
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_PWM_CFG_PWM_DUTY_CYCLE(x)  VTSS_ENCODE_BITFIELD(x,0,8)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_PWM_CFG_PWM_DUTY_CYCLE     VTSS_ENCODE_BITMASK(0,8)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_PWM_CFG_PWM_DUTY_CYCLE(x)  VTSS_EXTRACT_BITFIELD(x,0,8)


/** 
 * \brief SGPIO interrupt polarity
 *
 * \details
 * Register: \a DEVCPU_GCB:SIO_CTRL:SIO_INTR_POL
 *
 * @param ri Replicator: x_FFL_DEVCPU_SIO_IOS_PR_PORT (??), 0-3
 */
#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR_POL(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x68 + (ri))

/** 
 * \brief
 * Interrupt polarity. This register defines at which logic value an
 * interrupt is generated. For bit0 this register is also used to define
 * the polarity of the "loss of signal" output.
 *
 * \details 
 * 0: interrupt and "loss of signal" is active high
 * 1: interrupt and "loss of signal" is active low
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR_POL . SIO_INTR_POL
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_INTR_POL_SIO_INTR_POL(x)  (x)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_INTR_POL_SIO_INTR_POL     0xffffffff
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_INTR_POL_SIO_INTR_POL(x)  (x)


/** 
 * \brief Interrupt raw status
 *
 * \details
 * Register: \a DEVCPU_GCB:SIO_CTRL:SIO_INTR_RAW
 *
 * @param ri Replicator: x_FFL_DEVCPU_SIO_IOS_PR_PORT (??), 0-3
 */
#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR_RAW(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x6c + (ri))

/** 
 * \brief
 * Shows the current value of individual interrupts. All interrupts are
 * active high (but has been corrected for polarity as configured in
 * SIO_INTR_POL).
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR_RAW . SIO_INTR_RAW
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_INTR_RAW_SIO_INTR_RAW(x)  (x)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_INTR_RAW_SIO_INTR_RAW     0xffffffff
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_INTR_RAW_SIO_INTR_RAW(x)  (x)


/** 
 * \brief Interrupt trigger mode 0
 *
 * \details
 * Register: \a DEVCPU_GCB:SIO_CTRL:SIO_INTR_TRIGGER0
 *
 * @param ri Replicator: x_FFL_DEVCPU_SIO_IOS_PR_PORT (??), 0-3
 */
#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR_TRIGGER0(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x70 + (ri))

/** 
 * \brief
 * Configure trigger mode of individual interrupts. The trigger mode
 * determines how the value of the SIO_INTR_RAW register is transfered to
 * the SIO_INTR register.
 * 
 * This register is the LSB of the encoding. Register SIO_INTR_TRIGGER1 is
 * the MSB of the encoding.
 * 
 * For level-triggered interrupts SIO_INTR is set when an input is received
 * that results in a high corresponding bit in SIO_INTR_RAW.
 * For edge-triggered interrupts SIO_INTR is set when an input is received
 * that results in a change of the corresponding bit in SIO_INTR_RAW.
 * For falling-edge-triggered interrupts SIO_INTR is set when an input is
 * received that results in a change from '1' to '0' of the corresponding
 * bit in SIO_INTR_RAW.
 * For rising-edge-triggered interrupts SIO_INTR is set when an input is
 * received that results in a change from '0' to '1' of the corresponding
 * bit in SIO_INTR_RAW.
 *
 * \details 
 * 00: Interrupt is level-activated
 * 01: Interrupt is edge-triggered
 * 10: Interrupt is falling-edge-triggered
 * 11: Interrupt is rising-edge-triggered
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR_TRIGGER0 . SIO_INTR_TRIGGER0
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_INTR_TRIGGER0_SIO_INTR_TRIGGER0(x)  (x)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_INTR_TRIGGER0_SIO_INTR_TRIGGER0     0xffffffff
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_INTR_TRIGGER0_SIO_INTR_TRIGGER0(x)  (x)


/** 
 * \brief Interrupt trigger mode 1
 *
 * \details
 * Register: \a DEVCPU_GCB:SIO_CTRL:SIO_INTR_TRIGGER1
 *
 * @param ri Replicator: x_FFL_DEVCPU_SIO_IOS_PR_PORT (??), 0-3
 */
#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR_TRIGGER1(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x74 + (ri))

/** 
 * \brief
 * See description of SIO_INTR_TRIGGER0.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR_TRIGGER1 . SIO_INTR_TRIGGER1
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_INTR_TRIGGER1_SIO_INTR_TRIGGER1(x)  (x)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_INTR_TRIGGER1_SIO_INTR_TRIGGER1     0xffffffff
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_INTR_TRIGGER1_SIO_INTR_TRIGGER1(x)  (x)


/** 
 * \brief Currently interrupting SGPIOs
 *
 * \details
 * Register: \a DEVCPU_GCB:SIO_CTRL:SIO_INTR
 *
 * @param ri Replicator: x_FFL_DEVCPU_SIO_IOS_PR_PORT (??), 0-3
 */
#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x78 + (ri))

/** 
 * \brief
 * Interrupt register. These sticky bits are set when an input is received
 * that are triggered by the corresponding SIO_INTR_TRIGGER configuration.
 *
 * \details 
 * 0: No interrupt for given gpio
 * 1: Interrupt for given gpio
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR . SIO_INTR
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_INTR_SIO_INTR(x)  (x)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_INTR_SIO_INTR     0xffffffff
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_INTR_SIO_INTR(x)  (x)


/** 
 * \brief SGPIO interrupt enable per port
 *
 * \details
 * Register: \a DEVCPU_GCB:SIO_CTRL:SIO_INTR_ENA
 */
#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR_ENA  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x7c)

/** 
 * \brief
 * Interrupt enable vector with one enable bit for each port.
 * Port order: (portN down to port0)

 *
 * \details 
 * 0: Interrupt is disabled for the port
 * 1: Interrupt is enabled for the port
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR_ENA . SIO_INTR_ENA
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_INTR_ENA_SIO_INTR_ENA(x)  (x)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_INTR_ENA_SIO_INTR_ENA     0xffffffff
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_INTR_ENA_SIO_INTR_ENA(x)  (x)


/** 
 * \brief Currently active interrupts
 *
 * \details
 * Register: \a DEVCPU_GCB:SIO_CTRL:SIO_INTR_IDENT
 *
 * @param ri Replicator: x_FFL_DEVCPU_SIO_IOS_PR_PORT (??), 0-3
 */
#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR_IDENT(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x7d + (ri))

/** 
 * \brief
 * Shows the currently active interrupts. This register is the result of
 * the SIO_INTR interrupts with the disabled interrupts (from SIO_INTR_ENA
 * and SIO_GPIO_INTR_ENA) removed.
 *
 * \details 
 * 0: No active interrupt for given gpio
 * 1: Active interrupt for given gpio
 *
 * Field: ::VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INTR_IDENT . SIO_INTR_IDENT
 */
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_INTR_IDENT_SIO_INTR_IDENT(x)  (x)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_INTR_IDENT_SIO_INTR_IDENT     0xffffffff
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_INTR_IDENT_SIO_INTR_IDENT(x)  (x)

/**
 * Register Group: \a DEVCPU_GCB:FAN_CTRL
 *
 * Fan controller configuration and status
 */


/** 
 * \brief Fan controller configuration
 *
 * \details
 * Register: \a DEVCPU_GCB:FAN_CTRL:FAN_CFG
 */
#define VTSS_DEVCPU_GCB_FAN_CTRL_FAN_CFG     VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x81)

/** 
 * \brief
 * Define the duty cycle
 *
 * \details 
 * 0x00: Always "off"
 * 0xFF: Always "on"
 *
 * Field: ::VTSS_DEVCPU_GCB_FAN_CTRL_FAN_CFG . DUTY_CYCLE
 */
#define  VTSS_F_DEVCPU_GCB_FAN_CTRL_FAN_CFG_DUTY_CYCLE(x)  VTSS_ENCODE_BITFIELD(x,16,8)
#define  VTSS_M_DEVCPU_GCB_FAN_CTRL_FAN_CFG_DUTY_CYCLE     VTSS_ENCODE_BITMASK(16,8)
#define  VTSS_X_DEVCPU_GCB_FAN_CTRL_FAN_CFG_DUTY_CYCLE(x)  VTSS_EXTRACT_BITFIELD(x,16,8)

/** 
 * \brief
 * The number of system clock cycles that fit in 10 us.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_FAN_CTRL_FAN_CFG . CLK_CYCLES_10US
 */
#define  VTSS_F_DEVCPU_GCB_FAN_CTRL_FAN_CFG_CLK_CYCLES_10US(x)  VTSS_ENCODE_BITFIELD(x,4,12)
#define  VTSS_M_DEVCPU_GCB_FAN_CTRL_FAN_CFG_CLK_CYCLES_10US     VTSS_ENCODE_BITMASK(4,12)
#define  VTSS_X_DEVCPU_GCB_FAN_CTRL_FAN_CFG_CLK_CYCLES_10US(x)  VTSS_EXTRACT_BITFIELD(x,4,12)

/** 
 * \brief
 * Define the polarity of the PWM output.
 *
 * \details 
 * 0: PWM is logic 1 when "on"
 * 1: PWM is logic 0 when "on"
 *
 * Field: ::VTSS_DEVCPU_GCB_FAN_CTRL_FAN_CFG . INV_POL
 */
#define  VTSS_F_DEVCPU_GCB_FAN_CTRL_FAN_CFG_INV_POL(x)  VTSS_ENCODE_BITFIELD(!!(x),3,1)
#define  VTSS_M_DEVCPU_GCB_FAN_CTRL_FAN_CFG_INV_POL  VTSS_BIT(3)
#define  VTSS_X_DEVCPU_GCB_FAN_CTRL_FAN_CFG_INV_POL(x)  VTSS_EXTRACT_BITFIELD(x,3,1)

/** 
 * \brief
 * Enable gating of the TACH input by the PWM output so that only TACH
 * pulses received when PWM is "on" are counted.
 *
 * \details 
 * 0: Disabled
 * 1: Enabled
 *
 * Field: ::VTSS_DEVCPU_GCB_FAN_CTRL_FAN_CFG . GATE_ENA
 */
#define  VTSS_F_DEVCPU_GCB_FAN_CTRL_FAN_CFG_GATE_ENA(x)  VTSS_ENCODE_BITFIELD(!!(x),2,1)
#define  VTSS_M_DEVCPU_GCB_FAN_CTRL_FAN_CFG_GATE_ENA  VTSS_BIT(2)
#define  VTSS_X_DEVCPU_GCB_FAN_CTRL_FAN_CFG_GATE_ENA(x)  VTSS_EXTRACT_BITFIELD(x,2,1)

/** 
 * \brief
 * Configure the PWM output to be open collector
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_FAN_CTRL_FAN_CFG . PWM_OPEN_COL_ENA
 */
#define  VTSS_F_DEVCPU_GCB_FAN_CTRL_FAN_CFG_PWM_OPEN_COL_ENA(x)  VTSS_ENCODE_BITFIELD(!!(x),1,1)
#define  VTSS_M_DEVCPU_GCB_FAN_CTRL_FAN_CFG_PWM_OPEN_COL_ENA  VTSS_BIT(1)
#define  VTSS_X_DEVCPU_GCB_FAN_CTRL_FAN_CFG_PWM_OPEN_COL_ENA(x)  VTSS_EXTRACT_BITFIELD(x,1,1)

/** 
 * \brief
 * Configure behavior of TACH input tick counter, see DEVCPU_GCB::FAN_CNT
 * for more infromation.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_FAN_CTRL_FAN_CFG . FAN_STAT_CFG
 */
#define  VTSS_F_DEVCPU_GCB_FAN_CTRL_FAN_CFG_FAN_STAT_CFG(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_GCB_FAN_CTRL_FAN_CFG_FAN_STAT_CFG  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_GCB_FAN_CTRL_FAN_CFG_FAN_STAT_CFG(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


/** 
 * \brief Configuration of the PWM frequency.
 *
 * \details
 * Register: \a DEVCPU_GCB:FAN_CTRL:PWM_FREQ
 */
#define VTSS_DEVCPU_GCB_FAN_CTRL_PWM_FREQ    VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x82)

/** 
 * \brief
 * Set the frequency of the PWM output. The value of this field must be
 * (System clock frequency)/(PWM frequency)/256.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_FAN_CTRL_PWM_FREQ . PWM_FREQ
 */
#define  VTSS_F_DEVCPU_GCB_FAN_CTRL_PWM_FREQ_PWM_FREQ(x)  VTSS_ENCODE_BITFIELD(x,0,17)
#define  VTSS_M_DEVCPU_GCB_FAN_CTRL_PWM_FREQ_PWM_FREQ     VTSS_ENCODE_BITMASK(0,17)
#define  VTSS_X_DEVCPU_GCB_FAN_CTRL_PWM_FREQ_PWM_FREQ(x)  VTSS_EXTRACT_BITFIELD(x,0,17)


/** 
 * \brief TACH counter
 *
 * \details
 * Register: \a DEVCPU_GCB:FAN_CTRL:FAN_CNT
 */
#define VTSS_DEVCPU_GCB_FAN_CTRL_FAN_CNT     VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x83)

/** 
 * \brief
 * Counts the number of TACH input ticks. If
 * DEVCPU_GCB::FAN_CFG.FAN_STAT_CFG is set then this is a wrapping counter
 * that shows the total number of registered TACH ticks. If
 * DEVCPU_GCB::FAN_CFG.FAN_STAT_CFG is cleared then this counter is updated
 * once every second with the number of TACH ticks registered during the
 * last second.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_FAN_CTRL_FAN_CNT . FAN_CNT
 */
#define  VTSS_F_DEVCPU_GCB_FAN_CTRL_FAN_CNT_FAN_CNT(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_DEVCPU_GCB_FAN_CTRL_FAN_CNT_FAN_CNT     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_DEVCPU_GCB_FAN_CTRL_FAN_CNT_FAN_CNT(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

/**
 * Register Group: \a DEVCPU_GCB:MEMITGR
 *
 * Memory integrity monitor
 */


/** 
 * \brief Monitor control
 *
 * \details
 * Register: \a DEVCPU_GCB:MEMITGR:MEMITGR_CTRL
 */
#define VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_CTRL  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x84)

/** 
 * \brief
 * Setting this field transitions the integrity monitor between operating
 * modes. Transitioning between modes takes time, this field remains set
 * until the new mode is reached. During this time the monitor also reports
 * busy DEVCPU_GCB::MEMITGR_STAT.MODE_BUSY is set).
 * From IDLE (DEVCPU_GCB::MEMITGR_STAT.MODE_IDLE is set) the monitor can
 * transition into either DETECT or LISTEN mode, the DETECT mode is entered
 * if a memory reports an indication - the LISTEN mode is entered if no
 * indications are reported. The first time after reset the monitor will
 * not detect indications, that is; it will transition directly from IDLE
 * to LISTEN mode.
 * From DETECT (DEVCPU_GCB::MEMITGR_STAT.MODE_DETECT is set) the monitor
 * can transition into either DETECT or LISTEN mode, the DETECT mode is
 * entered if more indications are reported - the LISTEN mode is entered if
 * no more indications are reported.
 * From LISTEN (DEVCPU_GCB::MEMITGR_STAT.MODE_LISTEN is set) the monitor
 * can transition into IDLE mode.
 * Software shall not set this field when the monitor is BUSY (when
 * DEVCPU_GCB::MEMITGR_STAT.MODE_BUSY is set.)
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_CTRL . ACTIVATE
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_CTRL_ACTIVATE(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_CTRL_ACTIVATE  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_CTRL_ACTIVATE(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


/** 
 * \brief Monitor status
 *
 * \details
 * Register: \a DEVCPU_GCB:MEMITGR:MEMITGR_STAT
 */
#define VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_STAT  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x85)

/** 
 * \brief
 * This field is set if there is an overflow when recording indications
 * from the memories. If this happens (setting of this field) the value of
 * the DEVCPU_GCB::MEMITGR_DIV.MEM_DIV field is set too low!
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_STAT . INDICATION_OVF
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_INDICATION_OVF(x)  VTSS_ENCODE_BITFIELD(!!(x),5,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_INDICATION_OVF  VTSS_BIT(5)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_INDICATION_OVF(x)  VTSS_EXTRACT_BITFIELD(x,5,1)

/** 
 * \brief
 * If this field is set then there is an indication from one of the
 * memories that needs to be analyzed. An indication is either a parity
 * detection or an error correction.
 * This field is only set when the monitor is in LISTEN mode
 * (DEVCPU_GCB::MEMITGR_STAT.MODE_LISTEN is set), in all other states
 * (including BUSY) this field returns 0.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_STAT . INDICATION
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_INDICATION(x)  VTSS_ENCODE_BITFIELD(!!(x),4,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_INDICATION  VTSS_BIT(4)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_INDICATION(x)  VTSS_EXTRACT_BITFIELD(x,4,1)

/** 
 * \brief
 * This field is set when the monitor is in LISTEN mode, during listen mode
 * the monitor continually check for parity/correction indications from the
 * memories.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_STAT . MODE_LISTEN
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_MODE_LISTEN(x)  VTSS_ENCODE_BITFIELD(!!(x),3,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_MODE_LISTEN  VTSS_BIT(3)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_MODE_LISTEN(x)  VTSS_EXTRACT_BITFIELD(x,3,1)

/** 
 * \brief
 * This field is set when the monitor is in DETECT mode, during detect mode
 * the DEVCPU_GCB::MEMITGR_INFO and DEVCPU_GCB::MEMITGR_IDX registers
 * contains valid information about one indication.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_STAT . MODE_DETECT
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_MODE_DETECT(x)  VTSS_ENCODE_BITFIELD(!!(x),2,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_MODE_DETECT  VTSS_BIT(2)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_MODE_DETECT(x)  VTSS_EXTRACT_BITFIELD(x,2,1)

/** 
 * \brief
 * This field is set when the monitor is in IDLE mode.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_STAT . MODE_IDLE
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_MODE_IDLE(x)  VTSS_ENCODE_BITFIELD(!!(x),1,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_MODE_IDLE  VTSS_BIT(1)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_MODE_IDLE(x)  VTSS_EXTRACT_BITFIELD(x,1,1)

/** 
 * \brief
 * The busy signal is a copy of the DEVCPU_GCB::MEMITGR_CTRL.ACTIVATE
 * field, see description of that field for more information about the
 * different states/modes of the monitor.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_STAT . MODE_BUSY
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_MODE_BUSY(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_MODE_BUSY  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_MODE_BUSY(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


/** 
 * \brief Memory indication
 *
 * \details
 * This field is only valid when the monitor is in the DETECT
 * (DEVCPU_GCB::MEMITGR_STAT.MODE_DETECT is set) mode.
 *
 * Register: \a DEVCPU_GCB:MEMITGR:MEMITGR_INFO
 */
#define VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_INFO  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x86)

/** 
 * \brief
 * This field is set if the monitor has detected a parity indication (or an
 * unrecoverable correction).
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_INFO . MEM_ERR
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_ERR(x)  VTSS_ENCODE_BITFIELD(!!(x),31,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_ERR  VTSS_BIT(31)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_ERR(x)  VTSS_EXTRACT_BITFIELD(x,31,1)

/** 
 * \brief
 * This field is set if the monitor has detected a correction.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_INFO . MEM_COR
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_COR(x)  VTSS_ENCODE_BITFIELD(!!(x),30,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_COR  VTSS_BIT(30)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_COR(x)  VTSS_EXTRACT_BITFIELD(x,30,1)

/** 
 * \brief
 * This field is set if the monitor has detected a parity indication (or an
 * unrecoverable correction) for which the address has not been recorded.
 * If DEVCPU_GCB::MEMITGR_INFO.MEM_ERR is set then there has been more than
 * one indication, then only the address of the newest indication has been
 * kept. 
 * If DEVCPU_GCB::MEMITGR_INFO.MEM_ERR is cleared then an indication has
 * occurred for which the address could not be stored, this is a very rare
 * situation that can only happen if an indication is detected just as the
 * memory is talking to the monitor.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_INFO . MEM_ERR_OVF
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_ERR_OVF(x)  VTSS_ENCODE_BITFIELD(!!(x),29,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_ERR_OVF  VTSS_BIT(29)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_ERR_OVF(x)  VTSS_EXTRACT_BITFIELD(x,29,1)

/** 
 * \brief
 * This field is set if the monitor has correction indication for which the
 * address has not been recorded.
 * If DEVCPU_GCB::MEMITGR_INFO.MEM_ERR is set then there has also been a
 * parity indication (or an unrecoverable correction) which takes priority
 * over correction indications.
 * If DEVCPU_GCB::MEMITGR_INFO.MEM_ERR is cleared and
 * DEVCPU_GCB::MEMITGR_INFO.MEM_COR is set then there has been more than
 * one correction indication, then only the address of the newest
 * correction indication has been kept.
 * If DEVCPU_GCB::MEMITGR_INFO.MEM_ERR and DEVCPU_GCB::MEMITGR_INFO.MEM_COR
 * is both cleared then a correction indication has occurred for which the
 * address could not be stored, this is a very rare situation that can only
 * happen if an indication is detected just as the memory is talking to the
 * monitor.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_INFO . MEM_COR_OVF
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_COR_OVF(x)  VTSS_ENCODE_BITFIELD(!!(x),28,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_COR_OVF  VTSS_BIT(28)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_COR_OVF(x)  VTSS_EXTRACT_BITFIELD(x,28,1)

/** 
 * \brief
 * This field is valid only when DEVCPU_GCB::MEMITGR_INFO.MEM_ERR or
 * DEVCPU_GCB::MEMITGR_INFO.MEM_COR is set.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_INFO . MEM_ADDR
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_ADDR(x)  VTSS_ENCODE_BITFIELD(x,0,28)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_ADDR     VTSS_ENCODE_BITMASK(0,28)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_ADDR(x)  VTSS_EXTRACT_BITFIELD(x,0,28)


/** 
 * \brief Memory index
 *
 * \details
 * This field is only valid when the monitor is in the DETECT
 * (DEVCPU_GCB::MEMITGR_STAT.MODE_DETECT is set) mode.
 *
 * Register: \a DEVCPU_GCB:MEMITGR:MEMITGR_IDX
 */
#define VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_IDX  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x87)

/** 
 * \brief
 * This field contains a unique index for the memory for which info is
 * currently provided in DEVCPU_GCB::MEMITGR_INFO. Indexes are counted from
 * 1 (not 0).
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_IDX . MEM_IDX
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_IDX_MEM_IDX(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_IDX_MEM_IDX     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_IDX_MEM_IDX(x)  VTSS_EXTRACT_BITFIELD(x,0,16)


/** 
 * \brief Monitor speed
 *
 * \details
 * Register: \a DEVCPU_GCB:MEMITGR:MEMITGR_DIV
 */
#define VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_DIV  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x88)

/** 
 * \brief
 * Configure divider for generating the sync-pulse to memories (controls
 * the speed at which the monitor talks to the memories). The lower this is
 * set the faster indications can be read out of the memories.
 *
 * \details 
 * See datasheet for appropriate value.
 *
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_DIV . MEM_DIV
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_DIV_MEM_DIV(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_DIV_MEM_DIV     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_DIV_MEM_DIV(x)  VTSS_EXTRACT_BITFIELD(x,0,16)


/** 
 * \brief Debug registers
 *
 * \details
 * Register: \a DEVCPU_GCB:MEMITGR:MEMITGR_DBG
 */
#define VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_DBG  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x89)

/** 
 * \brief
 * This field is used for test purposes.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_DBG . MEM_DIV_SENSE
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_MEM_DIV_SENSE(x)  VTSS_ENCODE_BITFIELD(!!(x),9,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_MEM_DIV_SENSE  VTSS_BIT(9)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_MEM_DIV_SENSE(x)  VTSS_EXTRACT_BITFIELD(x,9,1)

/** 
 * \brief
 * Set to force the intr-field of the intgrity-ring out from the monitor.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_DBG . FORCE_INTR
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_FORCE_INTR(x)  VTSS_ENCODE_BITFIELD(!!(x),8,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_FORCE_INTR  VTSS_BIT(8)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_FORCE_INTR(x)  VTSS_EXTRACT_BITFIELD(x,8,1)

/** 
 * \brief
 * Always shows the (resynced) value of the sync-field of the
 * integrity-ring into the monitor.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_DBG . SYNC_IN
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_SYNC_IN(x)  VTSS_ENCODE_BITFIELD(!!(x),7,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_SYNC_IN  VTSS_BIT(7)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_SYNC_IN(x)  VTSS_EXTRACT_BITFIELD(x,7,1)

/** 
 * \brief
 * Always shows the (resynced) value of the ena-field of the integrity-ring
 * into the monitor.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_DBG . ENA_IN
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_ENA_IN(x)  VTSS_ENCODE_BITFIELD(!!(x),6,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_ENA_IN  VTSS_BIT(6)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_ENA_IN(x)  VTSS_EXTRACT_BITFIELD(x,6,1)

/** 
 * \brief
 * Always shows the (resynced) value of the data-field of the
 * integrity-ring into the monitor.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_DBG . DATA_IN
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_DATA_IN(x)  VTSS_ENCODE_BITFIELD(!!(x),5,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_DATA_IN  VTSS_BIT(5)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_DATA_IN(x)  VTSS_EXTRACT_BITFIELD(x,5,1)

/** 
 * \brief
 * Always shows the (resynced) value of the intr-field of the
 * integrity-ring into the monitor.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_DBG . INTR_IN
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_INTR_IN(x)  VTSS_ENCODE_BITFIELD(!!(x),4,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_INTR_IN  VTSS_BIT(4)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_INTR_IN(x)  VTSS_EXTRACT_BITFIELD(x,4,1)

/** 
 * \brief
 * When DEVCPU_GCB::MEMITGR_DBG.FORCE_ENA is set, this value is driven to
 * sync-field of the intgrity-ring out from the monitor.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_DBG . SYNC_OUT
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_SYNC_OUT(x)  VTSS_ENCODE_BITFIELD(!!(x),3,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_SYNC_OUT  VTSS_BIT(3)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_SYNC_OUT(x)  VTSS_EXTRACT_BITFIELD(x,3,1)

/** 
 * \brief
 * When DEVCPU_GCB::MEMITGR_DBG.FORCE_ENA is set, this value is driven to
 * ena-field of the intgrity-ring out from the monitor.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_DBG . ENA_OUT
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_ENA_OUT(x)  VTSS_ENCODE_BITFIELD(!!(x),2,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_ENA_OUT  VTSS_BIT(2)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_ENA_OUT(x)  VTSS_EXTRACT_BITFIELD(x,2,1)

/** 
 * \brief
 * Set to overtake ena and sync outputs (bit banging on the integrity ring)
 * and drive these by DEVCPU_GCB::MEMITGR_DBG.ENA_OUT and
 * DEVCPU_GCB::MEMITGR_DBG.SYNC_OUT respectively.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_DBG . FORCE_ENA
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_FORCE_ENA(x)  VTSS_ENCODE_BITFIELD(!!(x),1,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_FORCE_ENA  VTSS_BIT(1)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_FORCE_ENA(x)  VTSS_EXTRACT_BITFIELD(x,1,1)

/** 
 * \brief
 * Set this field to enable detection of parity detections and ecc
 * corrections.
 * The monitor must be initialized before first use (after reset), this is
 * done by making the first transtion from IDLE to LISTEN mode without
 * enabeling detections (this field is cleared) and then setting this field
 * once the monitor reaches the LISTEN mode.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_DBG . DETECT_ENA
 */
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_DETECT_ENA(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_DETECT_ENA  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_DBG_DETECT_ENA(x)  VTSS_EXTRACT_BITFIELD(x,0,1)

/**
 * Register Group: \a DEVCPU_GCB:VRAP
 *
 * VRAP controller
 */


/** 
 * \brief VRAP events
 *
 * \details
 * Register: \a DEVCPU_GCB:VRAP:VRAP_ACCESS_STAT
 */
#define VTSS_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x8a)

/** 
 * \brief
 * This field is set if a valid VRAP frame has been received.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT . FRM_RECV_STICKY
 */
#define  VTSS_F_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT_FRM_RECV_STICKY(x)  VTSS_ENCODE_BITFIELD(!!(x),3,1)
#define  VTSS_M_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT_FRM_RECV_STICKY  VTSS_BIT(3)
#define  VTSS_X_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT_FRM_RECV_STICKY(x)  VTSS_EXTRACT_BITFIELD(x,3,1)

/** 
 * \brief
 * This field is set if an invalid command inside a valid VRAP frame has
 * been received. The VRAP engine has ignored the command.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT . CMD_INVALID_STICKY
 */
#define  VTSS_F_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT_CMD_INVALID_STICKY(x)  VTSS_ENCODE_BITFIELD(!!(x),2,1)
#define  VTSS_M_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT_CMD_INVALID_STICKY  VTSS_BIT(2)
#define  VTSS_X_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT_CMD_INVALID_STICKY(x)  VTSS_EXTRACT_BITFIELD(x,2,1)

/** 
 * \brief
 * This field is set if an invalid VRAP frame has been received and
 * discarded by the VRAP-engine. Frames with a VRAP header different from
 * V1 are considered invalid.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT . FRM_INVALID_STICKY
 */
#define  VTSS_F_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT_FRM_INVALID_STICKY(x)  VTSS_ENCODE_BITFIELD(!!(x),1,1)
#define  VTSS_M_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT_FRM_INVALID_STICKY  VTSS_BIT(1)
#define  VTSS_X_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT_FRM_INVALID_STICKY(x)  VTSS_EXTRACT_BITFIELD(x,1,1)

/** 
 * \brief
 * This field is set if a VRAP reply frame has been aborted. This my happen
 * if a protocol violation is detected during VRAP request frame
 * processing.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT . REPLY_ABORT_STICKY
 */
#define  VTSS_F_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT_REPLY_ABORT_STICKY(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT_REPLY_ABORT_STICKY  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_GCB_VRAP_VRAP_ACCESS_STAT_REPLY_ABORT_STICKY(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


#endif /* _VTSS_OCELOT_REGS_DEVCPU_GCB_H_ */
