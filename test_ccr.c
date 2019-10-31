#include <stdio.h>
#include <stdlib.h>
#include "ccr.h"

int main()
{
//    init_perfcounters(1, 0);
    unsigned long long begin = ccr_read();

    int a = 0;
    for (int i = 0; i < 1000; ++i)
        a += i;

    unsigned long long end = ccr_read();
    printf("begin: %llu cycles!\n", begin);
    printf("end: %llu cycles!\n", end);
    printf("diff: %llu cycles!\n", end - begin);

    return 1;
}
