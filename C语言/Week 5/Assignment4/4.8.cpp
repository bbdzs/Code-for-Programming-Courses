#include<stdio.h>

int fib[100]; 

int main()
{
	fib[1] = 1;
	fib[2] = 1;
	for(int i = 3; i <= 40; i++)
		fib[i] = fib[i-1]+fib[i-2];
	
	for(int i = 1; i <= 40; i++)
	{	
		printf("%d ",fib[i]);
		if(i%10 == 0) printf("\n");
	}
	
	return 0;
}
