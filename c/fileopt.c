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
        if (flag)
        {
            printf("文件正常读取完毕！\n");
        }
        else
        {
            printf("文件读取异常！\n");
        }
        fclose(fp);
    }
    else
    {
        printf("文件打开失败\n");
    }
}
void writeBinaryFile()
{
    FILE *fp = fopen("fileout.binary", "w");
    if (fp)
    {
        char data[3] = {1, 255, 3};
        for (int i = 0; i < 3; i++)
        {
            //二进制文件，每次写入3个字节：0x01 0xff 0x03。写10次。
            fwrite(&data, sizeof(char), 3, fp);
        }
        fflush(fp);
        fclose(fp);
        printf("文件写入成功\n");
    }
    else
    {
        printf("文件创建失败\n");
    }
}
char *charToBit(char *strPtr, char c)
{
    unsigned int mask = 0x1;
    for (int i = 7; i >= 0; i--)
    {
        char r = c & mask;
        strPtr[i] = r ? '1' : '0';
        mask = mask << 1;
    }
    return strPtr;
}
void readBinaryFile()
{
    FILE *fp = fopen("fileout.binary", "r");
    if (fp)
    {
        char data[2];
        int readCount = 0;
        char charBitStr[9] = {0};
        while ((readCount = fread(&data, sizeof(char), 2, fp)) != 0)
        {
            for (int i = 0; i < readCount; i++)
            {
                printf("0x%hhx\n", data[i]);
                printf("%s\n", charToBit(charBitStr, data[i]));
            }
        }
        printf("\n");
        int flag = feof(fp);
        if (flag)
        {
            printf("文件正常读取完毕！\n");
        }
        else
        {
            printf("文件读取异常！\n");
        }
        fclose(fp);
    }
    else
    {
        printf("文件读取失败\n");
    }
}
void fileOpt()
{
    // writeToFile();
    // readFromFile();
    writeBinaryFile();
    readBinaryFile();
}