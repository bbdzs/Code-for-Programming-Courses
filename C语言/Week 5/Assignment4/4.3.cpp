#include<stdio.h>
#include<math.h>

int main()
{
	FILE *fp, *fp2;
	fp = fopen("GRADE.in","r");
	fp2 = fopen("GRADE.out","w");
	
	for(int i = 1; i <= 10; i++)
	{ 
		int score; 
		fscanf(fp,"%d",&score);
		{
			if(score < 60) fprintf(fp2,"%d   F\n",score);
			else if(60 <= score && score <= 69) fprintf(fp2,"%d   D\n",score);
			else if(70 <= score && score <= 79) fprintf(fp2,"%d   C\n",score);
			else if(80 <= score && score <= 89) fprintf(fp2,"%d   B\n",score);
			else if(90 <= score && score <= 100) fprintf(fp2,"%d   A\n",score);	
		}	
	}
	
	return 0;
}
