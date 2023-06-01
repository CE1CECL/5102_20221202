/* SPDX-License-Identifier: GPL-2.0 */


#ifndef __LINUX_TA_VDM_H
#define __LINUX_TA_VDM_H

#include "tcpm.h"

struct mtk_vdm_ta_cap {
	int cur;
	int vol;
	int temp;
};

enum {
	PD_USB_NOT_SUPPORT = -1,
	PD_USB_DISCONNECT = 0,
	PD_USB_CONNECT = 1,
};

struct pd_ta_stat {
	unsigned char chg_mode:1;
	unsigned char dc_en:1;
	unsigned char dpc_en:1;
	unsigned char pc_en:1;
	unsigned char ovp:1;
	unsigned char otp:1;
	unsigned char uvp:1;
	unsigned char rvs_cur:1;
	unsigned char ping_chk_fail:1;
};

static inline bool mtk_check_pe_ready_snk(void)
{
	return false;
}

#ifdef CONFIG_TCPC_CLASS

int tcpc_is_usb_connect(void);
bool mtk_is_pd_chg_ready(void);
bool mtk_is_ta_typec_only(void);
bool mtk_is_pep30_en_unlock(void);
#else
static inline int tcpc_is_usb_connect(void)
{
	return PD_USB_NOT_SUPPORT;
}

static inline int mtk_is_ta_typec_only(void)
{
	return true;
}

#if CONFIG_MTK_GAUGE_VERSION == 20
static inline bool mtk_is_pd_chg_ready(void)
{
	return false;
}

static inline bool mtk_is_pep30_en_unlock(void)
{
	return false;
}
#endif

#endif /* CONFIG_TCPC_RT1711H */

#ifdef CONFIG_RT7207_ADAPTER
enum { /* charge status */
	RT7207_CC_MODE,
	RT7207_CV_MODE,
};

#define MTK_VDM_FAIL  (-1)
#define MTK_VDM_SUCCESS  (0)
#define MTK_VDM_SW_BUSY	(1)


extern int mtk_direct_charge_vdm_init(void);

extern int mtk_vdm_config_dfp(void);

extern int mtk_get_ta_id(struct tcpc_device *tcpc);

extern int mtk_get_ta_charger_status(
		struct tcpc_device *tcpc, struct pd_ta_stat *ta);


extern int mtk_get_ta_temperature(struct tcpc_device *tcpc, int *temp);

extern int mtk_set_ta_boundary_cap(
	struct tcpc_device *tcpc, struct mtk_vdm_ta_cap *cap);


extern int mtk_set_ta_uvlo(struct tcpc_device *tcpc, int mv);

extern int mtk_get_ta_current_cap(struct tcpc_device *tcpc,
					struct mtk_vdm_ta_cap *cap);

extern int mtk_get_ta_setting_dac(struct tcpc_device *tcpc,
					struct mtk_vdm_ta_cap *cap);


extern int mtk_get_ta_boundary_cap(struct tcpc_device *tcpc,
					struct mtk_vdm_ta_cap *cap);


extern int mtk_set_ta_cap(struct tcpc_device *tcpc, struct mtk_vdm_ta_cap *cap);

extern int mtk_get_ta_cap(struct tcpc_device *tcpc,
					struct mtk_vdm_ta_cap *cap);
extern int mtk_monitor_ta_inform(struct tcpc_device *tcpc,
					struct mtk_vdm_ta_cap *cap);

extern int mtk_enable_direct_charge(struct tcpc_device *tcpc, bool en);

extern int mtk_enable_ta_dplus_dect(
			struct tcpc_device *tcpc, bool en, int time);

#if CONFIG_MTK_GAUGE_VERSION == 20
extern int mtk_clr_ta_pingcheck_fault(struct tcpc_device *tcpc);
#endif

#else /* not config RT7027 PD adapter */

static inline int mtk_direct_charge_vdm_init(void)
{
	return -1;
}

static inline int mtk_get_ta_id(void *tcpc)
{
	return -1;
}

static inline int mtk_set_ta_cap(
		void *tcpc, struct mtk_vdm_ta_cap *cap)
{
	cap->cur = cap->vol = cap->temp = 0;
	return -1;
}

static inline int mtk_get_ta_cap(
		void *tcpc, struct mtk_vdm_ta_cap *cap)
{
	cap->cur = cap->vol = cap->temp = 0;
	return -1;
}

static inline int mtk_get_ta_charger_status(
			void *tcpc, struct pd_ta_stat *ta)
{
	return -1;
}

static inline int mtk_get_ta_current_cap(
		void *tcpc, struct mtk_vdm_ta_cap *cap)
{
	cap->cur = cap->vol = cap->temp = 0;
	return -1;
}

static inline int mtk_get_ta_temperature(void *tcpc, int *temp)
{
	return -1;
}

static inline int mtk_update_ta_info(void *tcpc)
{
	return -1;
}

static inline int mtk_set_ta_boundary_cap(
		void *tcpc, struct mtk_vdm_ta_cap *cap)
{
	cap->cur = cap->vol = cap->temp = 0;
	return -1;
}

static inline int mtk_rqst_ta_cap(
		void *tcpc, struct mtk_vdm_ta_cap *cap)
{
	cap->cur = cap->vol = cap->temp = 0;
	return -1;
}

static inline int mtk_set_ta_uvlo(void *tcpc, int mv)
{
	return -1;
}

static inline int mtk_show_ta_info(void *tcpc)
{
	return -1;
}

static inline int mtk_get_ta_setting_dac(
			void *tcpc, struct mtk_vdm_ta_cap *cap)
{
	cap->cur = cap->vol = cap->temp = 0;
	return -1;
}

static inline int mtk_get_ta_boundary_cap(
			void *tcpc, struct mtk_vdm_ta_cap *cap)
{
	cap->cur = cap->vol = cap->temp = 0;
	return -1;
}

static inline int mtk_enable_direct_charge(void *tcpc, bool en)
{
	return -1;
}

static inline int mtk_enable_ta_dplus_dect(
			void *tcpc, bool en, int time)
{
	return -1;
}

#if CONFIG_MTK_GAUGE_VERSION == 20
static inline int mtk_clr_ta_pingcheck_fault(struct tcpc_device *tcpc)
{
	return -1;
}
#endif

static inline int mtk_monitor_ta_inform(void *tcpc,
					struct mtk_vdm_ta_cap *cap)
{
	cap->cur = cap->vol = cap->temp = 0;
	return -1;
}
#endif /* CONFIG_RT7207_ADAPTER */

#endif /* __LINUX_TA_VDM_H */
