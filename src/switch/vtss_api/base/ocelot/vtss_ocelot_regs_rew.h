#ifndef _VTSS_OCELOT_REGS_REW_H_
#define _VTSS_OCELOT_REGS_REW_H_

//Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
//SPDX-License-Identifier: MIT

#include "vtss_ocelot_regs_common.h"

/*********************************************************************** 
 *
 * Target: \a REW
 *
 * Rewriter Configuration
 *
 ***********************************************************************/

/**
 * Register Group: \a REW:PORT
 *
 * Per port configurations for Rewriter
 */


/** 
 * \brief Port VLAN configuration
 *
 * \details
 * Register: \a REW:PORT:PORT_VLAN_CFG
 *
 * @param gi Replicator: x_DPORT_CNT (??), 0-12
 */
#define VTSS_REW_PORT_PORT_VLAN_CFG(gi)      VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,0,0)

/** 
 * \brief
 * Tag Protocol Identifier for port.
 *
 * \details 
 * Field: ::VTSS_REW_PORT_PORT_VLAN_CFG . PORT_TPID
 */
#define  VTSS_F_REW_PORT_PORT_VLAN_CFG_PORT_TPID(x)  VTSS_ENCODE_BITFIELD(x,16,16)
#define  VTSS_M_REW_PORT_PORT_VLAN_CFG_PORT_TPID     VTSS_ENCODE_BITMASK(16,16)
#define  VTSS_X_REW_PORT_PORT_VLAN_CFG_PORT_TPID(x)  VTSS_EXTRACT_BITFIELD(x,16,16)

/** 
 * \brief
 * DEI value for port.
 *
 * \details 
 * Field: ::VTSS_REW_PORT_PORT_VLAN_CFG . PORT_DEI
 */
#define  VTSS_F_REW_PORT_PORT_VLAN_CFG_PORT_DEI(x)  VTSS_ENCODE_BITFIELD(!!(x),15,1)
#define  VTSS_M_REW_PORT_PORT_VLAN_CFG_PORT_DEI  VTSS_BIT(15)
#define  VTSS_X_REW_PORT_PORT_VLAN_CFG_PORT_DEI(x)  VTSS_EXTRACT_BITFIELD(x,15,1)

/** 
 * \brief
 * PCP value for port.
 *
 * \details 
 * Field: ::VTSS_REW_PORT_PORT_VLAN_CFG . PORT_PCP
 */
#define  VTSS_F_REW_PORT_PORT_VLAN_CFG_PORT_PCP(x)  VTSS_ENCODE_BITFIELD(x,12,3)
#define  VTSS_M_REW_PORT_PORT_VLAN_CFG_PORT_PCP     VTSS_ENCODE_BITMASK(12,3)
#define  VTSS_X_REW_PORT_PORT_VLAN_CFG_PORT_PCP(x)  VTSS_EXTRACT_BITFIELD(x,12,3)

/** 
 * \brief
 * VID value for port.
 *
 * \details 
 * Field: ::VTSS_REW_PORT_PORT_VLAN_CFG . PORT_VID
 */
#define  VTSS_F_REW_PORT_PORT_VLAN_CFG_PORT_VID(x)  VTSS_ENCODE_BITFIELD(x,0,12)
#define  VTSS_M_REW_PORT_PORT_VLAN_CFG_PORT_VID     VTSS_ENCODE_BITMASK(0,12)
#define  VTSS_X_REW_PORT_PORT_VLAN_CFG_PORT_VID(x)  VTSS_EXTRACT_BITFIELD(x,0,12)


/** 
 * \brief Tagging configuration
 *
 * \details
 * Register: \a REW:PORT:TAG_CFG
 *
 * @param gi Replicator: x_DPORT_CNT (??), 0-12
 */
#define VTSS_REW_PORT_TAG_CFG(gi)            VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,0,1)

/** 
 * \brief
 * Enable VLAN port tagging.
 *
 * \details 
 * 0: Port tagging disabled.
 * 1: Tag all frames, except when VID=PORT_VLAN_CFG.PORT_VID or VID=0.
 * 2: Tag all frames, except when VID=0.
 * 3: Tag all frames.

 *
 * Field: ::VTSS_REW_PORT_TAG_CFG . TAG_CFG
 */
