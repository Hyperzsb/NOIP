#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int total=0;
int** Creat_Arr_int(int n)
{
      int** arr=(int**)malloc(n*sizeof(int*));
      for(int i=0;i<n;i++)
      {
           arr[i]=(int*)malloc(n*sizeof(int));
      }
      return arr;
}
void dfs(int xR,int yR,int** list,int line)
{
	if(list[xR][yR]==1)
	{
		return;
	}
	if(xR==0&&yR==line-1)
	{
		total++;
		return;
	}
	list[xR][yR]=1;
	if(xR>0) dfs(xR-1,yR,list,line);
	if(xR<line-1) dfs(xR+1,yR,list,line);
	if(yR>0) dfs(xR,yR-1,list,line);
	if(yR<line-1) dfs(xR,yR+1,list,line);
	if(xR>0&&yR>0) dfs(xR-1,yR-1,list,line);
	if(xR>0&&yR<line-1) dfs(xR-1,yR+1,list,line);
	if(xR<line-1&&yR>0) dfs(xR+1,yR-1,list,line);
	if(xR<line-1&&yR<line-1) dfs(xR+1,yR+1,list,line);
	list[xR][yR]=0;
}
int main()
{
    int line;
    scanf("%d",&line);
    int** maplist=Creat_Arr_int(line);
    for(int i=0;i<line;i++)
    {
         for(int j=0;j<line;j++)
         {
                 scanf("%d",&maplist[i][j]);
         }
    } 
    dfs(0,0,maplist,line);
	printf("%d",total);
    return 0;
}
