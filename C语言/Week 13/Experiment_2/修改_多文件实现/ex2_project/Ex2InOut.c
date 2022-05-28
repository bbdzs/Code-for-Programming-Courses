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

    char t[100];
    while(fgets(t, 100, fp)) //按行读入同时处理 进行单词分割
    {
        int tlen = strlen(t);
        int last = 0;  //记录上一个空格位置
        for(int i = 0; i < tlen; i++) //访问当前行所有字符
        {
            if( !(t[i] == ' ' || t[i] == '\n') ) continue; //寻找单词分割标志
            if (i == 0 && t[i] == ' ') continue; //特判开头第一位是空格 第二位是字母的情况 防止越界
            if (t[i] == ' ' && t[i - 1] == ' ') continue; //当前是空格 但上一个不是单词，说明不是分割标志，继续往下找


            int len = 0;
            for(int j = last; j < i; j++) //将单词放入text数组 
                text[num][len++] = t[j];
            text[num][len] = '\0';
            

            //只有last = i = 0时才会跳过上面len++的循环 导致len-1 = -1数组越界  但此情况开头是空格，第二位是字母  上面已经特判 故不可能发生数组越界
            if( len > 1 && !isalpha(text[num][len-1]) )  //最后一位不是字母 是标点    当遇到空格+换行符时空格会被单独保存下来，需要排除字符串只含一个空格的情况 否则replace函数分离数组时数组会越界
                pun[num] = 1;
            

            last = i+1;
            num++;
            
            if(t[i] == '\n') //处理换行符 上面存单词时不包括第i位 故换行符不会重复
            {
                text[num][0] = '\n';
                text[num][1] = '\0';
                num++;
                last = 0;
            }
        }
    }

    fclose(fp);

}

void outmis(int line) //输出错误行 line记录text数组\n的下一个位置
{
    nummis++;
    printf("NO.%d\n", nummis); 

    printf("--The line that contains the misspelled word:\n");
    int pos = line-1;
    while (text[++pos][0] != '\n' && pos < num) //++pos直接从下一行行首内容开始输出 换行符在上面提示信息最后已经输出了
    {
        printf("%s ", text[pos]);
    }
    printf("\n");
}

void outcrt(int a, int b) //输出改正行
{
    printf("--The line after the correction is made:\n");
    for(int j = a; j < b; j++)
        printf("%s ", text[j]);
    printf("\n\n");
}

void outfile() //输出到文件
{
    FILE *fp;
    fp = fopen(newfn, "w");

    for(int i = 0; i < num; i++)
    {
        if(text[i][0] == '\n')
            fprintf(fp, "%s", text[i]); //新行不需要空格
        else
            fprintf(fp, "%s ", text[i]);
    }
    fclose(fp);

    printf("The correct text has been saved to %s", newfn);
}