#define  VTSS_F_REW_PORT_TAG_CFG_TAG_CFG(x)   VTSS_ENCODE_BITFIELD(x,7,2)
#define  VTSS_M_REW_PORT_TAG_CFG_TAG_CFG      VTSS_ENCODE_BITMASK(7,2)
#define  VTSS_X_REW_PORT_TAG_CFG_TAG_CFG(x)   VTSS_EXTRACT_BITFIELD(x,7,2)

/** 
 * \brief
 * Select TPID EtherType in port tag.
 *
 * \details 
 * 0: Use 0x8100.
 * 1: Use 0x88A8.
 * 2: Use custom value from PORT_VLAN_CFG.PORT_TPID.
 * 3: Use PORT_VLAN_CFG.PORT_TPID, unless ingress tag was a C-tag
 * (EtherType = 0x8100)

 *
 * Field: ::VTSS_REW_PORT_TAG_CFG . TAG_TPID_CFG
 */
#define  VTSS_F_REW_PORT_TAG_CFG_TAG_TPID_CFG(x)  VTSS_ENCODE_BITFIELD(x,5,2)
#define  VTSS_M_REW_PORT_TAG_CFG_TAG_TPID_CFG     VTSS_ENCODE_BITMASK(5,2)
#define  VTSS_X_REW_PORT_TAG_CFG_TAG_TPID_CFG(x)  VTSS_EXTRACT_BITFIELD(x,5,2)

/** 
 * \brief
 * Select VID in port tag.
 *
 * \details 
 * 0: Use classified VID.
 * 1: Use PORT_VLAN_CFG.PORT_VID.
 *
 * Field: ::VTSS_REW_PORT_TAG_CFG . TAG_VID_CFG
 */
#define  VTSS_F_REW_PORT_TAG_CFG_TAG_VID_CFG(x)  VTSS_ENCODE_BITFIELD(!!(x),4,1)
#define  VTSS_M_REW_PORT_TAG_CFG_TAG_VID_CFG  VTSS_BIT(4)
#define  VTSS_X_REW_PORT_TAG_CFG_TAG_VID_CFG(x)  VTSS_EXTRACT_BITFIELD(x,4,1)

/** 
 * \brief
 * Select PCP in port tag.
 *
 * \details 
 * 0: Classified PCP
 * 1: PORT_PCP
 * 2: DP and QoS mapped to PCP (PCP_DEI_QOS_MAP_CFG)
 * 3: QoS class

 *
 * Field: ::VTSS_REW_PORT_TAG_CFG . TAG_PCP_CFG
 */
#define  VTSS_F_REW_PORT_TAG_CFG_TAG_PCP_CFG(x)  VTSS_ENCODE_BITFIELD(x,2,2)
#define  VTSS_M_REW_PORT_TAG_CFG_TAG_PCP_CFG     VTSS_ENCODE_BITMASK(2,2)
#define  VTSS_X_REW_PORT_TAG_CFG_TAG_PCP_CFG(x)  VTSS_EXTRACT_BITFIELD(x,2,2)

/** 
 * \brief
 * Select DEI in port tag.
 *
 * \details 
 * 0: Classified DEI
 * 1: PORT_DEI
 * 2: DP and QoS mapped to DEI (PCP_DEI_QOS_MAP_CFG)
 * 3: DP level
 *
 * Field: ::VTSS_REW_PORT_TAG_CFG . TAG_DEI_CFG
 */
#define  VTSS_F_REW_PORT_TAG_CFG_TAG_DEI_CFG(x)  VTSS_ENCODE_BITFIELD(x,0,2)
#define  VTSS_M_REW_PORT_TAG_CFG_TAG_DEI_CFG     VTSS_ENCODE_BITMASK(0,2)
#define  VTSS_X_REW_PORT_TAG_CFG_TAG_DEI_CFG(x)  VTSS_EXTRACT_BITFIELD(x,0,2)


/** 
 * \brief Special port configuration
 *
 * \details
 * Register: \a REW:PORT:PORT_CFG
 *
 * @param gi Replicator: x_DPORT_CNT (??), 0-12
 */
#define VTSS_REW_PORT_PORT_CFG(gi)           VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,0,2)

/** 
 * \brief
 * Enable ES0 lookup.
 *
 * \details 
 * Field: ::VTSS_REW_PORT_PORT_CFG . ES0_ENA
 */
