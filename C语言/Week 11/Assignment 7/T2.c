#include<stdio.h>
#include<string.h>

int main()
{
    char tstr[100], pstr[100];

    printf("Please enter the target string and the pattern string: ");
    scanf("%s%s", &tstr, &pstr);
    
    int flag = 0, pos = 0; //是否匹配成功 首字母位置
    int tlen = strlen(tstr), plen = strlen(pstr); //两字符串长度

    for(int i = 0; i < tlen; i++) //逐位比较字符 外层为target string
    {
        if(tlen-i < plen) break; //目标串不够长 

        pos = i;
        int num = i; //记录目标子串首字母位置 便于操作下标进行比较
        flag = 1;
        for(int j = 0; j < plen; j++)
        {
            if(*(tstr+num) != pstr[j]) { flag = 0; break; } //字符串不一致 
            num++;
        }
        if(flag) break;
    }

    if(flag) 
        printf("The pattern string is in the target. The first letter's position is %d.\n", pos);
    else 
        printf("The pattern string is not in the target.");

    return 0;
}