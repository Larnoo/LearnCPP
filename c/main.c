#include <stdio.h>
void printDataTypeSize();
int main(int argc, char const *argv[])
{
  for (int i = 0; i < argc; i++)
  {
    printf("%d: %s\n", i, argv[i]);
  }
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