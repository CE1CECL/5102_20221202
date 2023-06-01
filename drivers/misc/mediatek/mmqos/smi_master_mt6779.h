/* SPDX-License-Identifier: GPL-2.0 */

#ifndef __SMI_MASTER_MT6779_H__
#define __SMI_MASTER_MT6779_H__

#include <dt-bindings/interconnect/mtk,mmqos.h>
#include <dt-bindings/memory/mt6779-larb-port.h>

/* MMSYS */
#define SMI_PORT_DISP_POSTMASK0	MASTER_LARB_PORT(M4U_PORT_DISP_POSTMASK0)
#define SMI_PORT_DISP_OVL0_HDR MASTER_LARB_PORT(M4U_PORT_DISP_OVL0_HDR)
#define SMI_PORT_DISP_OVL0 MASTER_LARB_PORT(M4U_PORT_DISP_OVL0)
#define SMI_PORT_DISP_RDMA0 MASTER_LARB_PORT(M4U_PORT_DISP_RDMA0)
#define SMI_PORT_DISP_WDMA0 MASTER_LARB_PORT(M4U_PORT_DISP_WDMA0)

#define SMI_PORT_DISP_OVL0_2L_HDR MASTER_LARB_PORT(M4U_PORT_DISP_OVL0_2L_HDR)
#define SMI_PORT_DISP_OVL0_2L MASTER_LARB_PORT(M4U_PORT_DISP_OVL0_2L)
#define SMI_PORT_DISP_OVL1_2L MASTER_LARB_PORT(M4U_PORT_DISP_OVL1_2L)
#define SMI_PORT_DISP_RDMA1	MASTER_LARB_PORT(M4U_PORT_DISP_RDMA1)

#define SMI_PORT_MDP_RDMA0 MASTER_LARB_PORT(M4U_PORT_MDP_RDMA0)
#define SMI_PORT_MDP_RDMA1 MASTER_LARB_PORT(M4U_PORT_MDP_RDMA1)
#define SMI_PORT_MDP_WROT0_R MASTER_LARB_PORT(M4U_PORT_MDP_WROT0_R)
#define SMI_PORT_MDP_WROT1_R MASTER_LARB_PORT(M4U_PORT_MDP_WROT1_R)

/* VDEC */
#define SMI_PORT_VDEC_MC MASTER_LARB_PORT(M4U_PORT_HW_VDEC_MC_EXT)
#define SMI_PORT_VDEC_UFO MASTER_LARB_PORT(M4U_PORT_HW_VDEC_UFO_EXT)
#define SMI_PORT_VDEC_PP MASTER_LARB_PORT(M4U_PORT_HW_VDEC_PP_EXT)
#define SMI_PORT_VDEC_PRED_RD MASTER_LARB_PORT(M4U_PORT_HW_VDEC_PRED_RD_EXT)
#define SMI_PORT_VDEC_PRED_WR MASTER_LARB_PORT(M4U_PORT_HW_VDEC_PRED_WR_EXT)
#define SMI_PORT_VDEC_PPWRAP MASTER_LARB_PORT(M4U_PORT_HW_VDEC_PPWRAP_EXT)
#define SMI_PORT_VDEC_TILE MASTER_LARB_PORT(M4U_PORT_HW_VDEC_TILE_EXT)
#define SMI_PORT_VDEC_VLD MASTER_LARB_PORT(M4U_PORT_HW_VDEC_VLD_EXT)
#define SMI_PORT_VDEC_VLD2 MASTER_LARB_PORT(M4U_PORT_HW_VDEC_VLD2_EXT)
#define SMI_PORT_VDEC_AVC_MV MASTER_LARB_PORT(M4U_PORT_HW_VDEC_AVC_MV_EXT)
#define SMI_PORT_VDEC_UFO_ENC MASTER_LARB_PORT(M4U_PORT_HW_VDEC_UFO_ENC_EXT)
#define SMI_PORT_VDEC_RG_CTRL_DMA \
		MASTER_LARB_PORT(M4U_PORT_HW_VDEC_RG_CTRL_DMA_EXT)

