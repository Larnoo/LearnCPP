#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// 编译多个文件：gcc main.c swap.c -o main.ex
#include "swap.h"
#include "minmax.h"
#include "stringopt.h"
#include "structopt.h"
#include "arrayopt.h"
#include "linkedlist.h"
#include "fileopt.h"
void printDataTypeSize();
void printBoolean();
void printSwap();
void printArray();
void printConst();
void printMalloc();
void printMaxMalloc();
void printCharIO();
void printMutableArray();
void printLinkStruct();
void printGlobalVariable();
void printStaticVariable();
void printScanf();
int gAll, gg;
#define PI 3.14
#define PI2 2 * PI // 2 *PI
#define FORMAT "2*PI=%f\n"
#define PRT          \
  printf(" %f", PI); \
  printf(" %f\n", PI2)
#define cube(x) ((x) * (x) * (x))
int main(int argc, char const *argv[])
{
  for (int i = 0; i < argc; i++)
  {
    char t[] = {'a', '\0'};
    // argv[0] = t; // ok
    // argv[0][0] = 'c'; // Error
    printf("%d: %c: %s\n", i, *argv[i], argv[i]);
  }
  // printDataTypeSize();
  // printBoolean();
  // printSwap();
  // printArray();
  // printConst();
  // printMalloc();
  // printMaxMalloc();
  // printCharIO();
  // stringopt();
  // structopt();
  // printMutableArray();
  // printLinkStruct();
  // printf("%s gAll=%d gg=%d\n", __func__, gAll, gg);
  // printGlobalVariable();
  // printf("%s after gAll=%d gg=%d\n", __func__, gAll, gg);
  // printStaticVariable();
  // printStaticVariable();
  // printStaticVariable();
  // printStaticVariable();
  // printf("radius=2, the cirle area is %f\n", 2*2*PI);
  // printf(FORMAT, PI2);
  // PRT;
  // printf("__LINE__=%d, __FILE__=%s, __STDC__=%d\n", __LINE__, __FILE__, __STDC__);
  // printf("cube(5)=%d\n",cube(5));
  // printf("arrayopt.h extern int BLOCK=%d\n", BLOCK);
  // printScanf();
  fileOpt();
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
void printConst()
{
  const int a = 10;
  int b = 20;
  // a = 5; // error
  b = 30;
  // int *const p = &a; // ok
  // p = &b; // error
  // *p = 50; // ok

  const int *q = &a;
  // *q = 33;
  q = &b;

  const int *const s = &a;
  // s = &b;
  // *s = 33;
}
void printMalloc()
{
  printf("sizeof(size_t)=%lu\n", sizeof(size_t));
  int n = 5;
  int *a = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    // *(a++) = i*5;
    *(a + i) = i * 5;
  }
  for (int i = 0; i < n; i++)
  {
    printf("array a[%d]=%d\n", i, a[i]);
  }
  free(a);
}
void printMaxMalloc()
{
  void *p = NULL;
  int count = 0;
  while ((p = malloc(1024 * 1024 * 1024)))
  {
    count++;
  }
  printf("分配了%dGB的内存空间\n", count);
}
void printCharIO()
{
  int c;
  while ((c = getchar()) != EOF)
  {
    putchar(c);
  }
  printf("EOF\n");
}
void printMutableArray()
{
  Array a = array_create(3);
  Array *pa = &a;
  *array_at(pa, 0) = 10;
  *array_at(pa, 1) = 20;
  *array_at(pa, 2) = 30;
  array_print(pa);
  *array_at(pa, 8) = 80;
  array_print(pa);
  array_free(pa);

  printf("sizeof(struct Array) = %lu\n", sizeof(Array));
  printf("sizeof(*p Array) = %lu\n", sizeof(pa));
}
void printLinkStruct()
{
  LinkedList list;
  list.head = NULL;
  linked_list_add(&list, 0);
  linked_list_add(&list, 1);
  linked_list_add(&list, 2);
  linked_list_add(&list, 3);
  printLinkedList(&list);
  linked_list_remove(&list, 2);
  printLinkedList(&list);
}
void printGlobalVariable()
{
  int gg = 20;
  printf("%s gAll=%d gg=%d\n", __func__, gAll, gg);
  gAll++;
  gg++;
  printf("%s after gAll=%d gg=%d\n", __func__, gAll, gg);
}
void printStaticVariable()
{
  static int all = 33;
  all += 2;
  printf("%s *gg=%p *i=%p i=%d\n", __func__, &gg, &all, all);
}
void printScanf()
{
  printf("%+08d\n", 123);
  printf("%+08d\n", -123);

  printf("%+012.5f\n", 123.456);
  printf("%+012.5f\n", -123.456);

  printf("%+0*.*f\n", 12, 5, 123.456);
  printf("%+0*.*f\n", 12, 5, -123.456);

  printf("%hhd\n", 12345);
  printf("%hd\n", 12345);

  int n;
  printf("%hhd hello! %n\n", 12345, &n);
  printf("output char count is %d\n", n);

  int a = scanf("%*d%d", &n);
  int b = printf("input %d\n", n);
  printf("scanf=%d, printf=%d\n", a, b);
}