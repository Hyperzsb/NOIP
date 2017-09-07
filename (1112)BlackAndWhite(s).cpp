#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
void dfs(int i,int j,int** list,int** test,int lin,int ro)
{
    if(test[i][j]==0)
    {
         return ; 
    }
    test[i][j]=0;
    if(i>0)dfs(i-1,j,list,test,lin,ro);
    if(i<lin-1)dfs(i+1,j,list,test,lin,ro);
    if(j>0)dfs(i,j-1,list,test,lin,ro);
    if(j<ro-1)dfs(i,j+1,list,test,lin,ro);
}
int **creat(int m, int n)//创建m行n列的二维数组。
{
    int **r;
    int i;
    r=(int **)malloc(sizeof(int *) *m);//分配m个int*指针内存。
    for(i = 0; i < m; i ++)//遍历每行
        r[i] = (int *)malloc(sizeof(int)*n);//每行分配n个int型元素。
    return r;//返回地址值。
}
int main()
{
    int line,row;
    scanf("%d %d",&line,&row);
    int** maplist=creat(line,row);
    int** isempty=creat(line,row);
    int total=0;
    for(int i=0;i<line;i++)
    {
            for(int j=0;j<row;j++)
            {
                    scanf("%d",&maplist[i][j]);
                    isempty[i][j]=maplist[i][j];
            } 
    }
    for(int p=0;p<line;p++)
    {
            for(int q=0;q<row;q++)
            {
                    if(maplist[p][q]==1&&isempty[p][q])
                    {
                         dfs(p,q,maplist,isempty,line,row);
                         total++;
                    }
            } 
    }
    printf("%d",total);
    return 0;
}

