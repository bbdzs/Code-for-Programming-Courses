#include<stdio.h>

int main()
{
	int n;
	bool f = 1;
	
	scanf("%d",&n);
	if(n == 1) f = 0;
	else
		for(int i = 2; i*i <= n; i++ )	
			if(n%i == 0) f = 0;
	
	if(f) printf("%d是素数",n); 
	else printf("%d不是素数",n);
	
	return 0;
}
