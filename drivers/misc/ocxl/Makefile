# SPDX-License-Identifier: GPL-2.0+
ccflags-$(CONFIG_PPC_WERROR)	+= 

ocxl-y				+= main.o pci.o config.o file.o pasid.o
ocxl-y				+= link.o context.o afu_irq.o sysfs.o trace.o
obj-$(CONFIG_OCXL)		+= ocxl.o

# For tracepoints to include our trace.h from tracepoint infrastructure:
CFLAGS_trace.o := -I$(src)

# ccflags-y += -DDEBUG
