//Ex2main.c

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Ex2InOut.h"
#include"Ex2Replace.h"

char fn[100], misword[100], crtword[100], newfn[100]; //输入文件名 错误单词 正确单词 输出文件名
char text[200][50]; //文章内容
int pun[200] = {0}; //对应单词是否最后一位含标点 0否1是
int num = 0; //文章单词个数
int nummis = 0; //错误行数量

int main()
{
    input();
    replace();
    outfile();

    printf("\n");
    system("pause");

    return 0;
}