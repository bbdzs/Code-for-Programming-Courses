#include<stdio.h>
#include<string.h>

char fn[100], misword[100], crtword[100], newfn[100]; //�����ļ��� ���󵥴� ��ȷ���� ����ļ���
char text[200][50]; //��������
int pun[200] = {0}; //��Ӧ�����Ƿ����һλ����� 0��1��
int num = 0; //���µ��ʸ���

void input()
{
    printf("Please enter the text file name...");
    scanf("%s", fn);
    printf("Please enter the misspelled word:");
    scanf("%s", misword);
    printf("Please enter the corret word:");
    scanf("%s", crtword);
    printf("Please enter the new file name:");
    scanf("%s", newfn);
    printf("\n");

    FILE *fp;
    fp = fopen(fn, "r");

    char t[100];
    while(fgets(t, 100, fp)) //���ж���ͬʱ���� ���е��ʷָ�
    {
        int tlen = strlen(t);
        int last = 0;  //��¼��һ���ո�λ��
        for(int i = 0; i < tlen; i++) //���ʵ�ǰ�������ַ�
        {
            if( !(t[i] == ' ' || t[i] == '\n') ) continue; //Ѱ�ҵ��ʷָ��־
            
            int len = -1; 
            for(int j = last; j < i; j++) //�����ʷ���text���� 
                text[num][++len] = t[j];
            text[num][++len] = '\0';

            if(text[num][len-1] < 'A' || (text[num][len-1] > 'Z' && text[num][len-1] < 'a') || text[num][len-1] > 'z' )  //���һλ������ĸ �Ǳ�� 
                pun[num] = 1;

            last = i+1;
            num++;
            
            if(t[i] == '\n') //�����з�
            {
                text[num][0] = '\n';
                text[num][1] = '\0';
                num++;
                last = 0;
            }
        }
    }

    fclose(fp);

}

int nummis = 0; //����������
void outmis(int line) //���������
{
    nummis++;
    printf("NO.%d\n", nummis); 

    printf("--The line that contains the misspelled word:\n");
    int pos = line-1;
    while(text[++pos][0] != '\n' && pos < num)
        printf("%s ", text[pos]);
    printf("\n");
}

void outcrt(int a, int b) //���������
{
    printf("--The line after the correction is made:\n");
    for(int j = a; j < b; j++)
        printf("%s ", text[j]);
    printf("\n\n");
}

void replace()
{
    int line = 0, f = 0; //��¼���󵥴������� ��ǰ�������Ƿ��Ѿ����
    for(int i = 0; i < num; i++)
    {
        if(text[i][0] == '\n') 
        {
            if(f) { outcrt(line, i); f = 0; } //ǰ������������� �ٴ������ȷ��

            line = i+1; 
        }

        if(pun[i]) //�����ĵ���
        {
            char t[100], ch[2]; //��ʱ�ַ��� ����ĸ���� 
            strcpy(t, text[i]);
            ch[0] = t[strlen(t)-1];  //������ĸ����
            ch[1] = '\0';
            t[strlen(t)-1] = '\0'; 

            if(!strcmp(t, misword)) //�Ǵ���Ĵ� �����滻�����
            {
                if(!f) { f = 1; outmis(line); } //���������

                strcpy(text[i], crtword);
                strcat(text[i], ch);
            }
        }
        else //�������ĵ���
            if(!strcmp(text[i], misword)) //�Ǵ���Ĵ� �����滻�����
            {
                if(!f) { f = 1; outmis(line); } //���������
            
                strcpy(text[i], crtword);
            }
    }
    
    if(f) { outcrt(line, num); f = 0; } //����βû�������з� �ж��Ƿ���Ҫ���
}

void outfile()
{
    FILE *fp;
    fp = fopen(newfn, "w");

    for(int i = 0; i < num; i++)
    {
        if(text[i][0] == '\n')
            fprintf(fp, "%s", text[i]); //���в���Ҫ�ո�
        else
            fprintf(fp, "%s ", text[i]);
    }
    fclose(fp);

    printf("The correct text has been saved to %s", newfn);
}

int main()
{
    input();
    replace();
    outfile();

    return 0;
}