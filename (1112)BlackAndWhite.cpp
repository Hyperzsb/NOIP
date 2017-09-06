#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
void dfs(int i,int j,int* list,bool* test,int lin,int ro)
{
    if(*(&test[i]+j)==false)
    {
         return ; 
    }
    *(&test[i]+j)=false;
    if(i>0)dfs(i-1,j,list,test,lin,ro);
    if(i<lin-1)dfs(i+1,j,list,test,lin,ro);
    if(j>0)dfs(i,j-1,list,test,lin,ro);
    if(j<ro-1)dfs(i,j+1,list,test,lin,ro);
}
int main()
{
    int line,row;
    scanf("%d %d",&line,&row);
    //printf("%d %d",line,row);
    int* maplist=(int*)malloc(line*row*sizeof(int));
    bool* isempty=(bool*)malloc(line*row*sizeof(int));
    int total=0;
    for(int i=0;i<line;i++)
    {
            for(int j=0;j<row;j++)
            {
                    scanf("%d",(&maplist[i]+j));
                    if(*(&maplist[i]+j)==0)
                    {
                        *(&isempty[i]+j)=false;                       
                    }
                    if(*(&maplist[i]+j)==1)
                    {
                        *(&isempty[i]+j)=true;
                    }
            } 
    }
    getchar();
    /*for(int m=0;m<line;m++)
    {
            for(int n=0;n<row;n++)
            {
                    printf("%d ",*(&maplist[m]+n));
            }
            printf("\n"); 
    }*/
    getchar();
    for(int p=0;p<line;p++)
    {
            for(int q=0;q<row;q++)
            {
                    if(*(&maplist[p]+q)==1||*(&isempty[p]+q))
                    {
                         dfs(p,q,maplist,isempty,line,row);
                         total++;
                    }
            } 
    }
    getchar();
    printf("%d",total);
    return 0;
}