/* VENC */
#define SMI_PORT_VENC_RCPU MASTER_LARB_PORT(M4U_PORT_VENC_RCPU)
#define SMI_PORT_VENC_REC MASTER_LARB_PORT(M4U_PORT_VENC_REC)
#define SMI_PORT_VENC_BSDMA MASTER_LARB_PORT(M4U_PORT_VENC_BSDMA)
#define SMI_PORT_VENC_SV_COMV MASTER_LARB_PORT(M4U_PORT_VENC_SV_COMV)
#define SMI_PORT_VENC_RD_COMV MASTER_LARB_PORT(M4U_PORT_VENC_RD_COMV)

#define SMI_PORT_JPGENC_Y_RDMA MASTER_LARB_PORT(M4U_PORT_JPGENC_Y_RDMA)
#define SMI_PORT_JPGENC_C_RDMA MASTER_LARB_PORT(M4U_PORT_JPGENC_C_RDMA)
#define SMI_PORT_JPGENC_Q_TABLE MASTER_LARB_PORT(M4U_PORT_JPGENC_Q_TABLE)
#define SMI_PORT_JPGENC_BSDMA MASTER_LARB_PORT(M4U_PORT_JPGENC_BSDMA)

#define SMI_PORT_VENC_CUR_LUMA MASTER_LARB_PORT(M4U_PORT_VENC_CUR_LUMA)
#define SMI_PORT_VENC_CUR_CHROMA MASTER_LARB_PORT(M4U_PORT_VENC_CUR_CHROMA)
#define SMI_PORT_VENC_REF_LUMA MASTER_LARB_PORT(M4U_PORT_VENC_REF_LUMA)
#define SMI_PORT_VENC_REF_CHROMA MASTER_LARB_PORT(M4U_PORT_VENC_REF_CHROMA)

/* IMG */
#define SMI_PORT_IMGI_D1 MASTER_LARB_PORT(M4U_PORT_IMGI_D1)
#define SMI_PORT_IMGCI_D1 MASTER_LARB_PORT(M4U_PORT_IMGBI_D1)
#define SMI_PORT_DMGI_D1 MASTER_LARB_PORT(M4U_PORT_DMGI_D1)
#define SMI_PORT_UFDI_D1 MASTER_LARB_PORT(M4U_PORT_DEPI_D1)
#define SMI_PORT_LCI_D1 MASTER_LARB_PORT(M4U_PORT_LCEI_D1)
#define SMI_PORT_SMTI_D1 MASTER_LARB_PORT(M4U_PORT_SMTI_D1)
#define SMI_PORT_SMTO_D2 MASTER_LARB_PORT(M4U_PORT_SMTO_D2)
#define SMI_PORT_SMTO_D1 MASTER_LARB_PORT(M4U_PORT_SMTO_D1)
#define SMI_PORT_CRZO_D1 MASTER_LARB_PORT(M4U_PORT_CRZO_D1)

#define SMI_PORT_UFOYW MASTER_LARB_PORT(M4U_PORT_IMG3O_D1)
#define SMI_PORT_UFOCW MASTER_LARB_PORT(M4U_PORT_VIPI_D1)
#define SMI_PORT_UFOYR MASTER_LARB_PORT(M4U_PORT_WPE_RDMA1)
#define SMI_PORT_UFOCR MASTER_LARB_PORT(M4U_PORT_WPE_RDMA0)
#define SMI_PORT_UFOY2R MASTER_LARB_PORT(M4U_PORT_WPE_WDMA)
#define SMI_PORT_UFOC2R MASTER_LARB_PORT(M4U_PORT_TIMGO_D1)
#define SMI_PORT_WPE_RDMA1 MASTER_LARB_PORT(M4U_PORT_MFB_RDMA0)
#define SMI_PORT_WPR_RDMA0 MASTER_LARB_PORT(M4U_PORT_MFB_RDMA1)
#define SMI_PORT_WPR_WDMA MASTER_LARB_PORT(M4U_PORT_MFB_RDMA2)
#define SMI_PORT_TIMGO_D1 MASTER_LARB_PORT(M4U_PORT_MFB_RDMA3)
#define SMI_PORT_PRVYR MASTER_LARB_PORT(M4U_PORT_MFB_WDMA)

