#include "reference.h"
#include <iostream>
void swapByValue(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}
void swapByReference(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
void swapByPoint(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void testReferenceVariable()
{
    int a={5}, b={6};
    const char *s1 = "print init ";
    const char *s2 = "swapByValue ";
    const char *s3 = "swapByPoint";
    const char *s4 = "swapByReference";
    const char *&sr = s1;
    std::cout << sr << "a=" << a << ", b=" << b << std::endl;
    swapByValue(a, b);
    sr = s2;
    std::cout << sr << "a=" << a << ", b=" << b << std::endl;
    swapByPoint(&a, &b);
    sr = s3;
    std::cout << sr << "a=" << a << ", b=" << b << std::endl;
    swapByReference(a, b);
    sr = s4;
    std::cout << sr << "a=" << a << ", b=" << b << std::endl;
}