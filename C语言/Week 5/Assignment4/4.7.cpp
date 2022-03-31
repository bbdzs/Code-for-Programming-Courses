#include<stdio.h>

int main()
{
	double pi = 0;
	double sum = 0;
	
	for(int i = 3; i <= 1000000; i+=4)
		sum -= double(1.0/double(i));
	for(int i = 1; i <= 1000000; i+=4)
		sum += double(1.0/double(i));
	pi = 4*sum;
	
	printf("%lf", pi);	
	return 0;
}
