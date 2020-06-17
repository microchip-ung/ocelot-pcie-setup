#ifndef _VTSS_OCELOT_REGS_DEVCPU_PTP_H_
#define _VTSS_OCELOT_REGS_DEVCPU_PTP_H_

//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT

#include "vtss_ocelot_regs_common.h"

/*********************************************************************** 
 *
 * Target: \a DEVCPU_PTP
 *
 * DEVCPU Precision Timing Protocol Originator
 *
 ***********************************************************************/

/**
 * Register Group: \a DEVCPU_PTP:PTP_CFG
 *
 * PTP controller configuration and status
 */


/** 
 * \brief Misc PTP configurations
 *
 * \details
 * Register: \a DEVCPU_PTP:PTP_CFG:PTP_MISC_CFG
 */
#define VTSS_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x28)

/** 
 * \brief
 * Enable master counter.
 *
 * \details 
 * 0: Master counter disabled and reset
 * 1: Master counter enabled
 *
 * Field: ::VTSS_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG . PTP_ENA
 */
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG_PTP_ENA(x)  VTSS_ENCODE_BITFIELD(!!(x),2,1)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG_PTP_ENA  VTSS_BIT(2)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG_PTP_ENA(x)  VTSS_EXTRACT_BITFIELD(x,2,1)

/** 
 * \brief
 * Hold master counter.
 *
 * \details 
 * 0: Master counter counts if enabled
 * 1: Master counter will stay at the reached value
 *
 * Field: ::VTSS_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG . PTP_HOLD
 */
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG_PTP_HOLD(x)  VTSS_ENCODE_BITFIELD(!!(x),1,1)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG_PTP_HOLD  VTSS_BIT(1)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG_PTP_HOLD(x)  VTSS_EXTRACT_BITFIELD(x,1,1)