/* IPE */
#define SMI_PORT_FDVT_RDA MASTER_LARB_PORT(M4U_PORT_FDVT_RDA)
#define SMI_PORT_FDVT_RDB MASTER_LARB_PORT(M4U_PORT_FDVT_RDB)
#define SMI_PORT_FDVT_WRA MASTER_LARB_PORT(M4U_PORT_FDVT_WRA)
#define SMI_PORT_FDVT_WRB MASTER_LARB_PORT(M4U_PORT_FDVT_WRB)
#define SMI_PORT_RSC_RDMA0 MASTER_LARB_PORT(M4U_PORT_RSC_RDMA0)
#define SMI_PORT_RSC_WDMA MASTER_LARB_PORT(M4U_PORT_RSC_WDMA)

/* CAM */
#define SMI_PORT_IMGO_R1_C MASTER_LARB_PORT(M4U_PORT_CAM_IMGO_R1_C)
#define SMI_PORT_RRZO_R1_C MASTER_LARB_PORT(M4U_PORT_CAM_RRZO_R1_C)
#define SMI_PORT_LSCI_R1_C MASTER_LARB_PORT(M4U_PORT_CAM_LSCI_R1_C)
#define SMI_PORT_BPCI_R1_C MASTER_LARB_PORT(M4U_PORT_CAM_BPCI_R1_C)
#define SMI_PORT_YUVO_R1_C MASTER_LARB_PORT(M4U_PORT_CAM_YUVO_R1_C)
#define SMI_PORT_UFDI_R2_C MASTER_LARB_PORT(M4U_PORT_CAM_UFDI_R2_C)
#define SMI_PORT_RAWI_R2_C MASTER_LARB_PORT(M4U_PORT_CAM_RAWI_R2_C)
#define SMI_PORT_CAMSV_1 MASTER_LARB_PORT(M4U_PORT_CAM_CAMSV_1)
#define SMI_PORT_CAMSV_2 MASTER_LARB_PORT(M4U_PORT_CAM_CAMSV_2)
#define SMI_PORT_CAMSV_3 MASTER_LARB_PORT(M4U_PORT_CAM_CAMSV_3)
#define SMI_PORT_AAO_R1_C MASTER_LARB_PORT(M4U_PORT_CAM_AAO_R1_C)
#define SMI_PORT_AFO_R1_C MASTER_LARB_PORT(M4U_PORT_CAM_AFO_R1_C)
#define SMI_PORT_FLKO_R1_C MASTER_LARB_PORT(M4U_PORT_CAM_FLKO_R1_C)
#define SMI_PORT_LCESO_R1_C MASTER_LARB_PORT(M4U_PORT_CAM_LCESO_R1_C)
#define SMI_PORT_CRZO_R1_C MASTER_LARB_PORT(M4U_PORT_CAM_CRZO_R1_C)
#define SMI_PORT_LTMSO_R1_C MASTER_LARB_PORT(M4U_PORT_CAM_LTMSO_R1_C)
#define SMI_PORT_RSSO_R1_C MASTER_LARB_PORT(M4U_PORT_CAM_RSSO_R1_C)
#define SMI_PORT_CCUI MASTER_LARB_PORT(M4U_PORT_CAM_CCUI)
#define SMI_PORT_CCUO MASTER_LARB_PORT(M4U_PORT_CAM_CCUO)