#define  VTSS_F_REW_PORT_PORT_CFG_ES0_ENA(x)  VTSS_ENCODE_BITFIELD(!!(x),5,1)
#define  VTSS_M_REW_PORT_PORT_CFG_ES0_ENA     VTSS_BIT(5)
#define  VTSS_X_REW_PORT_PORT_CFG_ES0_ENA(x)  VTSS_EXTRACT_BITFIELD(x,5,1)

/** 
 * \brief
 * FCS update mode for frames not received on the CPU port.
 *
 * \details 
 * 0: Update FCS if frame data has changed
 * 1: Never update FCS
 * 2: Always update FCS
 *
 * Field: ::VTSS_REW_PORT_PORT_CFG . FCS_UPDATE_NONCPU_CFG
 */
#define  VTSS_F_REW_PORT_PORT_CFG_FCS_UPDATE_NONCPU_CFG(x)  VTSS_ENCODE_BITFIELD(x,3,2)
#define  VTSS_M_REW_PORT_PORT_CFG_FCS_UPDATE_NONCPU_CFG     VTSS_ENCODE_BITMASK(3,2)
#define  VTSS_X_REW_PORT_PORT_CFG_FCS_UPDATE_NONCPU_CFG(x)  VTSS_EXTRACT_BITFIELD(x,3,2)

/** 
 * \brief
 * If set, update FCS for all frames injected by the CPU. If cleared, never
 * update the FCS.
 *
 * \details 
 * Field: ::VTSS_REW_PORT_PORT_CFG . FCS_UPDATE_CPU_ENA
 */
#define  VTSS_F_REW_PORT_PORT_CFG_FCS_UPDATE_CPU_ENA(x)  VTSS_ENCODE_BITFIELD(!!(x),2,1)
#define  VTSS_M_REW_PORT_PORT_CFG_FCS_UPDATE_CPU_ENA  VTSS_BIT(2)
#define  VTSS_X_REW_PORT_PORT_CFG_FCS_UPDATE_CPU_ENA(x)  VTSS_EXTRACT_BITFIELD(x,2,1)

/** 
 * \brief
 * If set, all frames destined for the egress port are discarded. 
 *
 * \details 
 * Field: ::VTSS_REW_PORT_PORT_CFG . FLUSH_ENA
 */
#define  VTSS_F_REW_PORT_PORT_CFG_FLUSH_ENA(x)  VTSS_ENCODE_BITFIELD(!!(x),1,1)
#define  VTSS_M_REW_PORT_PORT_CFG_FLUSH_ENA   VTSS_BIT(1)
#define  VTSS_X_REW_PORT_PORT_CFG_FLUSH_ENA(x)  VTSS_EXTRACT_BITFIELD(x,1,1)

/** 
 * \brief
 * Disable frame ageing for this egress port.
 *
 * \details 
 * Field: ::VTSS_REW_PORT_PORT_CFG . AGE_DIS
 */
#define  VTSS_F_REW_PORT_PORT_CFG_AGE_DIS(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_REW_PORT_PORT_CFG_AGE_DIS     VTSS_BIT(0)
#define  VTSS_X_REW_PORT_PORT_CFG_AGE_DIS(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


/** 
 * \brief DSCP updates
 *
 * \details
 * Register: \a REW:PORT:DSCP_CFG
 *
 * @param gi Replicator: x_DPORT_CNT (??), 0-12
 */
#define VTSS_REW_PORT_DSCP_CFG(gi)           VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,0,3)

/** 
 * \brief
 * Egress DSCP rewrite. 

 *
 * \details 
 * 0: No update of DSCP value in frame.
 * 1: Update with DSCP value from analyzer.
 * 2: Update with DSCP value from analyzer remapped through DSCP_REMAP_CFG.
 * 3. Update with DSCP value from analyzer remapped based on drop
 * precedence level through DSCP_REMAP_CFG or DSCP_REMAP_DP1_CFGl.
 *
 * Field: ::VTSS_REW_PORT_DSCP_CFG . DSCP_REWR_CFG
 */
#define  VTSS_F_REW_PORT_DSCP_CFG_DSCP_REWR_CFG(x)  VTSS_ENCODE_BITFIELD(x,0,2)
#define  VTSS_M_REW_PORT_DSCP_CFG_DSCP_REWR_CFG     VTSS_ENCODE_BITMASK(0,2)
#define  VTSS_X_REW_PORT_DSCP_CFG_DSCP_REWR_CFG(x)  VTSS_EXTRACT_BITFIELD(x,0,2)


