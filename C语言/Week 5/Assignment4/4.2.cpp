#include<stdio.h>
#include<math.h>

int main()
{
	int year;
	scanf("%d",&year);
	
	if(!(year%4) && (year%100) || !(year%400)) 
		printf("%d是闰年",year);
	else 
		printf("%d不是闰年",year);
	
	return 0;
}
