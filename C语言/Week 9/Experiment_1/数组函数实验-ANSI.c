#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define FOR(i,a,b) for(int i = a; i <= b; i++)

const double eps = 1e-6; //����������  
const int n = 10; //���ݷ�Χ

int dt[100], dts[100], dti[100]; //ԭ������ı�������
int quit = 0, Runtime = 0; //�˳���־ ��һ�����б��

//������������
void CreatDataToFile(); //�������n����
void Read(); //���ļ�������
void FirstMenu(int flag); //һ���˵� flag 0��һ������ 1����������������
void swap(int *a, int *b); //������������ֵ
void BubbleSort(); //ð������
void SelectSort(); //ѡ������
void SecondMenu(int flag); //�����˵�
void Search(); //��������
int BinarySearch(int num); //���ֲ���

//������
int main()
{
    FirstMenu(0);  //һ���˵�
    return 0;
}


//�������n����
void CreatDataToFile() 
{
    char slct; //�����û�ѡ��
    int f = 0, dataMin, dataMax;  //����Ƿ���Ҫָ����Χ

    //-----------------�Ƿ���������---------------
    printf("Is there a need to automatically generate %d data?(Y/N)\nIf you choose NO, you will need to manually enter the data into \"data.txt\" yourself.\nPlease enter...", n);
    scanf("%c", &slct);
    getchar(); //���������
    if(slct == 'N' || slct == 'n') return;

    //-----------------�Ƿ�ָ����Χ----------------
    printf("\nDo you need to specify a data range?\nIf so, please enter 'Y' followed by two integers as the range, otherwise please enter 'N'.\nPlease enter...");
    scanf("%c", &slct);
    getchar();
    if(slct == 'Y' || slct == 'y') 
    {
        f = 1;
        scanf("%d%d", &dataMin, &dataMax);
    }

    //-------------------���������ֵ----------------
    FILE *fp;
    fp = fopen("data.txt","w");
    srand(time(0)); //��ʱ����Ϊ���������
    FOR(i,1,n)
    {
        if(f) fprintf(fp,"%d ", rand()%(dataMax-dataMin+1)+dataMin);
        else fprintf(fp,"%d ", rand());
    }
    fclose(fp);
    printf("Data has been generated into \"data.txt\".\n");
    //system("pause");
    //system("cls"); //����
}

//���ļ�������
void Read()
{
    FILE *fp;
    fp = fopen("data.txt","r");
    FOR(i,1,n)
        fscanf(fp,"%d",&dt[i]);
    fclose(fp);

    printf("Data has been read in from \"data.txt\".\n\n");
}

//������������ֵ
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//ð������
void BubbleSort()
{
    int swapflag; //�Ƿ������� 
    FOR(i,1,n)  //��������
        dts[i] = dt[i];

    FOR(i,1,9)
    {
        swapflag = 0; 
        FOR(j,1,n-i)
            if(dts[j] > dts[j+1]) 
            {
                swapflag = 1;
                swap(&dts[j], &dts[j+1]);
            }
        if(!swapflag) break; //������� �˳�
    }

    printf("Bubble sort completed.\n\n");    
    //�������Ļ
    printf("    Raw data:\n    ");
    FOR(i,1,n)
        printf("%d ",dt[i]);
    printf("\n    Sorted data:\n    ");
    FOR(i,1,n)
        printf("%d ",dts[i]);
    printf("\n\n");    

    FirstMenu(0);
}

//ѡ������
void SelectSort()
{
    FOR(i,1,n)  //��������
        dts[i] = dt[i];
    
    for(int i = n; i >= 1; i--)
    {
        int maxx = i; 
        FOR(j,1,i-1)
            if(dts[j] > dts[maxx]) maxx = j;

        if(maxx != i)
            swap(&dts[maxx], &dts[i]);
    }

    printf("Exchange Maximum sort (select) completed.\n\n");
    //�������Ļ
    printf("    Raw data:\n    ");
    FOR(i,1,n)
        printf("%d ",dt[i]);
    printf("\n    Sorted data:\n    ");
    FOR(i,1,n)
        printf("%d ",dts[i]);
    printf("\n\n");    

    FirstMenu(0);

}

//�����˵�
void SecondMenu(int flag)
{
    float fun;
    if(!flag) printf("  Please select a sort algorithm.\n    2.1 Bubble sort algorithm.\n    2.2 Exchange Maximum sort (select) Algorithm.\n  Please enter...");
    scanf("%f", &fun);
    if(fabs(fun-2.1) < eps) BubbleSort();
    else if(fabs(fun-2.2) < eps) SelectSort();
    else 
    {
        printf("Invalid input, please enter a number again...");
        SecondMenu(1);
    }
}

//���ֲ��Ҳ���
int BinarySearch(int x)
{
    FOR(i,1,n)
        dti[i] = dts[i];

    int l = 1, r = n;
    while(l < r)
    {
        int mid = (l+r)>>1;
        if(dti[mid] >= x) r = mid;
        else l = mid+1;
    }
    
    if(dti[l] == x) printf("%d has been found, at the %d position in Sorted Data.\n\n",x,l);
    else //δ�ҵ� ��������
    {
        int tmp = dti[l];
        dti[l] = x;
        FOR(i,l+1,n+1)
            swap(&tmp, &dti[i]);

        printf("%d has been inserted into the %d position of the sorted data.\n\n",x,l);
        //�������Ļ
        printf("    Sorted data:\n    ");
        FOR(i,1,n)
            printf("%d ",dts[i]);
        printf("\n    Inserted data:\n    ");
        FOR(i,1,n+1)
            printf("%d ",dti[i]);
        printf("\n\n");
    }
}

//��������
void Search()
{
    int num;
    printf("Please enter the number you want to find, if it does not exist, it will be inserted.\n  Please enter...");
    scanf("%d", &num);
    BinarySearch(num);

}

//һ���˵� flag 0��һ������ 1����������������
void FirstMenu(int flag) 
{
    if(quit) return;

    int fun;
    if(!flag) printf("Please select a function to execute.\n  1.Reading the data from the file.\n  2.Sorting algorithms.\n  3.Binary search algorithm.\n  4.Exit this program.\nPlease enter...");
    scanf("%d",&fun);
    getchar(); //���������
    switch(fun)
    {
        case 1:
            CreatDataToFile(); //�������n�������ļ���
            Read();
            FirstMenu(0);
            break;
        case 2:
            SecondMenu(0);
            FirstMenu(0);
            break;
        case 3:
            Search();
            FirstMenu(0);
            break;
        case 4:
            quit = 1;
            return;
        default:   //������Ч
            printf("Invalid input, please enter a number again...");
            FirstMenu(1);
    }
}
