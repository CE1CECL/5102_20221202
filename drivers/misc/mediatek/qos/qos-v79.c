// SPDX-License-Identifier: GPL-2.0

#include <linux/device.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/of_device.h>
#include <linux/kthread.h>

#include <sspm_ipi.h>
#include <sspm_ipi_pin.h>

#include <linux/arm-smccc.h>
#include <linux/soc/mediatek/mtk_sip_svc.h>

#include "mtk_qos_ipi.h"
#include "mtk_qos_sram.h"
#include "mtk_qos_bound.h"
#include "mtk_qos_common.h"

static const struct qos_ipi_cmd mt6779_qos_ipi_pin[] = {
	[QOS_IPI_QOS_ENABLE] = {
			.id = 0,
			.valid = true,
		},
	[QOS_IPI_QOS_BOUND] = {
			.id = 10,
			.valid = true,
		},
	[QOS_IPI_QOS_BOUND_ENABLE] = {
			.id = 11,
			.valid = true,
		},
	[QOS_IPI_QOS_BOUND_STRESS_ENABLE] = {
			.id = 12,
			.valid = true,
		},
	[QOS_IPI_SWPM_INIT] = {
			.id = 5,
			.valid = true,
		},
	[QOS_IPI_UPOWER_DATA_TRANSFER] = {
			.id = 6,
			.valid = true,
		},
	[QOS_IPI_UPOWER_DUMP_TABLE] = {
			.id = 7,
			.valid = true,
		},
	[QOS_IPI_GET_GPU_BW] = {
			.id = 8,
			.valid = true,
		},
	[QOS_IPI_SWPM_ENABLE] = {
			.id = 9,
			.valid = true,
		},
	[QOS_IPI_SMI_MET_MON] = {
			.id = 13,
			.valid = true,
		},
	[QOS_IPI_SETUP_GPU_INFO] = {
			.id = 14,
			.valid = true,
		},
	[QOS_IPI_SWPM_SET_UPDATE_CNT] = {
			.id = 15,
			.valid = true,
		},
};


static const struct qos_sram_addr mt6779_qos_sram_pin[] = {
	[QOS_DEBUG_0] = {
			.offset = 0,
			.valid = true,
		},
	[QOS_DEBUG_1] = {
			.offset = 0x4,
			.valid = true,
		},
	[QOS_DEBUG_2] = {
			.offset = 0x8,
			.valid = true,
		},
	[QOS_DEBUG_3] = {
			.offset = 0xC,
			.valid = true,
		},
	[QOS_DEBUG_4] = {
			.offset = 0x10,
			.valid = true,
		},
	[MM_SMI_VENC] = {
			.offset = 0x20,
			.valid = true,
		},
	[MM_SMI_CAM] = {
			.offset = 0x24,
			.valid = true,
		},
	[MM_SMI_IMG] = {
			.offset = 0x28,
			.valid = true,
		},
	[MM_SMI_MDP] = {
			.offset = 0x2C,
			.valid = true,
		},
	[MM_SMI_CLK] = {
			.offset = 0x30,
			.valid = true,
		},
	[MM_SMI_CLR] = {
			.offset = 0x34,
			.valid = true,
		},
	[MM_SMI_EXE] = {
			.offset = 0x38,
			.valid = true,
		},
	[MM_SMI_DUMP] = {
			.offset = 0x3C,
			.valid = true,
		},
	[APU_CLK] = {
			.offset = 0x48,
			.valid = true,
		},
	[APU_BW_NORD] = {
			.offset = 0x4C,
			.valid = true,
		},
	[DVFSRC_TIMESTAMP_OFFSET] = {
			.offset = 0x50,
			.valid = true,
		},
	[CM_STALL_RATIO_ID_0] = {
			.offset = 0x60,
			.valid = true,
		},
	[CM_STALL_RATIO_ID_1] = {
			.offset = 0x64,
			.valid = true,
		},
	[CM_STALL_RATIO_ID_2] = {
			.offset = 0x68,
			.valid = true,
		},
	[CM_STALL_RATIO_ID_3] = {
			.offset = 0x6C,
			.valid = true,
		},
	[CM_STALL_RATIO_ID_4] = {
			.offset = 0x70,
			.valid = true,
		},
	[CM_STALL_RATIO_ID_5] = {
			.offset = 0x74,
			.valid = true,
		},
	[CM_STALL_RATIO_ID_6] = {
			.offset = 0x78,
			.valid = true,
		},
	[CM_STALL_RATIO_ID_7] = {
			.offset = 0x7C,
			.valid = true,
		},
	[QOS_TOTAL_BW] = {
			.offset = 0x100,
			.valid = false,
		},
};

static int mt6779_qos_sspm_init(void)
{
	struct qos_ipi_data qos_ipi_d;

	qos_ipi_d.cmd = QOS_IPI_QOS_ENABLE;
	qos_ipi_to_sspm_command(&qos_ipi_d, 1);

	return 0;
}

static int mt6779_qos_ipi_recv_handler(void *arg)
{
#if defined(CONFIG_MTK_TINYSYS_SSPM_SUPPORT)
	struct ipi_action qos_isr;
	struct qos_ipi_data qos_ipi_d;
	struct mtk_qos *qos = arg;
	unsigned int rdata, ret;

	qos_isr.data = &qos_ipi_d;

	ret = sspm_ipi_recv_registration(IPI_ID_QOS, &qos_isr);
	if (ret) {
		pr_info("mtkqos:%s, sspm register fail(%u)\n", __func__, ret);
		return 0;
	}

	qos->soc->qos_sspm_init();

	do {
		rdata = 0;
		sspm_ipi_recv_wait(IPI_ID_QOS);

		if (qos_ipi_d.cmd == mt6779_qos_ipi_pin[QOS_IPI_QOS_BOUND].id)
			qos_notifier_call_chain(
					qos_ipi_d.u.qos_bound.state,
					get_qos_bound());
		else
			pr_info("mtkqos: %s wrong QoS IPI command: %d\n",
				__func__, qos_ipi_d.cmd);

	} while (!kthread_should_stop());
#endif

	return 0;
}

static const struct mtk_qos_soc mt6779_qos_data = {
	.ipi_pin = mt6779_qos_ipi_pin,
	.sram_pin = mt6779_qos_sram_pin,
	.qos_sspm_init = mt6779_qos_sspm_init,
	.qos_ipi_recv_handler = mt6779_qos_ipi_recv_handler,
};


static int mt6779_qos_probe(struct platform_device *pdev)
{
	return mtk_qos_probe(pdev, &mt6779_qos_data);
}


static const struct of_device_id mtk_qos_of_match[] = {
	{
		.compatible = "mediatek,mt6779-qos",
		.data = &mt6779_qos_data,
	}, {
		/* sentinel */
	},
};

static int mt6779_qos_remove(struct platform_device *pdev)
{
	return 0;
}


static struct platform_driver mt6779_qos_platdrv = {
	.probe	= mt6779_qos_probe,
	.remove	= mt6779_qos_remove,
	.driver	= {
		.name	= "mt6779-qos",
		.of_match_table = mtk_qos_of_match,
	},
};

static int __init mt6779_qos_init(void)
{
	int ret = 0;

	ret = platform_driver_register(&mt6779_qos_platdrv);

	return ret;
}

late_initcall(mt6779_qos_init)

static void __exit mt6779_qos_exit(void)
{
	platform_driver_unregister(&mt6779_qos_platdrv);
}
module_exit(mt6779_qos_exit)

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("MediaTek QoS driver");