/** 
 * \brief Mapping of DP level and QoS class to PCP and DEI values
 *
 * \details
 * Register: \a REW:PORT:PCP_DEI_QOS_MAP_CFG
 *
 * @param gi Replicator: x_DPORT_CNT (??), 0-12
 * @param ri Register: PCP_DEI_QOS_MAP_CFG (??), 0-15
 */
#define VTSS_REW_PORT_PCP_DEI_QOS_MAP_CFG(gi,ri)  VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,ri,4)

/** 
 * \brief
 * Map the frame's DP level and QoS class to a DEI value. DEI =
 * PCP_DEI_QOS_MAP_CFG[8*DP level + QoS class].DEI_QOS_VAL. This must be
 * enabled in TAG_CFG.TAG_DEI_CFG.
 *
 * \details 
 * Field: ::VTSS_REW_PORT_PCP_DEI_QOS_MAP_CFG . DEI_QOS_VAL
 */
#define  VTSS_F_REW_PORT_PCP_DEI_QOS_MAP_CFG_DEI_QOS_VAL(x)  VTSS_ENCODE_BITFIELD(!!(x),3,1)
#define  VTSS_M_REW_PORT_PCP_DEI_QOS_MAP_CFG_DEI_QOS_VAL  VTSS_BIT(3)
#define  VTSS_X_REW_PORT_PCP_DEI_QOS_MAP_CFG_DEI_QOS_VAL(x)  VTSS_EXTRACT_BITFIELD(x,3,1)

/** 
 * \brief
 * Map the frame's DP level and QoS class to a PCP value. PCP =
 * PCP_DEI_QOS_MAP_CFG[8*DP level + QoS class].PCP_QOS_VAL. This must be
 * enabled in TAG_CFG.TAG_PCP_CFG.
 *
 * \details 
 * Field: ::VTSS_REW_PORT_PCP_DEI_QOS_MAP_CFG . PCP_QOS_VAL
 */
#define  VTSS_F_REW_PORT_PCP_DEI_QOS_MAP_CFG_PCP_QOS_VAL(x)  VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_REW_PORT_PCP_DEI_QOS_MAP_CFG_PCP_QOS_VAL     VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_REW_PORT_PCP_DEI_QOS_MAP_CFG_PCP_QOS_VAL(x)  VTSS_EXTRACT_BITFIELD(x,0,3)


/** 
 * \brief Precision time protocol configuration
 *
 * \details
 * Register: \a REW:PORT:PTP_CFG
 *
 * @param gi Replicator: x_DPORT_CNT (??), 0-12
 */
#define VTSS_REW_PORT_PTP_CFG(gi)            VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,0,20)

/** 
 * \brief
 * Backplane mode for PTP. If set, the frame's receive timestamp is written
 * into the PTP header (4 reserved bytes at offset 16).
 *
 * \details 
 * Field: ::VTSS_REW_PORT_PTP_CFG . PTP_BACKPLANE_MODE
 */
#define  VTSS_F_REW_PORT_PTP_CFG_PTP_BACKPLANE_MODE(x)  VTSS_ENCODE_BITFIELD(!!(x),7,1)
#define  VTSS_M_REW_PORT_PTP_CFG_PTP_BACKPLANE_MODE  VTSS_BIT(7)
#define  VTSS_X_REW_PORT_PTP_CFG_PTP_BACKPLANE_MODE(x)  VTSS_EXTRACT_BITFIELD(x,7,1)

/** 
 * \brief
 * Blablabla.
 *
 * \details 
 * Field: ::VTSS_REW_PORT_PTP_CFG . GP_CFG_UNUSED
 */
#define  VTSS_F_REW_PORT_PTP_CFG_GP_CFG_UNUSED(x)  VTSS_ENCODE_BITFIELD(x,3,4)
#define  VTSS_M_REW_PORT_PTP_CFG_GP_CFG_UNUSED     VTSS_ENCODE_BITMASK(3,4)
#define  VTSS_X_REW_PORT_PTP_CFG_GP_CFG_UNUSED(x)  VTSS_EXTRACT_BITFIELD(x,3,4)

/** 
 * \brief
 * Overrules the one-step and the origin PTP commands from IS2. This
 * disables updating the correction field or the origin timestamp field in
 * the PTP frame.
 *
 * \details 
 * Field: ::VTSS_REW_PORT_PTP_CFG . PTP_1STEP_DIS
 */
