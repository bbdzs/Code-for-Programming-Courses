//Ex2Replace.c

#define _CRT_SECURE_NO_WARNINGS

#include<string.h>
#include<stdio.h>
#include"Ex2InOut.h"
#include"Ex2Global.h"

void replace()
{
    int line = 0, f = 0; //记录错误单词所在行 当前错误行是否已经输出
    for(int i = 0; i < num; i++)
    {
        if(text[i][0] == '\n') 
        {
            if(f) { outcrt(line, i); f = 0; } //前面输出过错误行 再次输出正确的

            line = i+1; 
        }

        if(pun[i]) //含标点的单词
        {
            char t[100], ch[2]; //临时字符串 存字母与标点 
            strcpy(t, text[i]);
            ch[0] = t[strlen(t)-1];  //分离字母与标点
            ch[1] = '\0';
            t[strlen(t)-1] = '\0'; 

            if(!strcmp(t, misword)) //是错误的词 进行替换并输出
            {
                if(!f) { f = 1; outmis(line); } //输出错误行

                strcpy(text[i], crtword);
                strcat(text[i], ch);
            }
        }
        else //不含标点的单词
            if(!strcmp(text[i], misword)) //是错误的词 进行替换并输出
            {
                if(!f) { f = 1; outmis(line); } //输出错误行
            
                strcpy(text[i], crtword);
            }
    }
    
    if(f) { outcrt(line, num); f = 0; } //到结尾没遇到换行符 判断是否需要输出
}