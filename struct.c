#include<stdio.h>
#include<string.h>
struct date {
 int year;
 int month;
 int day;
};
struct person {
 char *name;
 struct date birthday;
};
struct person* getPerson(struct person *p);
void printPerson(const struct person *p);
void output(struct person p);

int main()
{
  struct person p, *p1;
  char name[8];
  p.name = name;
  printf("sizeof(char): %lu\n", sizeof(char));

  p1 = &p;
  getPerson(p1);
  output(*p1);
  printPerson(p1);
  return 0;
}

struct person* getPerson(struct person *p)
{
  printf("请输入出生年元日：");
  scanf("%d", &p->birthday.year);
  scanf("%d", &(*p).birthday.month);
  scanf("%d", &p->birthday.day);
  printf("请输入名字:");
  scanf("%s", p->name);
  printf("%s\n", p->name);
  return p;
}

void printPerson(const struct person *p)
{
  printf("birthday: %d-%d-%d\n", p->birthday.year, (*p).birthday.month, (*p).birthday.day);
  printf("name: %s\n", p->name);
}

void output(struct person p)
{
  printf("birthday: %d-%d-%d\n", p.birthday.year, p.birthday.month, p.birthday.day);
  printf("name: %s\n", p.name);
  printf("strlen(name): %lu\n", strlen(p.name));
}

