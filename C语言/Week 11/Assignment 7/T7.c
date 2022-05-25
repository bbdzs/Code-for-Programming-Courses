#include<stdio.h>
#include<string.h>

void bubble(char str[])
{
    int len = strlen(str);
    for(int i = 0; i < len-1; i++)
    {
        for(int j = 0; j < len-1-i; j++)
            if(str[j] > str[j+1])
            {
                char t = str[j+1];
                str[j+1] = str[j];
                str[j] = t;
            }
    }

    printf("%s", str);
}

int main()
{
    char str[100];
    scanf("%s", str);

    bubble(str);

    return 0;
}