#include<stdio.h>
#include<stdlib.h>
int main()
{
  int number;
  int *arr;
  printf("请输入number:");
  scanf("%d", &number);
  // int a[number];
  arr= malloc(number*sizeof(int));
  for(int i = 0; i<number; i++){
    scanf("%d", &arr[i]);
  }

  for(int i=number-1; i>=0; i--){
    printf("%d", arr[i]);
  }
  free(arr);
  printf("\n");

  int count = 0;
  void *p = 0;
  while( (p=malloc(100*1024*1024)) ){
    count++;
    printf("count=%d\n",count);
  }
  printf("最多申请%dM内存", count);
  return 0;
}
