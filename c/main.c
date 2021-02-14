#include <stdio.h>
#include <stdbool.h>
// 编译多个文件：gcc main.c swap.c -o main.ex
#include "swap.h"
#include "minmax.h"
void printDataTypeSize();
void printBoolean();
void printSwap();
void printArray();
int main(int argc, char const *argv[])
{
  for (int i = 0; i < argc; i++)
  {
    printf("%d: %s\n", i, argv[i]);
  }
  printDataTypeSize();
  printBoolean();
  printSwap();
  printArray();
  return 0;
}
// 获取基本数据类型的内存字节大小
void printDataTypeSize()
{
  printf("sizeof(char)=%ld\n", sizeof(char));
  printf("sizeof(short)=%ld\n", sizeof(short));
  printf("sizeof(int)=%ld\n", sizeof(int));
  printf("sizeof(float)=%ld\n", sizeof(float));
  printf("sizeof(long)=%ld\n", sizeof(long));
  printf("sizeof(double)=%ld\n", sizeof(double));
}
void printBoolean()
{
  bool a = true;
  printf("sizeof(bool)=%ld\n", sizeof(a));
}
void printSwap()
{
  int a = 4;
  int b = 5;
  printf("swap before a=%d, b=%d\n", a, b);
  testSwap(&a, &b);
  printf("swap after a=%d, b=%d\n", a, b);
}
void printArray()
{
  int a[] = {1, 2, 3, 5, 44, 88, 72};
  int min, max;
  printf("sizeof(a)=%lu, sizeof(a[0])=%lu\n", sizeof(a), sizeof(a[0]));
  printf("sizeof(sizeof return)=%lu\n", sizeof(sizeof(a)));
  printf("a=%p\n", a);
  int len = sizeof(a) / sizeof(a[0]);
  minmax(a, len, &min, &max);
  printf("min=%d, max=%d\n", min, max);
}