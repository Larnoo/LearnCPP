#ifndef _arrayopt_
#define _arrayopt_
typedef struct {
    int size;
    int capability;
    int* array;
} Array;
extern int BLOCK;
Array array_create(int init_size);
void array_free(Array *a);
int array_size(const Array *a);
int* array_at(Array *a, int index);
void array_inflate(Array *a, int more_size);
void array_print(Array *a);
#endif