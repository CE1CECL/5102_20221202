/* SPDX-License-Identifier: GPL-2.0 */

#ifndef __PINCTRL_MTK_COMMON_V2_H
#define __PINCTRL_MTK_COMMON_V2_H

#include <linux/gpio/driver.h>

#define MTK_INPUT      0
#define MTK_OUTPUT     1
#define MTK_DISABLE    0
#define MTK_ENABLE     1
#define MTK_PULLDOWN   0
#define MTK_PULLUP     1

#define EINT_NA	U16_MAX
#define NO_EINT_SUPPORT	EINT_NA

#define PIN_FIELD_CALC(_s_pin, _e_pin, _i_base, _s_addr, _x_addrs,      \
		       _s_bit, _x_bits, _sz_reg, _fixed) {		\
		.s_pin = _s_pin,					\
		.e_pin = _e_pin,					\
		.i_base = _i_base,					\
		.s_addr = _s_addr,					\
		.x_addrs = _x_addrs,					\
		.s_bit = _s_bit,					\
		.x_bits = _x_bits,					\
		.sz_reg = _sz_reg,					\
		.fixed = _fixed,					\
	}

#define PIN_FIELD(_s_pin, _e_pin, _s_addr, _x_addrs, _s_bit, _x_bits)	\
	PIN_FIELD_CALC(_s_pin, _e_pin, 0, _s_addr, _x_addrs, _s_bit,	\
		       _x_bits, 32, 0)

#define PINS_FIELD(_s_pin, _e_pin, _s_addr, _x_addrs, _s_bit, _x_bits)	\
	PIN_FIELD_CALC(_s_pin, _e_pin, 0, _s_addr, _x_addrs, _s_bit,	\
		       _x_bits, 32, 1)

/* List these attributes which could be modified for the pin */
enum {
	PINCTRL_PIN_REG_MODE,
	PINCTRL_PIN_REG_DIR,
	PINCTRL_PIN_REG_DI,
	PINCTRL_PIN_REG_DO,
	PINCTRL_PIN_REG_SR,
	PINCTRL_PIN_REG_SMT,
	PINCTRL_PIN_REG_PD,
	PINCTRL_PIN_REG_PU,
	PINCTRL_PIN_REG_E4,
	PINCTRL_PIN_REG_E8,
	PINCTRL_PIN_REG_TDSEL,
	PINCTRL_PIN_REG_RDSEL,
	PINCTRL_PIN_REG_DRV,
	PINCTRL_PIN_REG_PUPD,
	PINCTRL_PIN_REG_R0,
	PINCTRL_PIN_REG_R1,
	PINCTRL_PIN_REG_IES,
	PINCTRL_PIN_REG_PULLEN,
	PINCTRL_PIN_REG_PULLSEL,
	PINCTRL_PIN_REG_DRV_EH,
	PINCTRL_PIN_REG_DRV_EN,
	PINCTRL_PIN_REG_DRV_E0,
	PINCTRL_PIN_REG_DRV_E1,
	PINCTRL_PIN_REG_MAX,
};

/* Group the pins by the driving current */
enum {
	DRV_FIXED,
	DRV_GRP0,
	DRV_GRP1,
	DRV_GRP2,
	DRV_GRP3,
	DRV_GRP4,
	DRV_GRP_MAX,
};

static const char * const mtk_default_register_base_names[] = {
	"base",
};

struct mtk_pin_field {
	u8  index;
	u32 offset;
	u32 mask;
	u8  bitpos;
	u8  next;
};

struct mtk_pin_field_calc {
	u16 s_pin;
	u16 e_pin;
	u8  i_base;
	u32 s_addr;
	u8  x_addrs;
	u8  s_bit;
	u8  x_bits;
	u8  sz_reg;
	u8  fixed;
};

struct mtk_pin_reg_calc {
	const struct mtk_pin_field_calc *range;
	unsigned int nranges;
};

struct mtk_func_desc {
	const char *name;
	u8 muxval;
};

struct mtk_eint_desc {
	u16 eint_m;
	u16 eint_n;
};

struct mtk_pin_desc {
	unsigned int number;
	const char *name;
	struct mtk_eint_desc eint;
	u8 drv_n;
	struct mtk_func_desc *funcs;
};

struct mtk_pinctrl_group {
	const char	*name;
	unsigned long	config;
	unsigned	pin;
};

struct mtk_pinctrl;

/* struct mtk_pin_soc - the structure that holds SoC-specific data */
struct mtk_pin_soc {
	const struct mtk_pin_reg_calc	*reg_cal;
	const struct mtk_pin_desc	*pins;
	unsigned int			npins;
	const struct group_desc		*grps;
	unsigned int			ngrps;
	const struct function_desc	*funcs;
	unsigned int			nfuncs;
	const struct mtk_eint_regs	*eint_regs;
	const struct mtk_eint_hw	*eint_hw;

	/* Specific parameters per SoC */
	u8				gpio_m;
	bool				ies_present;
	const char * const		*base_names;
	unsigned int			nbase_names;

	/* Specific pinconfig operations */
	int (*bias_disable_set)(struct mtk_pinctrl *hw,
				const struct mtk_pin_desc *desc);
	int (*bias_disable_get)(struct mtk_pinctrl *hw,
				const struct mtk_pin_desc *desc, int *res);
	int (*bias_set)(struct mtk_pinctrl *hw,
			const struct mtk_pin_desc *desc, bool pullup);
	int (*bias_get)(struct mtk_pinctrl *hw,
			const struct mtk_pin_desc *desc, bool pullup, int *res);

