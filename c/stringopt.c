#include <string.h>
#include <stdio.h>
#include "stringopt.h"
size_t mystrlen(const char *str);
int mystrcmp(const char *str1, const char *str2);
char *mystrcpy(char *restrict dst, const char *restrict src);
void stringopt()
{
    char a = 'a';
    char *p = &a;
    printf("char * strlen=%lu\n", strlen(p));
    printf("char * mystrlen=%lu\n", mystrlen(p));
    printf("char * sizeof=%lu\n", sizeof(p));

    char line[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    // char line[] = "Hello";
    // char *line = "Hello";
    printf("char array strlen=%lu\n", strlen(line));
    printf("char array mystrlen=%lu\n", mystrlen(line));
    printf("char array sizeof=%lu\n", sizeof(line));

    char a1[] = "abc";
    char a2[] = "abc";
    int result = strcmp(a1, a2);
    printf("using strcmp %s vs %s = %d\n", a1, a2, result);
    result = mystrcmp(a1, a2);
    printf("using mystrcmp %s vs %s = %d\n", a1, a2, result);

    char src[] = "abc";
    char srcNew[] = "xyz";
    char dst[strlen(src)+1];
    strcpy(dst, src);
    mystrcpy(dst, srcNew);
    printf("using strcpy src=%s, dst=%s\n", src, dst);
    printf("using mystrcpy src=%s, dst=%s\n", srcNew, dst);
}
size_t mystrlen(const char *str)
{
    int len = 0;
    printf("mystrlen string is: ");
    while (str[len] != '\0')
    {
        printf("%c", str[len]);
        len++;
    }
    printf("\n");
    return len;
}
int mystrcmp(const char *str1, const char *str2)
{
    while (*str1 == *str2 && *str1 != '\0')
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}
char *mystrcpy(char *restrict dst, const char *restrict src)
{
    char *ret = dst;
    while (*dst++ = *src++)
    {
    }
    *dst = '\0';
    return ret;
}