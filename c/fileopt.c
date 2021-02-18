#include "fileopt.h"
#include <stdio.h>
#include <string.h>
void writeToFile()
{
    FILE *fp = fopen("fileout.data", "w");
    if (fp)
    {
        int ret = fprintf(fp, "%s", "1234567890\n123456789");
        printf("文件写入成功，写入%d个字符。\n", ret);
        fflush(fp);
        fclose(fp);
    }
    else
    {
        printf("文件创建失败\n");
    }
}
void readFromFile()
{
    FILE *fp = fopen("fileout.data", "r");
    if (fp)
    {
        const int len = 10;
        char buff[len];
        while (fgets(buff, len, fp) != NULL)
        {
            printf("%s", buff);
            printf("\n---读取了%lu个字符---\n", strlen(buff));
        }
        printf("\n");
        int flag = feof(fp);
        if(flag){
            printf("文件正常读取完毕！\n");
        }else{
            printf("文件读取异常！\n");
        }
        fclose(fp);
    }
    else
    {
        printf("文件打开失败\n");
    }
}
void fileOpt()
{
    writeToFile();
    readFromFile();
}