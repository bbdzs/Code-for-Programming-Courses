#include<stdio.h>
#include<math.h>

int main()
{
	int year;
	scanf("%d",&year);
	
	if(!(year%4) && (year%100) || !(year%400)) 
		printf("%d������",year);
	else 
		printf("%d��������",year);
	
	return 0;
}
