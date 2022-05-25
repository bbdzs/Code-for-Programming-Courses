#include<stdio.h>
#include<string.h>

char fn[100], misword[100], crtword[100], newfn[100]; //输入文件名 错误单词 正确单词 输出文件名
char text[200][50]; //文章内容
int pun[200] = {0}; //对应单词是否最后一位含标点 0否1是
int num = 0; //文章单词个数

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
    while(fgets(t, 100, fp)) //按行读入同时处理 进行单词分割
    {
        int tlen = strlen(t);
        int last = 0;  //记录上一个空格位置
        for(int i = 0; i < tlen; i++) //访问当前行所有字符
        {
            if( !(t[i] == ' ' || t[i] == '\n') ) continue; //寻找单词分割标志
            
            int len = -1; 
            for(int j = last; j < i; j++) //将单词放入text数组 
                text[num][++len] = t[j];
            text[num][++len] = '\0';

            if(text[num][len-1] < 'A' || (text[num][len-1] > 'Z' && text[num][len-1] < 'a') || text[num][len-1] > 'z' )  //最后一位不是字母 是标点 
                pun[num] = 1;

            last = i+1;
            num++;
            
            if(t[i] == '\n') //处理换行符
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

int nummis = 0; //错误行数量
void outmis(int line) //输出错误行
{
    nummis++;
    printf("NO.%d\n", nummis); 

    printf("--The line that contains the misspelled word:\n");
    int pos = line-1;
    while(text[++pos][0] != '\n' && pos < num)
        printf("%s ", text[pos]);
    printf("\n");
}

void outcrt(int a, int b) //输出改正行
{
    printf("--The line after the correction is made:\n");
    for(int j = a; j < b; j++)
        printf("%s ", text[j]);
    printf("\n\n");
}

void replace()
{
    int line = 0, f = 0; //记录错误单词所在行 当前错误行是否已经输出
    for(int i = 0; i < num; i++)
    {
        if(text[i][0] == '\n') 
        {
            if(f) { outcrt(line, i); f = 0; } //前面输出过错误行 再次输出正确的

            line = i+1; 
        }

        if(pun[i]) //含标点的单词
        {
            char t[100], ch[2]; //临时字符串 存字母与标点 
            strcpy(t, text[i]);
            ch[0] = t[strlen(t)-1];  //分离字母与标点
            ch[1] = '\0';
            t[strlen(t)-1] = '\0'; 

            if(!strcmp(t, misword)) //是错误的词 进行替换并输出
            {
                if(!f) { f = 1; outmis(line); } //输出错误行

                strcpy(text[i], crtword);
                strcat(text[i], ch);
            }
        }
        else //不含标点的单词
            if(!strcmp(text[i], misword)) //是错误的词 进行替换并输出
            {
                if(!f) { f = 1; outmis(line); } //输出错误行
            
                strcpy(text[i], crtword);
            }
    }
    
    if(f) { outcrt(line, num); f = 0; } //到结尾没遇到换行符 判断是否需要输出
}

void outfile()
{
    FILE *fp;
    fp = fopen(newfn, "w");

    for(int i = 0; i < num; i++)
    {
        if(text[i][0] == '\n')
            fprintf(fp, "%s", text[i]); //新行不需要空格
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