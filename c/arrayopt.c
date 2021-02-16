#include "arrayopt.h"
#include <stdlib.h>
#include <stdio.h>
const int BLOCK = 16;
Array array_create(int init_size)
{
    Array ret;
    ret.size = init_size;
    ret.array = (int *)malloc(sizeof(int) * ret.size);
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
    if (index >= a->size)
    {
        array_inflate(a, (index/BLOCK + 1) * BLOCK - a->size);
    }
    return &(a->array[index]);
}
void array_inflate(Array *a, int more_size)
{
    int target_size = a->size + more_size;
    int * p = (int*) malloc(sizeof(int) * target_size);
    for (int i = 0; i < a->size; i++)
    {
        // memcpy
        p[i] = a->array[i];
    }
    free(a->array);
    a->array = p;
    a->size += more_size;
}
void array_print(Array *a)
{
    printf("\nArray size=%d\n", a->size);
    printf("[");
    for (int i = 0; i < a->size; i++)
    {
        printf("%d, ", a->array[i]);
    }
    printf("]\n\n");
    
}