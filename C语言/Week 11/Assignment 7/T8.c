#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    char str[100][100];

    FILE *fp;
    fp = fopen("t8.txt","r");
    fscanf(fp, "%d", &n);
    for(int i = 1; i <= n; i++)
        fscanf(fp, "%s", str[i]);
    
    //冒泡排序
    for(int i = 1; i < n; i++)
        for(int j = 1; j <= n-i; j++)
        {
            if(strcmp(str[j], str[j+1]) > 0) //交换大的字符串到后面
            {    
                char t[100];
                memcpy(t, str[j], sizeof(str[j]));
                memcpy(str[j], str[j+1], sizeof(str[j+1]));
                memcpy(str[j+1], t, sizeof(t));
            }
        }

    for(int i = 1; i <= n; i++)
        printf("%s\n", str[i]);

    return 0;
}