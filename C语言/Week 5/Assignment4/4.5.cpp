#include<stdio.h>
#include<math.h>
char mon[13][10]={"","January","February","March","April","May","June","July","August","September","October","November","December"};
int main()
{
	int m,d,y;
	scanf("%d/%d/%d",&m,&d,&y);
	printf("Dated this ");
	switch(d)
	{
		case(1):
			printf("%dst",d);
			break;
		case(2):
			printf("%dnd",d);
			break;
		case(3):
			printf("%drd",d);
			break;
		default:
			printf("%dth",d);
	}
	
	printf(" day of %s, 20%d.",&mon[m][0],y);
	
	return 0;
}
