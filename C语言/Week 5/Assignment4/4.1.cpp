#include<stdio.h>
#include<math.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int delta;
	delta = b*b-4*a*c;
	
	double x1,x2;
	x1 = (-b+double(sqrt(delta)))/double(2*a);
	x2 = (-b-double(sqrt(delta)))/double(2*a);
	if(delta < 0) printf("此方程无解");
	else if(delta == 0) printf("方程的根为0"); 
	else printf("方程的两个根分别为\n%lf\n%lf",x1,x2);
	
	return 0;
}
