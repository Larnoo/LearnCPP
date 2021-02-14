#include "swap.h"
void testSwap(int *pa, int *pb)
{
    int t = *pa;
    *pa = *pb;
    *pb = t;
}