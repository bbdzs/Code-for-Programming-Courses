#include<stdio.h>

/*
	ÿ�� 2i-1 �� * 
	ǰn�� �����2n-1-(2i-1)=2(n-i)���ո�   2i-1�� * 
	(��n�� 2n-1 �� *   0���ո�) 
	n+1...2n-1�� ��2n-i�и���һ�� ���˳���෴ 
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
