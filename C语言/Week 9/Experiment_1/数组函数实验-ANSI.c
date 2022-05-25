#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define FOR(i,a,b) for(int i = a; i <= b; i++)

const double eps = 1e-6; //浮点数精度  
const int n = 10; //数据范围

int dt[100], dts[100], dti[100]; //原数据与改变后的数据
int quit = 0, Runtime = 0; //退出标志 第一次运行标记

//函数声明部分
void CreatDataToFile(); //随机生成n个数
void Read(); //从文件读数据
void FirstMenu(int flag); //一级菜单 flag 0第一次输入 1输入错误后重新输入
void swap(int *a, int *b); //交换两个数的值
void BubbleSort(); //冒泡排序
void SelectSort(); //选择排序
void SecondMenu(int flag); //二级菜单
void Search(); //搜索插入
int BinarySearch(int num); //二分查找

//主程序
int main()
{
    FirstMenu(0);  //一级菜单
    return 0;
}


//随机生成n个数
void CreatDataToFile() 
{
    char slct; //读入用户选择
    int f = 0, dataMin, dataMax;  //标记是否需要指定范围

    //-----------------是否生成数据---------------
    printf("Is there a need to automatically generate %d data?(Y/N)\nIf you choose NO, you will need to manually enter the data into \"data.txt\" yourself.\nPlease enter...", n);
    scanf("%c", &slct);
    getchar(); //清除缓冲区
    if(slct == 'N' || slct == 'n') return;

    //-----------------是否指定范围----------------
    printf("\nDo you need to specify a data range?\nIf so, please enter 'Y' followed by two integers as the range, otherwise please enter 'N'.\nPlease enter...");
    scanf("%c", &slct);
    getchar();
    if(slct == 'Y' || slct == 'y') 
    {
        f = 1;
        scanf("%d%d", &dataMin, &dataMax);
    }

    //-------------------随机生成数值----------------
    FILE *fp;
    fp = fopen("data.txt","w");
    srand(time(0)); //将时间作为随机数种子
    FOR(i,1,n)
    {
        if(f) fprintf(fp,"%d ", rand()%(dataMax-dataMin+1)+dataMin);
        else fprintf(fp,"%d ", rand());
    }
    fclose(fp);
    printf("Data has been generated into \"data.txt\".\n");
    //system("pause");
    //system("cls"); //清屏
}

//从文件读数据
void Read()
{
    FILE *fp;
    fp = fopen("data.txt","r");
    FOR(i,1,n)
        fscanf(fp,"%d",&dt[i]);
    fclose(fp);

    printf("Data has been read in from \"data.txt\".\n\n");
}

//交换两个数的值
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//冒泡排序
void BubbleSort()
{
    int swapflag; //是否发生交换 
    FOR(i,1,n)  //复制数据
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
        if(!swapflag) break; //排序完成 退出
    }

    printf("Bubble sort completed.\n\n");    
    //输出到屏幕
    printf("    Raw data:\n    ");
    FOR(i,1,n)
        printf("%d ",dt[i]);
    printf("\n    Sorted data:\n    ");
    FOR(i,1,n)
        printf("%d ",dts[i]);
    printf("\n\n");    

    FirstMenu(0);
}

//选择排序
void SelectSort()
{
    FOR(i,1,n)  //复制数据
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
    //输出到屏幕
    printf("    Raw data:\n    ");
    FOR(i,1,n)
        printf("%d ",dt[i]);
    printf("\n    Sorted data:\n    ");
    FOR(i,1,n)
        printf("%d ",dts[i]);
    printf("\n\n");    

    FirstMenu(0);

}

//二级菜单
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

//二分查找插入
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
    else //未找到 插入数字
    {
        int tmp = dti[l];
        dti[l] = x;
        FOR(i,l+1,n+1)
            swap(&tmp, &dti[i]);

        printf("%d has been inserted into the %d position of the sorted data.\n\n",x,l);
        //输出到屏幕
        printf("    Sorted data:\n    ");
        FOR(i,1,n)
            printf("%d ",dts[i]);
        printf("\n    Inserted data:\n    ");
        FOR(i,1,n+1)
            printf("%d ",dti[i]);
        printf("\n\n");
    }
}

//搜索插入
void Search()
{
    int num;
    printf("Please enter the number you want to find, if it does not exist, it will be inserted.\n  Please enter...");
    scanf("%d", &num);
    BinarySearch(num);

}

//一级菜单 flag 0第一次输入 1输入错误后重新输入
void FirstMenu(int flag) 
{
    if(quit) return;

    int fun;
    if(!flag) printf("Please select a function to execute.\n  1.Reading the data from the file.\n  2.Sorting algorithms.\n  3.Binary search algorithm.\n  4.Exit this program.\nPlease enter...");
    scanf("%d",&fun);
    getchar(); //清除缓冲区
    switch(fun)
    {
        case 1:
            CreatDataToFile(); //随机生成n个数到文件中
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
        default:   //输入无效
            printf("Invalid input, please enter a number again...");
            FirstMenu(1);
    }
}
