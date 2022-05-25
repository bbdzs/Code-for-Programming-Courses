#include<stdio.h>
#include<string.h>

int mystrlen(char *p)
{
    int cnt = 0;
    while(*p != '\0')
    {
        cnt++;
        p++;
    }

    return cnt;
}

void mystrcat(char *a, char *b)
{
    int num1 = 0, num2 = 0;
    while(*(a+num1) != '\0')
        num1++;
    while(*(b+num2) != '\0')
    {
        *(a+num1) = *(b+num2);
        num1++;
        num2++;
    }
    *(a+num1) = *(b+num2); //复制\0

}

int mystrcmp(char *a, char *b)
{
    int flag = 1;
    int cmp;
    int num1 = 0, num2 = 0;
    while(*(a+num1) != '\0' && *(b+num2) != '\0')
    {
        int t = *(a+num1) - *(b+num2);
        if(t > 0) 
        {
            flag = 0;
            cmp = 1; //前面大
            break;
        }
        else if (t < 0)
        {
            flag = 0;
            cmp = -1; //后面大
            break;
        }

        num1++; num2++;
    }
    
    if(*(a+num1) != '\0') //b是a的子串 
    {
        flag = 0;
        cmp = 1;
    }
    if(*(b+num2) != '\0') //a是b的子串 
    {
        flag = 0;
        cmp = -1;
    }

    if(flag) return 0; //相同
    else return cmp;
}

char *mysubstr(char *str, int offset, int length)
{
    char *str2;
    int num = 0;

    for(int i = offset; i < offset+length; i++)
    {
        *(str2+num) = *(str+i);
        num++;
    }
    *(str2+num) = '\0';
    return str2; 
}

int main()
{
    char a[100], b[100], c[100];

    scanf("%s%s", &a, &b);

    strcpy(c, a);

    int len = mystrlen(a);
    printf("%s length: %d\n", a, len);
    
    mystrcat(c, b);
    printf("after mystrcat: %s\n", c);
    
    int cmp = mystrcmp(a, b);
    printf("after mystrcmp(\"%s\", \"%s\"): %d\n", a, b, cmp);

    char *d = mysubstr(a, 1, 2);
    printf("after mysubstr(\"%s\", 1, 2): %s", a, d);

    return 0;
}