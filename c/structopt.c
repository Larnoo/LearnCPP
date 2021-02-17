#include <stdio.h>
#include "structopt.h"
#include <stdbool.h>
struct point
{
    int x;
    int y;
    int z;
};
typedef struct point Point;
typedef union
{
    int i;
    char ch[sizeof(int)];
} CHI;

void printPoint(struct point p);
void printPointWithPoint(struct point *p);
void structopt()
{
    // struct point
    // {
    //     int x;
    //     int y;
    // };
    // struct point p1, p2;
    // struct point
    // {
    //     int x;
    //     int y;
    //     int z;
    // } p1;
    // struct {
    //     int x;
    //     int y;
    // } p1, p2;
    struct point p1;
    p1.x = 1;
    p1.y = 2;
    p1.z = 3;
    struct point p2 = {4, 5, 6};
    struct point p3 = {.x = 10, .z = 20};
    struct point p4;
    p4 = (struct point){7, 8, 9};
    struct point arr[] = {p1, p2, p3, p4};
    for (size_t i = 0; i < sizeof(arr) / sizeof(struct point); i++)
    {
        printPoint(arr[i]);
    }

    struct point pa, pb;
    pa = (struct point){100, 200, 300};
    pb = pa;
    pa.x = 200;
    printPoint(pa);
    printPointWithPoint(&pa);
    printPoint(pa);
    printPointWithPoint(&pa);
    printPoint(pb);

    Point point = {.x = 100, .z = 300};
    printPointWithPoint(&point);

    CHI chi;
    chi.i = 0x44776655;
    for (int i = 0; i < sizeof(int); i++)
    {
        printf("%c\n", chi.ch[i]);
    }

    printf("sizeof(struct Point) = %lu\n", sizeof(Point));
    printf("sizeof(*p Point) = %lu\n", sizeof(&point));


    printf("sizeof(union CHI) = %lu\n", sizeof(CHI));
    printf("sizeof(*p CHI) = %lu\n", sizeof(&chi));
}
void printPoint(struct point p)
{
    p.x = p.x - 1;
    printf("point x=%d, y=%d, z=%d\n", p.x, p.y, p.z);
}
void printPointWithPoint(struct point *p)
{
    printf("point with *p. x=%d, y=%d, z=%d\n", (*p).x, (*p).y, (*p).z);
    printf("point with p-> x=%d, y=%d, z=%d\n", p->x, p->y, p->z);
}