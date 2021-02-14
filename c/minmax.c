#include "minmax.h"
#include <stdio.h>
void minmax(int a[], int len, int *min, int *max)
{
    printf("minmax sizeof(a)=%lu\n", sizeof(a));
    printf("minmax a=%p\n", a);
    *min = *max = a[0];
    for (int i = 1; i < len; i++)
    {
        if (a[i] < *min)
        {
            *min = a[i];
        }
        else if (a[i] > *max)
        {
            *max = a[i];
        }
    }
}