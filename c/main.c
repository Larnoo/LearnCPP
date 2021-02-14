#include <stdio.h>
#include <stdbool.h>
// 编译多个文件：gcc main.c swap.c -o main.ex
#include "swap.h"
void printDataTypeSize();
void printBoolean();
void printSwap();
int main(int argc, char const *argv[])
{
  for (int i = 0; i < argc; i++)
  {
    printf("%d: %s\n", i, argv[i]);
  }
  printDataTypeSize();
  printBoolean();
  printSwap();
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