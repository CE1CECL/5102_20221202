/* SPDX-License-Identifier: GPL-2.0 */

#ifndef __pcm_def_h__
#define __pcm_def_h__


/* --- R0 Define --- */
#define R0_SC_26M_CK_OFF                      (1U << 0)
#define R0_SC_TX_TRACK_RETRY_EN               (1U << 1)
#define R0_SC_MEM_CK_OFF                      (1U << 2)
#define R0_SC_AXI_CK_OFF                      (1U << 3)
#define R0_SC_DR_SRAM_LOAD                    (1U << 4)
#define R0_SC_MD26M_CK_OFF                    (1U << 5)
#define R0_SC_DPY_MODE_SW                     (1U << 6)
#define R0_SC_DMSUS_OFF                       (1U << 7)
#define R0_SC_DPY_2ND_DLL_EN                  (1U << 8)
#define R0_SC_DR_SRAM_RESTORE                 (1U << 9)
#define R0_SC_MPLLOUT_OFF                     (1U << 10)
#define R0_SC_TX_TRACKING_DIS                 (1U << 11)
#define R0_SC_DPY_DLL_EN                      (1U << 12)
#define R0_SC_DPY_DLL_CK_EN                   (1U << 13)
#define R0_SC_DPY_VREF_EN                     (1U << 14)
#define R0_SC_PHYPLL_EN                       (1U << 15)
#define R0_SC_DDRPHY_FB_CK_EN                 (1U << 16)
#define R0_SC_DPY_BCLK_ENABLE                 (1U << 17)
#define R0_SC_MPLL_OFF                        (1U << 18)
#define R0_SC_SHU_RESTORE                     (1U << 19)
#define R0_SC_CKSQ0_OFF                       (1U << 20)
#define R0_SC_DR_SHU_LEVEL_SRAM_LATCH         (1U << 21)
#define R0_SC_DR_SHU_EN                       (1U << 22)
#define R0_SC_DHPY_PRECAL_UP                  (1U << 23)
#define R0_SC_MPLL_S_OFF                      (1U << 24)
#define R0_SC_DHPY_RXDLY_TRACK_EN             (1U << 25)
#define R0_SC_PHYPLL_SHU_EN                   (1U << 26)
#define R0_SC_PHYPLL2_SHU_EN                  (1U << 27)
#define R0_SC_PHYPLL_MODE_SW                  (1U << 28)
#define R0_SC_PHYPLL2_MODE_SW                 (1U << 29)
#define R0_SC_DR_SHU_LEVEL0                   (1U << 30)
#define R0_SC_DR_SHU_LEVEL1                   (1U << 31)
/* --- R7 Define --- */
#define R7_PWRAP_SLEEP_REQ                    (1U << 0)
#define R7_EMI_CLK_OFF_REQ                    (1U << 1)
#define R7_TOP_MAS_PAU_REQ                    (1U << 2)
#define R7_SPM2CKSYS_MEM_CK_MUX_UPDATE        (1U << 3)
#define R7_PCM_CK_SEL0                        (1U << 4)
#define R7_PCM_CK_SEL1                        (1U << 5)
#define R7_SPM_LEAVE_DEEPIDLE_REQ             (1U << 6)
#define R7_SC_FHC_PAUSE_MPLL                  (1U << 7)
#define R7_SC_26M_CK_SEL                      (1U << 8)
#define R7_PCM_TIMER_SET                      (1U << 9)
#define R7_PCM_TIMER_CLR                      (1U << 10)
#define R7_SRCVOLTEN                          (1U << 11)
#define R7_CSYSPWRUPACK                       (1U << 12)
#define R7_IM_SLEEP_ENABLE                    (1U << 13)
#define R7_SRCCLKENO_0                        (1U << 14)
#define R7_SPM_SYSRST_B                       (1U << 15)
#define R7_SPM_APSRC_INTERNAL_ACK             (1U << 16)
#define R7_CPU_SYS_TIMER_CLK_SEL              (1U << 17)
#define R7_SC_AXI_DCM_DIS                     (1U << 18)
#define R7_SC_FHC_PAUSE_MEM                   (1U << 19)
#define R7_SC_FHC_PAUSE_MAIN                  (1U << 20)
#define R7_SRCCLKENO_1                        (1U << 21)
#define R7_WDT_KICK_P                         (1U << 22)
#define R7_SC_TIMER_RST                       (1U << 23)
#define R7_WAKEUP_EXT_W_SEL                   (1U << 24)
#define R7_WAKEUP_EXT_R_SEL                   (1U << 25)
#define R7_PMIC_IRQ_REQ_EN                    (1U << 26)
#define R7_FORCE_26M_WAKE                     (1U << 27)
#define R7_FORCE_APSRC_WAKE                   (1U << 28)
#define R7_FORCE_INFRA_WAKE                   (1U << 29)
#define R7_FORCE_VRF18_WAKE                   (1U << 30)
#define R7_SPM_DDR_EN_INTERNAL_ACK            (1U << 31)
/* --- R12 Define --- */
#define R12_PCM_TIMER_EVENT                   (1U << 0)
#define R12_SPM_TWAM_IRQ_B                    (1U << 1)
#define R12_KP_IRQ_B                          (1U << 2)
#define R12_APWDT_EVENT_B                     (1U << 3)
#define R12_APXGPT1_EVENT_B                   (1U << 4)
#define R12_CONN2AP_SPM_WAKEUP_B              (1U << 5)
#define R12_EINT_EVENT_B                      (1U << 6)
#define R12_CONN_WDT_IRQ_B                    (1U << 7)
#define R12_CCIF0_EVENT_B                     (1U << 8)
#define R12_LOWBATTERY_IRQ_B                  (1U << 9)
#define R12_SC_SSPM2SPM_WAKEUP                (1U << 10)
#define R12_SC_SCP2SPM_WAKEUP                 (1U << 11)
#define R12_SC_ADSP2SPM_WAKEUP                (1U << 12)
#define R12_PCM_WDT_EVENT_B                   (1U << 13)
#define R12_USBX_CDSC_B                       (1U << 14)
#define R12_USBX_POWERDWN_B                   (1U << 15)
#define R12_SYS_TIMER_EVENT_B                 (1U << 16)
#define R12_EINT_EVENT_SECURE_B               (1U << 17)
#define R12_CCIF1_EVENT_B                     (1U << 18)
#define R12_UART0_IRQ_B                       (1U << 19)
#define R12_AFE_IRQ_MCU_B                     (1U << 20)
#define R12_THERMAL_CTRL_EVENT_B              (1U << 21)
#define R12_SYS_CIRQ_IRQ_B                    (1U << 22)
#define R12_MD2AP_PEER_WAKEUP_EVENT           (1U << 23)
#define R12_CSYSPWREQ_B                       (1U << 24)
#define R12_MD1_WDT_B                         (1U << 25)
#define R12_AP2AP_PEER_WAKEUP_EVENT           (1U << 26)
#define R12_SEJ_EVENT_B                       (1U << 27)
#define R12_SPM_CPU_WAKEUP_EVENT              (1U << 28)
#define R12_CPU_IRQOUT                        (1U << 29)
#define R12_CPU_WFI                           (1U << 30)
#define R12_MCUSYS_IDLE_TO_EMI_ALL            (1U << 31)
/* --- R12ext Define --- */
#define R12EXT_26M_WAKE                       (1U << 0)
#define R12EXT_26M_SLEEP                      (1U << 1)
#define R12EXT_INFRA_WAKE                     (1U << 2)
#define R12EXT_INFRA_SLEEP                    (1U << 3)
#define R12EXT_APSRC_WAKE                     (1U << 4)
#define R12EXT_APSRC_SLEEP                    (1U << 5)
#define R12EXT_VRF18_WAKE                     (1U << 6)
#define R12EXT_VRF18_SLEEP                    (1U << 7)
#define R12EXT_DVFS_WAKE                      (1U << 8)
#define R12EXT_DDREN_WAKE                     (1U << 9)
#define R12EXT_DDREN_SLEEP                    (1U << 10)
#define R12EXT_DDREN2_WAKE                    (1U << 11)
#define R12EXT_DDREN2_SLEEP                   (1U << 12)
#define R12EXT_CONN_SRCCLKENB                 (1U << 13)
#define R12EXT_CONN_SRCCLKENB__B              (1U << 14)
#define R12EXT_SW_MAILBOX_WAKE                (1U << 15)
#define R12EXT_SSPM_MAILBOX_WAKE              (1U << 16)
#define R12EXT_ADSP_MAILBOX_WAKE              (1U << 17)
#define R12EXT_SCP_MAILBOX_WAKE               (1U << 18)
#define R12EXT_VS2_VOTER_INT0                 (1U << 19)
#define R12EXT_VS2_VOTER_INT1                 (1U << 20)
#define R12EXT_VS2_VOTER_INT2                 (1U << 21)
#define R12EXT_VS1_VOTER_INT0                 (1U << 22)
#define R12EXT_VS1_VOTER_INT1                 (1U << 23)
#define R12EXT_BIT24                          (1U << 24)
#define R12EXT_BIT25                          (1U << 25)
#define R12EXT_BIT26                          (1U << 26)
#define R12EXT_BIT27                          (1U << 27)
#define R12EXT_BIT28                          (1U << 28)
#define R12EXT_BIT29                          (1U << 29)
#define R12EXT_BIT30                          (1U << 30)
#define R12EXT_BIT31                          (1U << 31)
/* --- R13 Define --- */
#define R13_SRCCLKENI0                        (1U << 0)
#define R13_SRCCLKENI1                        (1U << 1)
#define R13_MD_SRCCLKENA_0                    (1U << 2)
#define R13_MD_APSRC_REQ_0                    (1U << 3)
#define R13_CONN_DDR_EN                       (1U << 4)
#define R13_MD_SRCCLKENA_1                    (1U << 5)
#define R13_SSPM_SRCCLKENA                    (1U << 6)
#define R13_SSPM_APSRC_REQ                    (1U << 7)
#define R13_MD1_STATE                         (1U << 8)
#define R13_EMI_CLK_OFF_2_ACK                 (1U << 9)
#define R13_MM_STATE                          (1U << 10)
#define R13_SSPM_STATE                        (1U << 11)
#define R13_MD_DDR_EN_0                       (1U << 12)
#define R13_CONN_STATE                        (1U << 13)
#define R13_CONN_SRCCLKENA                    (1U << 14)
#define R13_CONN_APSRC_REQ                    (1U << 15)
#define R13_BIT16                             (1U << 16)
#define R13_BIT17                             (1U << 17)
#define R13_SCP_STATE                         (1U << 18)
#define R13_CSYSPWRUPREQ                      (1U << 19)
#define R13_PWRAP_SLEEP_ACK                   (1U << 20)
#define R13_EMI_CLK_OFF_ACK_ALL               (1U << 21)
#define R13_AUDIO_DSP_STATE                   (1U << 22)
#define R13_SW_DMDRAMCSHU_ACK_ALL             (1U << 23)
#define R13_CONN_SRCCLKENB                    (1U << 24)
#define R13_SC_DR_SRAM_LOAD_ACK_ALL           (1U << 25)
#define R13_INFRA_AUX_IDLE                    (1U << 26)
#define R13_DVFS_STATE                        (1U << 27)
#define R13_SC_DR_SRAM_PLL_LOAD_ACK_ALL       (1U << 28)
#define R13_SC_DR_SRAM_RESTORE_ACK_ALL        (1U << 29)
#define R13_MD_VRF18_REQ_0                    (1U << 30)
#define R13_DDR_EN_STATE                      (1U << 31)

