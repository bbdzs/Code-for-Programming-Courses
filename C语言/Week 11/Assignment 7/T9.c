#include<stdio.h>
#include<string.h>

int max(int a, int b)
{
    return a>b ? a : b;
}

int LCS(char a[], char b[], int x, int y)
{
    if(x == 0 || y == 0) return 0; //边界
    
    if(a[x] == b[y]) 
        return LCS(a, b, x-1, y-1) + 1;
    else 
        return max( LCS(a, b, x-1, y), LCS(a, b, x, y-1) );
}

int main()
{

    char a[100] = " ", b[100] = " ", t1[100], t2[100];
    int alen, blen, lcs = 0;
    double ans = 0; //相似度

    printf("Please enter two strings:\n");
    scanf("%s%s", t1, t2);

    alen = strlen(t1); 
    blen = strlen(t2);

    strcat(a, t1); strcat(b, t2); //首位留空 便于处理边界 

    lcs = LCS(a, b, alen, blen);
    //printf("%d\n", lcs);

    ans = (double)1/(lcs+1);
    printf("Their similarity is %lf", ans);

    return 0;
}