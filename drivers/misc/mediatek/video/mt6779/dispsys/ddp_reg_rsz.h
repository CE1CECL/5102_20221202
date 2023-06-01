/* SPDX-License-Identifier: GPL-2.0 */

#ifndef __DDP_RSZ_REG_H__
#define __DDP_RSZ_REG_H__

#include "ddp_reg.h"

/* DISP_RSZ reg offset */
#define DISP_REG_RSZ_ENABLE				(0x000)
#  define FLD_RSZ_RST					REG_FLD_MSB_LSB(16, 16)
#  define FLD_RSZ_EN					REG_FLD_MSB_LSB(0, 0)
#define DISP_REG_RSZ_CONTROL_1				(0x004)
#  define FLD_RSZ_INT_WCLR_EN				REG_FLD_MSB_LSB(31, 31)
#  define FLD_RSZ_INTEN					REG_FLD_MSB_LSB(30, 28)
#  define FLD_RSZ_DCM_DIS				REG_FLD_MSB_LSB(27, 27)
#  define FLD_RSZ_VERTICAL_TABLE_SELECT			REG_FLD_MSB_LSB(25, 21)
#  define FLD_RSZ_HORIZONTAL_TABLE_SELECT		REG_FLD_MSB_LSB(20, 16)
#  define FLD_RSZ_LBCSON_MODE				REG_FLD_MSB_LSB(9, 9)
#  define FLD_RSZ_VERTICAL_EN				REG_FLD_MSB_LSB(1, 1)
#  define FLD_RSZ_HORIZONTAL_EN				REG_FLD_MSB_LSB(0, 0)
#define DISP_REG_RSZ_CONTROL_2				(0x008)
#  define FLD_RSZ_RGB_BIT_MODE				REG_FLD_MSB_LSB(28, 28)
#  define FLD_RSZ_POWER_SAVING				REG_FLD_MSB_LSB(9, 9)
#define DISP_REG_RSZ_INT_FLAG				(0x00c)
#  define FLD_RSZ_SOF_RESET				REG_FLD_MSB_LSB(5, 5)
#  define FLD_RSZ_SIZE_ERR				REG_FLD_MSB_LSB(4, 4)
#  define FLD_RSZ_FRAME_END				REG_FLD_MSB_LSB(1, 1)
#  define FLD_RSZ_FRAME_START				REG_FLD_MSB_LSB(0, 0)
#define DISP_REG_RSZ_INPUT_IMAGE			(0x010)
#  define FLD_RSZ_INPUT_IMAGE_H				REG_FLD_MSB_LSB(31, 16)
#  define FLD_RSZ_INPUT_IMAGE_W				REG_FLD_MSB_LSB(15, 0)
#define DISP_REG_RSZ_OUTPUT_IMAGE			(0x014)
#  define FLD_RSZ_OUTPUT_IMAGE_H			REG_FLD_MSB_LSB(31, 16)
#  define FLD_RSZ_OUTPUT_IMAGE_W			REG_FLD_MSB_LSB(15, 0)
#define DISP_REG_RSZ_HORIZONTAL_COEFF_STEP		(0x018)
#  define FLD_RSZ_HORIZONTAL_COEFF_STEP			REG_FLD_MSB_LSB(22, 0)
#define DISP_REG_RSZ_VERTICAL_COEFF_STEP		(0x01c)
#  define FLD_RSZ_VERTICAL_COEFF_STEP			REG_FLD_MSB_LSB(22, 0)
#define DISP_REG_RSZ_LUMA_HORIZONTAL_INTEGER_OFFSET	(0x020)
#  define FLD_RSZ_LUMA_HORIZONTAL_INTEGER_OFFSET	REG_FLD_MSB_LSB(15, 0)
#define DISP_REG_RSZ_LUMA_HORIZONTAL_SUBPIXEL_OFFSET	(0x024)
#  define FLD_RSZ_LUMA_HORIZONTAL_SUBPIXEL_OFFSET	REG_FLD_MSB_LSB(20, 0)
#define DISP_REG_RSZ_LUMA_VERTICAL_INTEGER_OFFSET	(0x028)
#  define FLD_RSZ_LUMA_VERTICAL_INTEGER_OFFSET		REG_FLD_MSB_LSB(15, 0)
#define DISP_REG_RSZ_LUMA_VERTICAL_SUBPIXEL_OFFSET	(0x02c)
#  define FLD_RSZ_LUMA_VERTICAL_SUBPIXEL_OFFSET		REG_FLD_MSB_LSB(20, 0)
#define DISP_REG_RSZ_RSV				(0x040)
#define DISP_REG_RSZ_DEBUG_SEL				(0x044)
#define DISP_REG_RSZ_DEBUG				(0x048)
#define DISP_REG_RSZ_SHADOW_CTRL			(0x0f0)
#  define FLD_RSZ_READ_WRK_REG				REG_FLD_MSB_LSB(2, 2)
#  define FLD_RSZ_FORCE_COMMIT				REG_FLD_MSB_LSB(1, 1)
#  define FLD_RSZ_BYPASS_SHADOW				REG_FLD_MSB_LSB(0, 0)
#define DISP_REG_RSZ_ATPG				(0x0fc)
#define DISP_REG_PAT2_GET_SET				(0x200)
#define DISP_REG_PAT2_GEN_COLOR0			(0x208)
#define DISP_REG_PAT2_GEN_COLOR1			(0x20c)
#define DISP_REG_PAT2_GEN_CURSOR_RB0			(0x214)
#define DISP_REG_PAT2_GEN_CURSOR_RB1			(0x218)
#define DISP_REG_PAT2_GEN_TILE_POS			(0x224)
#define DISP_REG_PAT2_GEN_TILE_OV			(0x228)

