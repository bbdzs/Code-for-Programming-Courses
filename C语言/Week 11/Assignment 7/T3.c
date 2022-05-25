#include<stdio.h>
#include<string.h>

int main()
{
    FILE *fp;
    fp = fopen("t3.txt", "r");

    int n;
    char str[100][100];
    char sml[100], lag[100];
    
    fscanf(fp, "%d", &n);
    for(int i = 0; i < n; i++)
        fscanf(fp, "%s", str+i);

    strcpy(sml, str[0]);
    strcpy(lag, str[0]);

    for(int i = 0; i < n; i++)
    {
        if(strcmp(str[i], sml) < 0) strcpy(sml, str[i]); //有更小的
        if(strcmp(str[i], lag) > 0) strcpy(lag, str[i]); //有更大的
    }

    printf("The largest string is %s.\n The smallest string is %s.", lag, sml);

    return 0;
}