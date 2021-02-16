#include <string.h>
#include <stdio.h>
#include "stringopt.h"
size_t mystrlen(const char *str);
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