#include <stdio.h>
#include <stdlib.h>
#include "ccr.h"

int main()
{
//    init_perfcounters(1, 0);
    unsigned int begin = ccr_read();

    int a = 0;
    for (int i = 0; i < 1000; ++i)
        a += i;

    unsigned int end = ccr_read();
    printf("begin: %d cycles!\n", begin);
    printf("end: %d cycles!\n", end);
    printf("diff: %d cycles!\n", end - begin);

    return 1;
}
