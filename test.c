#include<stdio.h>
#include<string.h>
int main()
{

{
int a = 6, b = 0, c = 3;
printf("%d\n", (a&&b)||(b-c));
}

char ch = -1;
printf("%d\n", ch);

char a[20]="cehiknqtw";
char *s="fbla",*p;
int i, j;
for(p=s; *p; p++) {
   j=0;
   while (*p>=a[j] && a[j]!='\0') j++;
   for(i=strlen(a); i>=j; i--) a[i+1] = a[i];
   a[j]=*p;
}
printf("%s\n", a);


 return 0;
}
