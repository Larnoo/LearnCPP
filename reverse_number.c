#include<stdio.h>
int main()
{
 for(int i =0; i<1000; i++)
 {
  int input = i;
  printf("你输入的是: %d\n",input);

  int number = 0;
  do {
    number = number * 10;
    number += input%10;
    input = input/10;
  } while(input>0);

  printf("输出是：%d\n",number);
  printf("\n");
 }

 return 0;
}
