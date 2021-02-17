#include "arrayopt.h"
#include <stdlib.h>
#include <stdio.h>
const int BLOCK = 16;
Array array_create(int init_size)
{
    Array ret;
    ret.capability = init_size;
    ret.array = (int *)malloc(sizeof(int) * ret.capability);
    ret.size = 0;
    return ret;
}
void array_free(Array *a)
{
    free(a->array);
    a->array = NULL;
    a->size = 0;
}
int array_size(const Array *a)
{
    return a->size;
}
int *array_at(Array *a, int index)
{
    if (index >= a->capability)
    {
        array_inflate(a, (index / BLOCK + 1) * BLOCK - a->size);
    }
    if (a->size <= index)
    {
        a->size = index + 1;
    }
    return &(a->array[index]);
}
void array_inflate(Array *a, int more_size)
{
    int target_size = a->capability + more_size;
    int *p = (int *)malloc(sizeof(int) * target_size);
    for (int i = 0; i < a->size; i++)
    {
        // memcpy
        p[i] = a->array[i];
    }
    free(a->array);
    a->array = p;
    a->capability += more_size;
}
void array_print(Array *a)
{
    printf("\nArray capability=%d size=%d\n", a->capability, a->size);
    printf("[");
    for (int i = 0; i < a->size; i++)
    {
        printf("%d, ", a->array[i]);
    }
    printf("]\n\n");
}