//Ex2InOut.c

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"Ex2Global.h"

void input()
{
    printf("Please enter the text file name...");
    scanf("%s", fn);
    printf("Please enter the misspelled word:");
    scanf("%s", misword);
    printf("Please enter the corret word:");
    scanf("%s", crtword);
    printf("Please enter the new file name:");
    scanf("%s", newfn);
    printf("\n");

    FILE *fp;
    fp = fopen(fn, "r");

    char t[300];
    while(fgets(t, 100, fp)) //按行读入同时处理 进行单词分割
    {
        int tlen = strlen(t);
        int last = 0;  //记录上一个空格位置

        for(int i = 0; i < tlen; i++) //访问当前行所有字符
        {
            if(isalpha(t[i])) continue; //寻找单词分割标志 不是字母全部按分割符处理

            if (i - last > 1)
            {
                int len = 0;
                for (int j = last + 1; j < i; j++) //储存单词
                {
                    text[num][len++] = t[j];
                }
                text[num][len] = '\0';
            }

            text[++num][0] = t[i];    //储存分割符
            text[num][1] = '\0';

        
            num++;
            
            last = i;
            if(t[i] == '\n') //处理换行符 需要重置last位置
                last = 0;
        }
    }

    fclose(fp);

}

void outmis(int start) //输出错误行 st记录text数组\n的下一个位置
{
    nummis++;
    printf("NO.%d\n", nummis); 

    printf("--The line that contains the misspelled word:\n");
    int pos = start;
    while (text[pos][0] != '\n' && pos < num) 
    {
        printf("%s", text[pos]);
        pos++;
    }
    printf("\n");
}

void outcrt(int a, int b) //输出改正行
{
    printf("--The line after the correction is made:\n");
    for(int j = a; j < b; j++)
        printf("%s", text[j]);
    printf("\n\n");
}

void outfile() //输出到文件
{
    FILE *fp;
    fp = fopen(newfn, "w");

    for(int i = 0; i < num; i++)
    {
        fprintf(fp, "%s", text[i]); 
    }
    fclose(fp);

    printf("The correct text has been saved to %s", newfn);
}
