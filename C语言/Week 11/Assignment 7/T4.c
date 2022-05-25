#include<stdio.h>
#include<string.h>

int main()
{
    FILE *fp;
    fp = fopen("file1.txt", "r");

    char ch[100], ostr[100], estr[100];
    int sa; //加密间隔
    
    while( fgets(ch, 81, fp) != NULL) //读入文件全部内容
        strcat(ostr, ch);
    fclose(fp);
    
    printf("\nPlease enter the shift amount(from 0 to 26):");
    scanf("%d", &sa);

    for(int i = 0; i < strlen(ostr); i++)
    {
        char t = ostr[i];
        if(t < 'A' || t > 'z' || ('Z' < t && t < 'a') ) //不是字母 直接复制不处理
        {  
            estr[i] = t;
            continue; 
        }

        if('a' < t && t < 'z')  //小写字母
            estr[i] = (t+sa > 'z') ? (t+sa-26) : (t+sa);

        if('A' < t && t < 'Z')  //大写字母
            estr[i] = (t+sa > 'Z') ? (t+sa-26) : (t+sa);
        
    }

    fp = fopen("file2.txt","w");
    fprintf(fp, "The encrypted message:\n%s", estr);
    fclose(fp);

    return 0;
}