#define SMI_PORT_IMGO_R1_A MASTER_LARB_PORT(M4U_PORT_CAM_IMGO_R1_A)
#define SMI_PORT_RRZO_R1_A MASTER_LARB_PORT(M4U_PORT_CAM_RRZO_R1_A)
#define SMI_PORT_LSCI_R1_A MASTER_LARB_PORT(M4U_PORT_CAM_LSCI_R1_A)
#define SMI_PORT_BPCI_R1_A MASTER_LARB_PORT(M4U_PORT_CAM_BPCI_R1_A)
#define SMI_PORT_YUVO_R1_A MASTER_LARB_PORT(M4U_PORT_CAM_YUVO_R1_A)
#define SMI_PORT_UFDI_R2_A MASTER_LARB_PORT(M4U_PORT_CAM_UFDI_R2_A)
#define SMI_PORT_RAWI_R2_A MASTER_LARB_PORT(M4U_PORT_CAM_RAWI_R2_A)

#define SMI_PORT_IMGO_R1_B MASTER_LARB_PORT(M4U_PORT_CAM_IMGO_R1_B)
#define SMI_PORT_RRZO_R1_B MASTER_LARB_PORT(M4U_PORT_CAM_RRZO_R1_B)
#define SMI_PORT_LSCI_R1_B MASTER_LARB_PORT(M4U_PORT_CAM_LSCI_R1_B)
#define SMI_PORT_BPCI_R1_B MASTER_LARB_PORT(M4U_PORT_CAM_BPCI_R1_B)
#define SMI_PORT_YUVO_R1_B MASTER_LARB_PORT(M4U_PORT_CAM_YUVO_R1_B)
#define SMI_PORT_UFDI_R2_B MASTER_LARB_PORT(M4U_PORT_CAM_UFDI_R2_B)
#define SMI_PORT_RAWI_R2_b MASTER_LARB_PORT(M4U_PORT_CAM_RAWI_R2_B)

#define SMI_PORT_AAO_R1_A MASTER_LARB_PORT(M4U_PORT_CAM_AAO_R1_A)
#define SMI_PORT_AFO_R1_A MASTER_LARB_PORT(M4U_PORT_CAM_AFO_R1_A)
#define SMI_PORT_FLKO_R1_A MASTER_LARB_PORT(M4U_PORT_CAM_FLKO_R1_A)
#define SMI_PORT_LCESO_R1_A MASTER_LARB_PORT(M4U_PORT_CAM_LCESO_R1_A)
#define SMI_PORT_CRZO_R1_A MASTER_LARB_PORT(M4U_PORT_CAM_CRZO_R1_A)

#define SMI_PORT_AAO_R1_B MASTER_LARB_PORT(M4U_PORT_CAM_AAO_R1_B)
#define SMI_PORT_AFO_R1_B MASTER_LARB_PORT(M4U_PORT_CAM_AFO_R1_B)
#define SMI_PORT_FLKO_R1_B MASTER_LARB_PORT(M4U_PORT_CAM_FLKO_R1_B)
#define SMI_PORT_LCESO_R1_B MASTER_LARB_PORT(M4U_PORT_CAM_LCESO_R1_B)
#define SMI_PORT_CRZO_R1_B MASTER_LARB_PORT(M4U_PORT_CAM_CRZO_R1_B)

#define SMI_PORT_LTMSO_R1_A MASTER_LARB_PORT(M4U_PORT_CAM_LTMSO_R1_A)
#define SMI_PORT_RSSO_R1_A MASTER_LARB_PORT(M4U_PORT_CAM_RSSO_R1_A)
#define SMI_PORT_LTMSO_R1_B MASTER_LARB_PORT(M4U_PORT_CAM_LTMSO_R1_B)
#define SMI_PORT_RSSO_R1_B MASTER_LARB_PORT(M4U_PORT_CAM_RSSO_R1_B)

#endif