#define  VTSS_F_REW_PORT_PTP_CFG_PTP_1STEP_DIS(x)  VTSS_ENCODE_BITFIELD(!!(x),2,1)
#define  VTSS_M_REW_PORT_PTP_CFG_PTP_1STEP_DIS  VTSS_BIT(2)
#define  VTSS_X_REW_PORT_PTP_CFG_PTP_1STEP_DIS(x)  VTSS_EXTRACT_BITFIELD(x,2,1)

/** 
 * \brief
 * Overrules the two-step PTP command from IS2. This effectively disables
 * saving the frame's departure time into the timestamp FIFO queue.
 *
 * \details 
 * Field: ::VTSS_REW_PORT_PTP_CFG . PTP_2STEP_DIS
 */
#define  VTSS_F_REW_PORT_PTP_CFG_PTP_2STEP_DIS(x)  VTSS_ENCODE_BITFIELD(!!(x),1,1)
#define  VTSS_M_REW_PORT_PTP_CFG_PTP_2STEP_DIS  VTSS_BIT(1)
#define  VTSS_X_REW_PORT_PTP_CFG_PTP_2STEP_DIS(x)  VTSS_EXTRACT_BITFIELD(x,1,1)

/** 
 * \brief
 * If this bit is set, the UDP checksum will not be corrected when the PTP
 * datagram is changed.
 *
 * \details 
 * Field: ::VTSS_REW_PORT_PTP_CFG . PTP_UDP_KEEP
 */
#define  VTSS_F_REW_PORT_PTP_CFG_PTP_UDP_KEEP(x)  VTSS_ENCODE_BITFIELD(!!(x),0,1)
#define  VTSS_M_REW_PORT_PTP_CFG_PTP_UDP_KEEP  VTSS_BIT(0)
#define  VTSS_X_REW_PORT_PTP_CFG_PTP_UDP_KEEP(x)  VTSS_EXTRACT_BITFIELD(x,0,1)


/** 
 * \brief Asymmetric delay
 *
 * \details
 * Register: \a REW:PORT:PTP_DLY1_CFG
 *
 * @param gi Replicator: x_DPORT_CNT (??), 0-12
 */
#define VTSS_REW_PORT_PTP_DLY1_CFG(gi)       VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,0,21)

/** 
 * \brief
 * Delay to add to frame's residence time. This is applicable to one-step
 * PTP and it is enabled by setting the IS2 action REW_OP[5] to 1. Unit is
 * ns. Value is signed.
 *
 * \details 
 * Field: ::VTSS_REW_PORT_PTP_DLY1_CFG . PTP_DLY1_VAL
 */
#define  VTSS_F_REW_PORT_PTP_DLY1_CFG_PTP_DLY1_VAL(x)  (x)
#define  VTSS_M_REW_PORT_PTP_DLY1_CFG_PTP_DLY1_VAL     0xffffffff
#define  VTSS_X_REW_PORT_PTP_DLY1_CFG_PTP_DLY1_VAL(x)  (x)

/**
 * Register Group: \a REW:COMMON
 *
 * Common configurations for Rewriter
 */


/** 
 * \brief Remap table of DSCP values for frames with drop precedence set
 *
 * \details
 * Register: \a REW:COMMON:DSCP_REMAP_DP1_CFG
 *
 * @param ri Register: DSCP_REMAP_DP1_CFG (??), 0-63
 */
#define VTSS_REW_COMMON_DSCP_REMAP_DP1_CFG(ri)  VTSS_IOREG(VTSS_TO_REW,0x1a4 + (ri))

/** 
 * \brief
 * One to one DSCP remapping table common for all ports. This table is used
 * if ANA::DSCP_CFG[DSCP].DSCP_REWR_ENA=3 and DP=1.
 *
 * \details 
 * Field: ::VTSS_REW_COMMON_DSCP_REMAP_DP1_CFG . DSCP_REMAP_DP1_VAL
 */
#define  VTSS_F_REW_COMMON_DSCP_REMAP_DP1_CFG_DSCP_REMAP_DP1_VAL(x)  VTSS_ENCODE_BITFIELD(x,0,6)
#define  VTSS_M_REW_COMMON_DSCP_REMAP_DP1_CFG_DSCP_REMAP_DP1_VAL     VTSS_ENCODE_BITMASK(0,6)
#define  VTSS_X_REW_COMMON_DSCP_REMAP_DP1_CFG_DSCP_REMAP_DP1_VAL(x)  VTSS_EXTRACT_BITFIELD(x,0,6)


