#include<string.h>
#include<stdio.h>

int main()
{
    char str1[100], str2[100];
    int len1, len2, flag = 1, cnt[150];

    memset(cnt, 0, sizeof(cnt));

    printf("Enter the first word: ");
    scanf("%s", str1);
    printf("Enter the second word: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    if(len1 != len2) flag = 0; //长度不同 不可能是anagram
    else if(!strcmp(str1, str2)) flag = 0; //两字符串相同
    else
    {
        for(int i = 0; i < len1; i++)
            cnt[str1[i]]++;  //对每个字母计数
        for(int i = 0; i < len2; i++)
            cnt[str2[i]]--;  
        for(int i = 'A'; i <= 'z'; i++)
            if(cnt[i])   //两单词的字母个数不同 不是anagram
            {
                flag = 0;
                break;
            }
    }

    if(flag) 
        printf("The words are anagrams.");
    else
        printf("The words are not anagrams.");
        
    return 0;
}