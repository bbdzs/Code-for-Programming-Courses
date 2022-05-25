#include<string.h>
#include<stdio.h>

int main()
{
    char str[100][100], ch; //句子 标点 
    int num = 0; //单词计数

    while(scanf("%s", str+num) != EOF)
        num++;
    
    int len = strlen(str[num-1]);
    ch = str[num-1][len-1];  //处理最后的符号
    str[num-1][len-1] = '\0';

    for(int i = num-1; i > 0; i--)
        printf("%s ", str[i]);
    printf("%s%c", str[0], ch); //输出最后一个单词和符号
    return 0;
}