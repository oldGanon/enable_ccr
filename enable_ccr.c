#include <linux/module.h>
#include <linux/kernel.h>

MODULE_VERSION("1.0");
MODULE_AUTHOR("oldGanon");
MODULE_DESCRIPTION("Enables user level access to the cycle counting register.");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_SUPPORTED_DEVICE("armv7l");

static void enable_ccr_cpu(void *data)
{
    asm volatile ("mcr p15, 0, %0, c9, c14, 0" : : "r" (1));
    asm volatile ("mcr p15, 0, %0, c9, c14, 2" : : "r" (0x80000000));
    asm volatile ("mcr p15, 0, %0, c9, c12, 0" : : "r" (13));
    asm volatile ("mcr p15, 0, %0, c9, c12, 1" : : "r" (0x80000000));
    asm volatile ("mcr p15, 0, %0, c9, c12, 3" : : "r" (0x80000000));
}

static void disable_ccr_cpu(void *data)
{
    asm volatile ("mcr p15, 0, %0, c9, c14, 0" : : "r" (0));
    asm volatile ("mcr p15, 0, %0, c9, c14, 2" : : "r" (0));
    asm volatile ("mcr p15, 0, %0, c9, c12, 0" : : "r" (0));
    asm volatile ("mcr p15, 0, %0, c9, c12, 1" : : "r" (0));
    asm volatile ("mcr p15, 0, %0, c9, c12, 3" : : "r" (0));
}

int init_module(void)
{
    on_each_cpu(enable_ccr_cpu, 0, 1);
    printk (KERN_INFO "Enabled user level access to the cycle counting register.\n");
    return 0;
}

void cleanup_module(void)
{
    on_each_cpu(disable_ccr_cpu, 0, 1);
    printk (KERN_INFO "Disabled user level access to the cycle counting register.\n");
}

