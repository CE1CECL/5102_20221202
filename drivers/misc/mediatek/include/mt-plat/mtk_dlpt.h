/* SPDX-License-Identifier: GPL-2.0 */

#ifndef _MTK_DLPT_H_
#define _MTK_DLPT_H_

#if !IS_ENABLED(CONFIG_MTK_LOW_BATTERY_POWER_THROTTLING)
#define DISABLE_LOW_BATTERY_PROTECT
#endif

#if !IS_ENABLED(CONFIG_MTK_BATTERY_OC_POWER_THROTTLING)
#define DISABLE_BATTERY_OC_PROTECT
#endif

#if !IS_ENABLED(CONFIG_MTK_BATTERY_PERCENTAGE_POWER_THROTTLING)
#define DISABLE_BATTERY_PERCENT_PROTECT
#endif

#if !IS_ENABLED(CONFIG_MTK_PBM)
#define DISABLE_DLPT_FEATURE
#endif

#endif /* _MTK_DLPT_H_ */