/** 
 * \brief Remap table of DSCP values
 *
 * \details
 * Register: \a REW:COMMON:DSCP_REMAP_CFG
 *
 * @param ri Register: DSCP_REMAP_CFG (??), 0-63
 */
#define VTSS_REW_COMMON_DSCP_REMAP_CFG(ri)   VTSS_IOREG(VTSS_TO_REW,0x1e4 + (ri))

/** 
 * \brief
 * One to one DSCP remapping table common for all ports. This table is used
 * if ANA::DSCP_CFG[DSCP].DSCP_REWR_ENA=2 or if
 * DSCP_CFG[DSCP].DSCP_REWR_ENA=3 and DP=0.
 *
 * \details 
 * Field: ::VTSS_REW_COMMON_DSCP_REMAP_CFG . DSCP_REMAP_VAL
 */
#define  VTSS_F_REW_COMMON_DSCP_REMAP_CFG_DSCP_REMAP_VAL(x)  VTSS_ENCODE_BITFIELD(x,0,6)
#define  VTSS_M_REW_COMMON_DSCP_REMAP_CFG_DSCP_REMAP_VAL     VTSS_ENCODE_BITMASK(0,6)
#define  VTSS_X_REW_COMMON_DSCP_REMAP_CFG_DSCP_REMAP_VAL(x)  VTSS_EXTRACT_BITFIELD(x,0,6)


/** 
 * \brief Egress statistics mode
 *
 * \details
 * Register: \a REW:COMMON:STAT_CFG
 */
#define VTSS_REW_COMMON_STAT_CFG             VTSS_IOREG(VTSS_TO_REW,0x224)

/** 
 * \brief
 * Configures the egress service statistics mode. The following options for
 * looking up the egress service counter set are available:
 *
 * \details 
 * 00: Use ESDX from ES0 if hit, otherwise ISDX
 * 01: Use ESDX from ES0 if hit, otherwise no counting.
 * 10: Use ISDX.
 * 11: Use 8*SRC_PORT + QOS_CLASS.
 *
 * Field: ::VTSS_REW_COMMON_STAT_CFG . STAT_MODE
 */
#define  VTSS_F_REW_COMMON_STAT_CFG_STAT_MODE(x)  VTSS_ENCODE_BITFIELD(x,0,2)
#define  VTSS_M_REW_COMMON_STAT_CFG_STAT_MODE     VTSS_ENCODE_BITMASK(0,2)
#define  VTSS_X_REW_COMMON_STAT_CFG_STAT_MODE(x)  VTSS_EXTRACT_BITFIELD(x,0,2)

/**
 * Register Group: \a REW:PPT
 *
 * Path group protection table per path
 */


/** 
 * \brief Path protection table
 *
 * \details
 * First register in this group maps to path protection group indexes 31:0.
 * Second register in this group maps to path protection group indexes
 * 63:32.
 * Third register in this group maps to path protection group indexes
 * 75:64.
 *
 * Register: \a REW:PPT:PPT
 *
 * @param ri Register: PPT (??), 0-2
 */
#define VTSS_REW_PPT_PPT(ri)                 VTSS_IOREG(VTSS_TO_REW,0x1a0 + (ri))

/** 
 * \brief
 * Path protection status with one entry per path protection group. The
 * path protection group is selected by ES0_action.PPT_IDX from the ES0
 * lookup.
 * 
 * Bit n in PPT[0].PATH_CFG returns the status for path protection group n,
 * n <= 31.
 * Bit n in PPT[1].PATH_CFG returns the status for path protection group
 * n+32, 32 <= n <= 63.
 * Bit n in PPT[2].PATH_CFG returns the status for path protection group
 * n+64, 64 <= n <= 75.
 * 
 * Each bit is encoded the following way:
 *
 * \details 
 * 0: Path protection group uses working path.
 * 1: Path protection group uses protected path.
 *
 * Field: ::VTSS_REW_PPT_PPT . PATH_STAT
 */
#define  VTSS_F_REW_PPT_PPT_PATH_STAT(x)      (x)
#define  VTSS_M_REW_PPT_PPT_PATH_STAT         0xffffffff
#define  VTSS_X_REW_PPT_PPT_PATH_STAT(x)      (x)


#endif /* _VTSS_OCELOT_REGS_REW_H_ */