/* DISP_RSZ bit field */
#define FLD_RSZ_RSV				REG_FLD_MSB_LSB(31, 0)
#define FLD_RSZ_DEBUG_SEL			REG_FLD_MSB_LSB(3, 0)
#define FLD_RSZ_DEBUG				REG_FLD_MSB_LSB(31, 0)
#define FLD_RSZ_ATPG_CT				REG_FLD_MSB_LSB(1, 1)
#define FLD_RSZ_ATPG_OB				REG_FLD_MSB_LSB(0, 0)
#define FLD_RSZ_REG2_PAT_TYPE			REG_FLD_MSB_LSB(23, 16)
#define FLD_RSZ_REG2_CURSOR_SHOW		REG_FLD_MSB_LSB(1, 1)
#define FLD_RSZ_REG2_PAT_GEN_EN			REG_FLD_MSB_LSB(0, 0)
#define FLD_RSZ_REG2_COLOR_V			REG_FLD_MSB_LSB(29, 20)
#define FLD_RSZ_REG2_COLOR_U			REG_FLD_MSB_LSB(19, 10)
#define FLD_RSZ_REG2_COLOR_Y			REG_FLD_MSB_LSB(9, 0)
#define FLD_RSZ_REG2_COLOR_A			REG_FLD_MSB_LSB(7, 0)
#define FLD_RSZ_REG2_POS_Y			REG_FLD_MSB_LSB(28, 16)
#define FLD_RSZ_REG2_POS_X			REG_FLD_MSB_LSB(12, 0)
#define FLD_RSZ_REG2_RB_CURSOR_U		REG_FLD_MSB_LSB(25, 16)
#define FLD_RSZ_REG2_RB_CURSOR_Y		REG_FLD_MSB_LSB(9, 0)
#define FLD_RSZ_REG2_RB_CURSOR_A		REG_FLD_MSB_LSB(23, 16)
#define FLD_RSZ_REG2_RB_CURSOR_V		REG_FLD_MSB_LSB(9, 0)
#define FLD_RSZ_REG2_TILE_POS_Y			REG_FLD_MSB_LSB(28, 16)
#define FLD_RSZ_REG2_TILE_POS_X			REG_FLD_MSB_LSB(12, 0)
#define FLD_RSZ_REG2_TILE_OV_Y			REG_FLD_MSB_LSB(15, 8)
#define FLD_RSZ_REG2_TILE_OV_X			REG_FLD_MSB_LSB(7, 0)

#endif
