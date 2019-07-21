#include<stdio.h>
#include<string.h>
int main()
{
  char line[] = "hello";
  // 获取字符串长度
  printf("strlen=%lu\n", strlen(line));
  printf("sizeof=%lu\n", sizeof(line));

  // 比较字符串是否相同
  char a[] = "abc";
  char b[] = "aac";
  int flag = strcmp(a, b);
  if(flag==0)
  {
   printf("a==b\n");
  } else if(flag < 0){
   printf("a<b\n");
  } else if(flag > 0){
    printf("a>b\n");
  }
  // 复制字符串  strcpy
  // 拼接字符串  strcat
  return 0;
}
