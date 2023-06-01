/* SPDX-License-Identifier: GPL-2.0 */

#ifndef _MTK_VCODEC_ENC_H_
#define _MTK_VCODEC_ENC_H_

#include <media/videobuf2-core.h>
#include <media/videobuf2-v4l2.h>

enum eos_types {
	NON_EOS = 0,
	EOS_WITH_DATA,
	EOS
};

struct mtk_video_enc_buf {
	struct vb2_v4l2_buffer vb;
	struct list_head list;
	u32 param_change;
	struct mtk_enc_params enc_params;
	enum eos_types lastframe;
	int    flags;
	struct mtk_vcodec_mem bs_buf;
	struct venc_frm_buf frm_buf;
	unsigned int roimap;
};

extern const struct v4l2_ioctl_ops mtk_venc_ioctl_ops;
extern const struct v4l2_m2m_ops mtk_venc_m2m_ops;

void mtk_venc_unlock(struct mtk_vcodec_ctx *ctx, u32 hw_id);
void mtk_venc_lock(struct mtk_vcodec_ctx *ctx, u32 hw_id);
int mtk_vcodec_enc_queue_init(void *priv, struct vb2_queue *src_vq,
	struct vb2_queue *dst_vq);
void mtk_vcodec_enc_empty_queues(struct file *file, struct mtk_vcodec_ctx *ctx);
void mtk_vcodec_enc_release(struct mtk_vcodec_ctx *ctx);
int mtk_vcodec_enc_ctrls_setup(struct mtk_vcodec_ctx *ctx);
void mtk_vcodec_enc_set_default_params(struct mtk_vcodec_ctx *ctx);

#endif /* _MTK_VCODEC_ENC_H_ */