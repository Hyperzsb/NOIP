#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
void dfs(int i,int j,int** list,int lin,int ro)
{
    if(list[i][j]==0)
    {
         return ; 
    }
    list[i][j]=0;
    if(i>0)dfs(i-1,j,list,lin,ro);
    if(i<lin-1)dfs(i+1,j,list,lin,ro);
    if(j>0)dfs(i,j-1,list,lin,ro);
    if(j<ro-1)dfs(i,j+1,list,lin,ro);
}
int **creat(int m, int n)
{
    int **r;
    int i;
    r=(int **)malloc(sizeof(int *) *m);
    for(i = 0; i < m; i ++)
        r[i] = (int *)malloc(sizeof(int)*n);
    return r;
}
char **creat_c(int m, int n)
{
    char **r;
    int i;
    r=(char **)malloc(sizeof(char *) *m);
    for(i = 0; i < m; i ++)
        r[i] = (char *)malloc(sizeof(char)*(n+1));
    return r;
}
int main()
{
    int line,row;
    scanf("%d %d",&line,&row);
    int** maplist=creat(line,row);
    char** trans=creat_c(line,row);
    int total=0;
    for(int i=0;i<line;i++)
    {
            for(int j=-1;j<row;j++)
            {
                    scanf("%c",&trans[i][j]);
                    maplist[i][j]=(int)trans[i][j]-48;
            } 
    }
    for(int p=0;p<line;p++)
    {
            for(int q=0;q<row;q++)
            {
                    if(maplist[p][q]!=0)
                    {
                         dfs(p,q,maplist,line,row);
                         total++;
                    }
            } 
    }
    printf("%d",total);
    return 0;
}
