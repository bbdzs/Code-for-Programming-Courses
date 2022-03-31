#include<stdio.h>

int main()
{
	int maxx = -0x7fffffff, maxx2, minn = 0x7fffffff, minn2;
	FILE *fp;
	fp = fopen("TWOMM.in","r");
	
	for(int i = 1; i <= 20; i++)
	{
		int t;
		fscanf(fp,"%d",&t);
		if(t > maxx) 
		{
			maxx2 = maxx; maxx = t;
		}
		if(t < minn)
		{
			minn2 = minn; minn = t;
		}
	}
	
	printf("The two largest: %d %d\n", maxx, maxx2);
	printf("The two largest: %d %d", minn, minn2);
	
	return 0;	
}
