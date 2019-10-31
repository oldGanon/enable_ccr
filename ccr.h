static inline unsigned long long ccr_read (void)
{
    unsigned int value;
    __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0" : "=r" (value));
    return (unsigned long long)value << 6;
}

static inline void ccr_reset()
{
    __asm__ volatile ("mcr p15, 0, %0, c9, c12, 0" : : "r" (13));
}
