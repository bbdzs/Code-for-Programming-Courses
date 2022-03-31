#include<stdio.h>
#include<math.h>

char mon[13][10]={"","January","February","March","April","May","June","July","August","September","October","November","December"};
int month, day;
int ans;

int cal(int m)
{
	switch(m)
	{
		case 1: 
			return 31;
			break;
		case 2:	
			return 28; //I don't know what year the title was asked for. 
						//So I calculated by 2022. It's not a leap year. 
			break;			
		case 3:
			return 31;
			break;
		case 4:	
			return 30;
			break;
		case 5:
			return 31;
			break;
		case 6:	
			return 30;
			break;
		case 7:
			return 31;
			break;
		case 8:
			return 31;
			break;
		case 9:	
			return 30;
			break;
		case 10:
			return 31;
			break;
		case 11:	
			return 30;
			break;
		case 12:
			return 31;
			break;
	}
}

int change()
{
	int num = 0;
	for(int i = 1; i < month; i++)
		num += cal(i); //计算i月有多少天 
	num += day;
	return (num-1);
}

int main()
{
	int n;
	FILE *fp,*fp2;
	fp = fopen("days.in","r");
	fp2 = fopen("days.out","w");
	
	fscanf(fp,"%d",&n);
	for(int i = 1; i <= n; i++)
	{
		fscanf(fp,"%d%d",&month,&day);
		ans = change();
		fprintf(fp2,"%-3d %-10s",day,&mon[month][0]);
		fprintf(fp2,"距1月1日有%d天\n",ans);
	}
	
	return 0;
}