/** 
 * \brief
 * The PTP_CUR timers will be frozen when this field is set for a domain,
 * in order to return concurrent values.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG . PTP_TOD_FREEZE
 */
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG_PTP_TOD_FREEZE(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG_PTP_TOD_FREEZE  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG_PTP_TOD_FREEZE(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


/** 
 * \brief Generated clock adjustment configuration
 *
 * \details
 * One replication exsists per time domain
 *
 * Register: \a DEVCPU_PTP:PTP_CFG:CLK_ADJ_CFG
 */
#define VTSS_DEVCPU_PTP_PTP_CFG_CLK_ADJ_CFG  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x29)

/** 
 * \brief
 * Clock frequency adjustment direction.
 *
 * \details 
 * 0: Positive adjustment. Every adjustment adds 1ns to the counter. =>
 * clock period is decreased, clock frequency is increased
 * 1: Negative adjustment. Every adjustment subtracts 1ns from the counter.
 * => clock period is increased, clock frequency is decreased
 *
 * Field: ::VTSS_DEVCPU_PTP_PTP_CFG_CLK_ADJ_CFG . CLK_ADJ_DIR
 */
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_CLK_ADJ_CFG_CLK_ADJ_DIR(x)  VTSS_ENCODE_BITFIELD(!!(x),1,1)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_CLK_ADJ_CFG_CLK_ADJ_DIR  VTSS_BIT(1)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_CLK_ADJ_CFG_CLK_ADJ_DIR(x)  VTSS_EXTRACT_BITFIELD(x,1,1)

/** 
 * \brief
 * Clock frequency adjust enable.
 *
 * \details 
 * 0: Adjustment Disabled
 * 1: Adjustment Enabled
 *
 * Field: ::VTSS_DEVCPU_PTP_PTP_CFG_CLK_ADJ_CFG . CLK_ADJ_ENA
 */
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_CLK_ADJ_CFG_CLK_ADJ_ENA(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_CLK_ADJ_CFG_CLK_ADJ_ENA  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_CLK_ADJ_CFG_CLK_ADJ_ENA(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


/** 
 * \brief Generated clock frequency adjustment
 *
 * \details
 * Adjust master timer acording to detected PPB error. Ex: 1PBB: Adjust
 * every 1ns. 50.006PBB: Adjust every 19.997.600ps
 *
 * Register: \a DEVCPU_PTP:PTP_CFG:CLK_ADJ_FRQ
 */
#define VTSS_DEVCPU_PTP_PTP_CFG_CLK_ADJ_FRQ  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x2a)

/** 
 * \brief
 * Clock frequency adjust unit./
 *
 * \details 
 * 0: Adjustment made every CLK_ADJ picoseconds.1: Adjustment made every
 * CLK_ADJ nanoseconds.
 *
 * Field: ::VTSS_DEVCPU_PTP_PTP_CFG_CLK_ADJ_FRQ . CLK_ADJ_UNIT
 */
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_CLK_ADJ_FRQ_CLK_ADJ_UNIT(x)  VTSS_ENCODE_BITFIELD(!!(x),30,1)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_CLK_ADJ_FRQ_CLK_ADJ_UNIT  VTSS_BIT(30)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_CLK_ADJ_FRQ_CLK_ADJ_UNIT(x)  VTSS_EXTRACT_BITFIELD(x,30,1)

/** 
 * \brief
 * Clock frequency adjust./
 *
 * \details 
 * N: Number of unadjusted CLK_ADJ_UNIT after which the counter for the
 * clock must be adjusted.
 *
 * Field: ::VTSS_DEVCPU_PTP_PTP_CFG_CLK_ADJ_FRQ . CLK_ADJ
 */
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_CLK_ADJ_FRQ_CLK_ADJ(x)  VTSS_ENCODE_BITFIELD(x,0,30)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_CLK_ADJ_FRQ_CLK_ADJ     VTSS_ENCODE_BITMASK(0,30)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_CLK_ADJ_FRQ_CLK_ADJ(x)  VTSS_EXTRACT_BITFIELD(x,0,30)


/** 
 * \brief Pending interrupt mask
 *
 * \details
 * Register: \a DEVCPU_PTP:PTP_CFG:PTP_PIN_INTR
 */
#define VTSS_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x2b)

/** 
 * \brief
 * One bit per pin set when an active edge is seen.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR . INTR_PTP
 */
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR_INTR_PTP(x)  VTSS_ENCODE_BITFIELD(x,0,5)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR_INTR_PTP     VTSS_ENCODE_BITMASK(0,5)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR_INTR_PTP(x)  VTSS_EXTRACT_BITFIELD(x,0,5)


/** 
 * \brief Enable interrupts per pin
 *
 * \details
 * Register: \a DEVCPU_PTP:PTP_CFG:PTP_PIN_INTR_ENA
 */
#define VTSS_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR_ENA  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x2c)

/** 
 * \brief
 * Enable interrupt per ptp pin.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR_ENA . INTR_PTP_ENA
 */
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR_ENA_INTR_PTP_ENA(x)  VTSS_ENCODE_BITFIELD(x,0,5)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR_ENA_INTR_PTP_ENA     VTSS_ENCODE_BITMASK(0,5)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR_ENA_INTR_PTP_ENA(x)  VTSS_EXTRACT_BITFIELD(x,0,5)


/** 
 * \brief Current interrupt status
 *
 * \details
 * Register: \a DEVCPU_PTP:PTP_CFG:PTP_INTR_IDENT
 */
#define VTSS_DEVCPU_PTP_PTP_CFG_PTP_INTR_IDENT  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x2d)

/** 
 * \brief
 * Bit n will be high if an interrupt is currently pending for pin <n>.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_CFG_PTP_INTR_IDENT . INTR_PTP_IDENT
 */
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_PTP_INTR_IDENT_INTR_PTP_IDENT(x)  VTSS_ENCODE_BITFIELD(x,0,5)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_PTP_INTR_IDENT_INTR_PTP_IDENT     VTSS_ENCODE_BITMASK(0,5)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_PTP_INTR_IDENT_INTR_PTP_IDENT(x)  VTSS_EXTRACT_BITFIELD(x,0,5)


/** 
 * \brief System clock configuration
 *
 * \details
 * Register: \a DEVCPU_PTP:PTP_CFG:PTP_SYS_CLK_CFG
 */
#define VTSS_DEVCPU_PTP_PTP_CFG_PTP_SYS_CLK_CFG  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x2e)

/** 
 * \brief
 * Must be configured to running system clock period, rounded down to
 * closest interger nanoseconds value.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_CFG_PTP_SYS_CLK_CFG . PTP_SYS_CLK_PER_NS
 */
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_PTP_SYS_CLK_CFG_PTP_SYS_CLK_PER_NS(x)  VTSS_ENCODE_BITFIELD(x,4,5)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_PTP_SYS_CLK_CFG_PTP_SYS_CLK_PER_NS     VTSS_ENCODE_BITMASK(4,5)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_PTP_SYS_CLK_CFG_PTP_SYS_CLK_PER_NS(x)  VTSS_EXTRACT_BITFIELD(x,4,5)

/** 
 * \brief
 * Must be configured to number of 100ps to add on top of the
 * PTP_SYS_CLK_PER_NS value to get to the correct clock period.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_CFG_PTP_SYS_CLK_CFG . PTP_SYS_CLK_PER_PS100
 */
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_PTP_SYS_CLK_CFG_PTP_SYS_CLK_PER_PS100(x)  VTSS_ENCODE_BITFIELD(x,0,4)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_PTP_SYS_CLK_CFG_PTP_SYS_CLK_PER_PS100     VTSS_ENCODE_BITMASK(0,4)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_PTP_SYS_CLK_CFG_PTP_SYS_CLK_PER_PS100(x)  VTSS_EXTRACT_BITFIELD(x,0,4)

/**
 * Register Group: \a DEVCPU_PTP:PTP_STATUS
 *
 * Status of PTP timers
 */


/** 
 * \brief Current timestamping value
 *
 * \details
 * Register: \a DEVCPU_PTP:PTP_STATUS:PTP_CUR_NSF
 */
#define VTSS_DEVCPU_PTP_PTP_STATUS_PTP_CUR_NSF  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x2f)

/** 
 * \brief
 * Returns the current value of the timestamping clock. The time of day
 * registers will be latched when this register is read.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_STATUS_PTP_CUR_NSF . PTP_CUR_NSF
 */
#define  VTSS_F_DEVCPU_PTP_PTP_STATUS_PTP_CUR_NSF_PTP_CUR_NSF(x)  (x)
#define  VTSS_M_DEVCPU_PTP_PTP_STATUS_PTP_CUR_NSF_PTP_CUR_NSF     0xffffffff
#define  VTSS_X_DEVCPU_PTP_PTP_STATUS_PTP_CUR_NSF_PTP_CUR_NSF(x)  (x)


/** 
 * \brief Current time of day
 *
 * \details
 * Current time of day, nanoseconds part. 
 *
 * Register: \a DEVCPU_PTP:PTP_STATUS:PTP_CUR_NSEC
 */
#define VTSS_DEVCPU_PTP_PTP_STATUS_PTP_CUR_NSEC  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x30)

/** 
 * \brief
 * Time of day naoseconds, latched when NSF was read.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_STATUS_PTP_CUR_NSEC . PTP_CUR_NSEC
 */
#define  VTSS_F_DEVCPU_PTP_PTP_STATUS_PTP_CUR_NSEC_PTP_CUR_NSEC(x)  VTSS_ENCODE_BITFIELD(x,0,30)
#define  VTSS_M_DEVCPU_PTP_PTP_STATUS_PTP_CUR_NSEC_PTP_CUR_NSEC     VTSS_ENCODE_BITMASK(0,30)
#define  VTSS_X_DEVCPU_PTP_PTP_STATUS_PTP_CUR_NSEC_PTP_CUR_NSEC(x)  VTSS_EXTRACT_BITFIELD(x,0,30)


/** 
 * \brief Current time of day
 *
 * \details
 * Register: \a DEVCPU_PTP:PTP_STATUS:PTP_CUR_SEC_LSB
 */
#define VTSS_DEVCPU_PTP_PTP_STATUS_PTP_CUR_SEC_LSB  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x31)

/** 
 * \brief
 * Value of current tod secs, latched when NSF was read.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_STATUS_PTP_CUR_SEC_LSB . PTP_CUR_SEC_LSB
 */
#define  VTSS_F_DEVCPU_PTP_PTP_STATUS_PTP_CUR_SEC_LSB_PTP_CUR_SEC_LSB(x)  (x)
#define  VTSS_M_DEVCPU_PTP_PTP_STATUS_PTP_CUR_SEC_LSB_PTP_CUR_SEC_LSB     0xffffffff
#define  VTSS_X_DEVCPU_PTP_PTP_STATUS_PTP_CUR_SEC_LSB_PTP_CUR_SEC_LSB(x)  (x)


/** 
 * \brief Current time of day
 *
 * \details
 * Register: \a DEVCPU_PTP:PTP_STATUS:PTP_CUR_SEC_MSB
 */
#define VTSS_DEVCPU_PTP_PTP_STATUS_PTP_CUR_SEC_MSB  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x32)

/** 
 * \brief
 * Current time of day, seconds part, latched when NSF was read
 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_STATUS_PTP_CUR_SEC_MSB . PTP_CUR_SEC_MSB
 */
#define  VTSS_F_DEVCPU_PTP_PTP_STATUS_PTP_CUR_SEC_MSB_PTP_CUR_SEC_MSB(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_DEVCPU_PTP_PTP_STATUS_PTP_CUR_SEC_MSB_PTP_CUR_SEC_MSB     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_DEVCPU_PTP_PTP_STATUS_PTP_CUR_SEC_MSB_PTP_CUR_SEC_MSB(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

/**
 * Register Group: \a DEVCPU_PTP:PTP_PINS
 *
 * Timing synchronization
 */


/** 
 * \brief Configuration of use of the register group
 *
 * \details
 * Select use of the ptp i/o pin. Ptp pin 4 is not attached to any physical
 * I/O.
 *
 * Register: \a DEVCPU_PTP:PTP_PINS:PTP_PIN_CFG
 *
 * @param gi Replicator: x_FFL_DEVCPU_PTP_NUM_LS_IFS (??), 0-4
 */
#define VTSS_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_PTP,0x0,gi,8,0,0)

/** 
 * \brief
 * Defined actions are: 
 *   IDLE: No operation 
 *   LOAD:   Load TimeOfDay with configured values
 *   STORE:  Store TimeOfDay and NSF of selected time domain
 *   CLOCK:  Generate a clock output
 *   DELTA:  Add PTP_TOD_NSEC field as a signed integer to TimeOfDay
 * 
 * When the sync option is set, the action will be done when the pin sees
 * an active edge.
 * The action will automatically return to IDLE when complete.

 *
 * \details 
 * 0: IDLE
 * 1: LOAD
 * 2: STORE
 * 3: CLOCK
 * 4: DELTA
 * 5-7: reserved

 *
 * Field: ::VTSS_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG . PTP_PIN_ACTION
 */
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_ACTION(x)  VTSS_ENCODE_BITFIELD(x,3,3)
#define  VTSS_M_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_ACTION     VTSS_ENCODE_BITMASK(3,3)
#define  VTSS_X_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_ACTION(x)  VTSS_EXTRACT_BITFIELD(x,3,3)

/** 
 * \brief
 * For LOAD/STORE/DELTA actions, setting this option will suspend the
 * action until an active edge is seen on the pin. Otherwise it will be
 * done immediately.
 * For the CLOCK action, the sync option makes the pin generate a single
 * pulse, <WAFEFORM_LOW> nanoseconds after the time of day has increased
 * the seconds. The pulse will get a width of <WAVEFORM_HIGH> nanoseconds.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG . PTP_PIN_SYNC
 */
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_SYNC(x)  VTSS_ENCODE_BITFIELD(!!(x),2,1)
#define  VTSS_M_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_SYNC  VTSS_BIT(2)
#define  VTSS_X_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_SYNC(x)  VTSS_EXTRACT_BITFIELD(x,2,1)

/** 
 * \brief
 * Polarity of the PTP pin. 
 *
 * \details 
 * 0: Active high
 * 1: Active low

 *
 * Field: ::VTSS_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG . PTP_PIN_INV_POL
 */
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_INV_POL(x)  VTSS_ENCODE_BITFIELD(!!(x),1,1)
#define  VTSS_M_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_INV_POL  VTSS_BIT(1)
#define  VTSS_X_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_INV_POL(x)  VTSS_EXTRACT_BITFIELD(x,1,1)

/** 
 * \brief
 * Configures the time domain the pin is connected to.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG . PTP_PIN_DOM
 */
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_DOM(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_DOM  VTSS_BIT(0)
#define  VTSS_X_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_DOM(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


/** 
 * \brief Time Of Day MSB
 *
 * \details
 * Register: \a DEVCPU_PTP:PTP_PINS:PTP_TOD_SEC_MSB
 *
 * @param gi Replicator: x_FFL_DEVCPU_PTP_NUM_LS_IFS (??), 0-4
 */
#define VTSS_DEVCPU_PTP_PTP_PINS_PTP_TOD_SEC_MSB(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_PTP,0x0,gi,8,0,1)

/** 
 * \brief
 * Bits 47:32 of the time-of-day seconds
 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_PINS_PTP_TOD_SEC_MSB . PTP_TOD_SEC_MSB
 */
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PTP_TOD_SEC_MSB_PTP_TOD_SEC_MSB(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_DEVCPU_PTP_PTP_PINS_PTP_TOD_SEC_MSB_PTP_TOD_SEC_MSB     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_DEVCPU_PTP_PTP_PINS_PTP_TOD_SEC_MSB_PTP_TOD_SEC_MSB(x)  VTSS_EXTRACT_BITFIELD(x,0,16)


/** 
 * \brief Time Of Day LSB
 *
 * \details
 * Register: \a DEVCPU_PTP:PTP_PINS:PTP_TOD_SEC_LSB
 *
 * @param gi Replicator: x_FFL_DEVCPU_PTP_NUM_LS_IFS (??), 0-4
 */
#define VTSS_DEVCPU_PTP_PTP_PINS_PTP_TOD_SEC_LSB(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_PTP,0x0,gi,8,0,2)

/** 
 * \brief
 * Bits 31:0 of the time-of-day seconds
 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_PINS_PTP_TOD_SEC_LSB . PTP_TOD_SEC_LSB
 */
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PTP_TOD_SEC_LSB_PTP_TOD_SEC_LSB(x)  (x)
#define  VTSS_M_DEVCPU_PTP_PTP_PINS_PTP_TOD_SEC_LSB_PTP_TOD_SEC_LSB     0xffffffff
#define  VTSS_X_DEVCPU_PTP_PTP_PINS_PTP_TOD_SEC_LSB_PTP_TOD_SEC_LSB(x)  (x)


/** 
 * \brief Time Of Day nanosecs part
 *
 * \details
 * Register: \a DEVCPU_PTP:PTP_PINS:PTP_TOD_NSEC
 *
 * @param gi Replicator: x_FFL_DEVCPU_PTP_NUM_LS_IFS (??), 0-4
 */
#define VTSS_DEVCPU_PTP_PTP_PINS_PTP_TOD_NSEC(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_PTP,0x0,gi,8,0,3)

/** 
 * \brief
 * Time Of Day nanoseconds loaded or stored into TimeOfDay. A synced store
 * operation may return a value between -2 and 999.999.999 in this field.
 * To normalize the complete TOD, in case field is read 0x3ffffffe/f,
 * software must subtract one from the SEC part, and add 1.000.000.000 to
 * the NSEC part.
 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_PINS_PTP_TOD_NSEC . PTP_TOD_NSEC
 */
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PTP_TOD_NSEC_PTP_TOD_NSEC(x)  VTSS_ENCODE_BITFIELD(x,0,30)
#define  VTSS_M_DEVCPU_PTP_PTP_PINS_PTP_TOD_NSEC_PTP_TOD_NSEC     VTSS_ENCODE_BITMASK(0,30)
#define  VTSS_X_DEVCPU_PTP_PTP_PINS_PTP_TOD_NSEC_PTP_TOD_NSEC(x)  VTSS_EXTRACT_BITFIELD(x,0,30)


/** 
 * \brief Stamper clock
 *
 * \details
 * Register: \a DEVCPU_PTP:PTP_PINS:PTP_NSF
 *
 * @param gi Replicator: x_FFL_DEVCPU_PTP_NUM_LS_IFS (??), 0-4
 */
#define VTSS_DEVCPU_PTP_PTP_PINS_PTP_NSF(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_PTP,0x0,gi,8,0,4)

/** 
 * \brief
 * Value of NSF counter when load/save action was executed. This value will
 * not be loaded into the timers upon a LOAD operation. 

 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_PINS_PTP_NSF . PTP_NSF
 */
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PTP_NSF_PTP_NSF(x)  (x)
#define  VTSS_M_DEVCPU_PTP_PTP_PINS_PTP_NSF_PTP_NSF     0xffffffff
#define  VTSS_X_DEVCPU_PTP_PTP_PINS_PTP_NSF_PTP_NSF(x)  (x)


/** 
 * \brief Waveform programming
 *
 * \details
 * Register: \a DEVCPU_PTP:PTP_PINS:PIN_WF_HIGH_PERIOD
 *
 * @param gi Replicator: x_FFL_DEVCPU_PTP_NUM_LS_IFS (??), 0-4
 */
#define VTSS_DEVCPU_PTP_PTP_PINS_PIN_WF_HIGH_PERIOD(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_PTP,0x0,gi,8,0,5)

/** 
 * \brief
 * Configure waveform. Unit is nanoseconds.
 * EX. 25MHz 60/40 clock:
 *   PIN_ACTION=CLOCK, PIN_SYNC=0, PIN_WFH=24, PIN_WFL=16
 * EX. 1 us pulse after 150 ns
 *   PIN_ACTION=CLOCK, PIN_SYNC=1, PIN_WFH=1000, PIN_WFL=150

 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_PINS_PIN_WF_HIGH_PERIOD . PIN_WFH
 */
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PIN_WF_HIGH_PERIOD_PIN_WFH(x)  VTSS_ENCODE_BITFIELD(x,0,30)
#define  VTSS_M_DEVCPU_PTP_PTP_PINS_PIN_WF_HIGH_PERIOD_PIN_WFH     VTSS_ENCODE_BITMASK(0,30)
#define  VTSS_X_DEVCPU_PTP_PTP_PINS_PIN_WF_HIGH_PERIOD_PIN_WFH(x)  VTSS_EXTRACT_BITFIELD(x,0,30)


/** 
 * \brief Waveform programming
 *
 * \details
 * Register: \a DEVCPU_PTP:PTP_PINS:PIN_WF_LOW_PERIOD
 *
 * @param gi Replicator: x_FFL_DEVCPU_PTP_NUM_LS_IFS (??), 0-4
 */
#define VTSS_DEVCPU_PTP_PTP_PINS_PIN_WF_LOW_PERIOD(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_PTP,0x0,gi,8,0,6)

/** 
 * \brief
 * Configure waveform
 *
 * \details 
 * Field: ::VTSS_DEVCPU_PTP_PTP_PINS_PIN_WF_LOW_PERIOD . PIN_WFL
 */
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PIN_WF_LOW_PERIOD_PIN_WFL(x)  VTSS_ENCODE_BITFIELD(x,0,30)
#define  VTSS_M_DEVCPU_PTP_PTP_PINS_PIN_WF_LOW_PERIOD_PIN_WFL     VTSS_ENCODE_BITMASK(0,30)
#define  VTSS_X_DEVCPU_PTP_PTP_PINS_PIN_WF_LOW_PERIOD_PIN_WFL(x)  VTSS_EXTRACT_BITFIELD(x,0,30)


#endif /* _VTSS_OCELOT_REGS_DEVCPU_PTP_H_ */