	int (*bias_set_combo)(struct mtk_pinctrl *hw,
			const struct mtk_pin_desc *desc, u32 pullup, u32 arg);
	int (*bias_get_combo)(struct mtk_pinctrl *hw,
			const struct mtk_pin_desc *desc, u32 *pullup, u32 *arg);

	int (*drive_set)(struct mtk_pinctrl *hw,
			 const struct mtk_pin_desc *desc, u32 arg);
	int (*drive_get)(struct mtk_pinctrl *hw,
			 const struct mtk_pin_desc *desc, int *val);

	int (*adv_pull_set)(struct mtk_pinctrl *hw,
			    const struct mtk_pin_desc *desc, bool pullup,
			    u32 arg);
	int (*adv_pull_get)(struct mtk_pinctrl *hw,
			    const struct mtk_pin_desc *desc, bool pullup,
			    u32 *val);
	int (*adv_drive_set)(struct mtk_pinctrl *hw,
			     const struct mtk_pin_desc *desc, u32 arg);
	int (*adv_drive_get)(struct mtk_pinctrl *hw,
			     const struct mtk_pin_desc *desc, u32 *val);

	/* Specific driver data */
	void				*driver_data;
};

struct mtk_pinctrl {
	struct pinctrl_dev		*pctrl;
	void __iomem			**base;
	u8				nbase;
	struct device			*dev;
	struct gpio_chip		chip;
	const struct mtk_pin_soc        *soc;
	struct mtk_eint			*eint;
	struct mtk_pinctrl_group	*groups;
	const char          **grp_names;
};

void mtk_rmw(struct mtk_pinctrl *pctl, u8 i, u32 reg, u32 mask, u32 set);

int mtk_hw_set_value(struct mtk_pinctrl *hw, const struct mtk_pin_desc *desc,
		     int field, int value);
int mtk_hw_get_value(struct mtk_pinctrl *hw, const struct mtk_pin_desc *desc,
		     int field, int *value);

int mtk_build_eint(struct mtk_pinctrl *hw, struct platform_device *pdev);

extern const struct dev_pm_ops mtk_eint_pm_ops_v2;

int mtk_pinconf_bias_disable_set(struct mtk_pinctrl *hw,
				 const struct mtk_pin_desc *desc);
int mtk_pinconf_bias_disable_get(struct mtk_pinctrl *hw,
				 const struct mtk_pin_desc *desc, int *res);
int mtk_pinconf_bias_set(struct mtk_pinctrl *hw,
			 const struct mtk_pin_desc *desc, bool pullup);
int mtk_pinconf_bias_get(struct mtk_pinctrl *hw,
			 const struct mtk_pin_desc *desc, bool pullup,
			 int *res);

int mtk_pinconf_bias_disable_set_rev1(struct mtk_pinctrl *hw,
				      const struct mtk_pin_desc *desc);
int mtk_pinconf_bias_disable_get_rev1(struct mtk_pinctrl *hw,
				      const struct mtk_pin_desc *desc,
				      int *res);
int mtk_pinconf_bias_set_rev1(struct mtk_pinctrl *hw,
			      const struct mtk_pin_desc *desc, bool pullup);
int mtk_pinconf_bias_get_rev1(struct mtk_pinctrl *hw,
			      const struct mtk_pin_desc *desc, bool pullup,
			      int *res);

int mtk_pinconf_drive_set(struct mtk_pinctrl *hw,
			  const struct mtk_pin_desc *desc, u32 arg);
int mtk_pinconf_drive_get(struct mtk_pinctrl *hw,
			  const struct mtk_pin_desc *desc, int *val);

int mtk_pinconf_drive_set_rev1(struct mtk_pinctrl *hw,
			       const struct mtk_pin_desc *desc, u32 arg);
int mtk_pinconf_drive_get_rev1(struct mtk_pinctrl *hw,
			       const struct mtk_pin_desc *desc, int *val);

int mtk_pinconf_drive_set_raw(struct mtk_pinctrl *hw,
			       const struct mtk_pin_desc *desc, u32 arg);
int mtk_pinconf_drive_get_raw(struct mtk_pinctrl *hw,
			       const struct mtk_pin_desc *desc, int *val);

int mtk_pinconf_adv_pull_set(struct mtk_pinctrl *hw,
			     const struct mtk_pin_desc *desc, bool pullup,
			     u32 arg);
int mtk_pinconf_adv_pull_get(struct mtk_pinctrl *hw,
			     const struct mtk_pin_desc *desc, bool pullup,
			     u32 *val);
int mtk_pinconf_adv_drive_set(struct mtk_pinctrl *hw,
			      const struct mtk_pin_desc *desc, u32 arg);
int mtk_pinconf_adv_drive_get(struct mtk_pinctrl *hw,
			      const struct mtk_pin_desc *desc, u32 *val);

int mtk_pinconf_bias_set_combo(struct mtk_pinctrl *hw,
				const struct mtk_pin_desc *desc,
				u32 pullup, u32 enable);

int mtk_pinconf_bias_get_combo(struct mtk_pinctrl *hw,
			      const struct mtk_pin_desc *desc,
			      u32 *pullup, u32 *enable);

bool mtk_is_virt_gpio(struct mtk_pinctrl *hw, unsigned int gpio_n);
#endif /* __PINCTRL_MTK_COMMON_V2_H */