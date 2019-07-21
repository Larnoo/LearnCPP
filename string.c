#include<stdio.h>
void f(char arr[], int len);
int main()
{ 
  const int count = 3;
  char w1[count];
  char w2[count];
  scanf("%s", w1);
  f(w1, count); 
  f(w2, count); 
  scanf("%s", w2);
  f(w1, count);
  f(w2, count);
  printf("w1=%s, w2=%s\n", w1, w2);
  return 0;
}
void f(char arr[], int len)
{
  for(int i=0; i<len; i++)
  {
    printf("position=%p, value=%c, acsii=%d; ", &arr[i], arr[i], arr[i]);
  }
  printf("\n");
}
