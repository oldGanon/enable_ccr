static inline unsigned int ccr_read (void)
{
    unsigned int value;
    asm volatile ("mrc p15, 0, %0, c9, c13, 0" : "=r" (value));
    return value << 6;
}

static inline void ccr_reset()
{
    asm volatile ("mcr p15, 0, %0, c9, c12, 0" : : "r" (13));
}
