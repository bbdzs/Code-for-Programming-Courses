#include<stdio.h>

/*
	每行 2i-1 个 * 
	前n行 先输出2n-1-(2i-1)=2(n-i)个空格   2i-1个 * 
	(第n行 2n-1 个 *   0个空格) 
	n+1...2n-1行 与2n-i行个数一样 输出顺序相反 
	               n-(2n-i)=i-n  
*/

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= 2*n-1; i++)
	{
		if(i <= n)
		{
			for(int j = 1; j <= 2*(n-i); j++)
				printf(" ");
			for(int j = 1; j <= 2*i-1; j++)
				printf("*");
		}
		else
		{
			for(int j = 1; j <= 2*(2*n-i)-1; j++)
				printf("*");
			for(int j = 1; j <= 2*(i-n); j++)
				printf(" ");
		}
		printf("\n");
	}
}
