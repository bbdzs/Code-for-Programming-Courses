//Ex2Replace.c

#define _CRT_SECURE_NO_WARNINGS

#include<string.h>
#include<stdio.h>
#include"Ex2InOut.h"
#include"Ex2Global.h"

void replace()
{
    int st = 0, f = 0; //记录错误单词行开头位置 当前错误行是否已经输出
    for(int i = 0; i < num; i++)
    {
        if(text[i][0] == '\n') 
        {
            if(f) { outcrt(st, i); f = 0; } //前面输出过错误行 再次输出正确的 输出st到i之间的内容 
            st = i+1; 
        }

        
        if(!strcmp(text[i], misword)) //是错误的词 进行替换并输出
        {
            if(!f) { f = 1; outmis(st); } //输出错误行

            strcpy(text[i], crtword);
        }
    }
    
    if(f) { outcrt(st, num); f = 0; } //到结尾没遇到换行符 判断是否需要输出
}