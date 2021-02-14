#include<stdio.h>
#include<stdlib.h>

enum color { red, yellow, green };

void f(enum color c);

struct date {
  int month;
  int day;
  int year;
};

int main(int argc, char const *argv[]){
  int i;
  for(i=0; i<argc; i++){
    printf("%d: %s\n", i,argv[i]);
  }
  enum color t;
  scanf("%d", &t);
  f(t);

  struct date tody;
  return 0;
}

void f(enum color c){
  printf("%d\n", c);
}