enum SPM_WAKE_SRC_LIST {
	WAKE_SRC_R12_PCM_TIMER = (1U << 0),
	WAKE_SRC_R12_SPM_TWAM_IRQ_B = (1U << 1),
	WAKE_SRC_R12_KP_IRQ_B = (1U << 2),
	WAKE_SRC_R12_APWDT_EVENT_B = (1U << 3),
	WAKE_SRC_R12_APXGPT1_EVENT_B = (1U << 4),
	WAKE_SRC_R12_CONN2AP_SPM_WAKEUP_B = (1U << 5),
	WAKE_SRC_R12_EINT_EVENT_B = (1U << 6),
	WAKE_SRC_R12_CONN_WDT_IRQ_B = (1U << 7),
	WAKE_SRC_R12_CCIF0_EVENT_B = (1U << 8),
	WAKE_SRC_R12_LOWBATTERY_IRQ_B = (1U << 9),
	WAKE_SRC_R12_SSPM_SPM_IRQ_B = (1U << 10),
	WAKE_SRC_R12_SCP_SPM_IRQ_B = (1U << 11),
	WAKE_SRC_R12_SC_ADSP2SPM_WAKEUP = (1U << 12),
	WAKE_SRC_R12_PCM_WDT_WAKEUP_B = (1U << 13),
	WAKE_SRC_R12_USB_CDSC_B = (1U << 14),
	WAKE_SRC_R12_USB_POWERDWN_B = (1U << 15),
	WAKE_SRC_R12_SYS_TIMER_EVENT_B = (1U << 16),
	WAKE_SRC_R12_EINT_EVENT_SECURE_B = (1U << 17),
	WAKE_SRC_R12_CCIF1_EVENT_B = (1U << 18),
	WAKE_SRC_R12_UART0_IRQ_B = (1U << 19),
	WAKE_SRC_R12_AFE_IRQ_MCU_B = (1U << 20),
	WAKE_SRC_R12_THERMAL_CTRL_EVENT_B = (1U << 21),
	WAKE_SRC_R12_SYS_CIRQ_IRQ_B = (1U << 22),
	WAKE_SRC_R12_MD2AP_PEER_WAKEUP_EVENT = (1U << 23),
	WAKE_SRC_R12_CSYSPWREQ_B = (1U << 24),
	WAKE_SRC_R12_MD1_WDT_B = (1U << 25),
	WAKE_SRC_R12_AP2AP_PEER_WAKEUP_EVENT = (1U << 26),
	WAKE_SRC_R12_SEJ_EVENT_B = (1U << 27),
	WAKE_SRC_R12_SPM_CPU_WAKEUP_EVENT = (1U << 28),
	WAKE_SRC_R12_CPU_IRQOUT = (1U << 29),
	WAKE_SRC_R12_CPU_WFI = (1U << 30),
};

extern const char *wakesrc_str[32];

/* define WAKE_SRC_CONN2AP for conn use */
#define WAKE_SRC_CONN2AP WAKE_SRC_R12_CONN2AP_SPM_WAKEUP_B

#endif /* __pcm_def_h__ */
