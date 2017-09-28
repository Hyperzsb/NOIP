#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int flag=0;
int total=0;
int** Creat_Arr_int(int num)
{
	int** arr=(int**)malloc(num*sizeof(int*));
	for(int i=0;i<num;i++)
	{
		arr[i]=(int*)malloc(num*sizeof(int));
	}
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			arr[i][j]=0;
		}
	}
	return arr;
}
int snum(int a,int b)
{
	if(a>b) return a-b;
	else return b-a;
}
void dfs(int x,int y,int** list,int num)
{
	if(flag==num-1)
	{
		total++;
		return;
	}
	flag++;
	for(int i=0;i<num;i++)
	{
		if(i==x)
		{
			 for(int j=0;j<num;j++) list[x][j]+=1;
			 continue;
		}
		list[i][y-snum(x,i)]+=1;
		list[i][y]+=1;
		list[i][y+snum(x,i)]+=1;
	}
	for(int i=0;i<num;i++)
	{
		if(list[x+1][i]==0)
		{
			dfs(x+1,i,list,num);
		}
	}
	for(int i=0;i<num;i++)
	{
		if(i==x)
		{
			 for(int j=0;j<num;j++) list[x][j]-=1;
			 continue;
		}
		list[i][y-snum(x,i)]-=1;
		list[i][y]-=1;
		list[i][y+snum(x,i)]-=1;
	}
	flag--;
}
int main()
{
	int num;
	scanf("%d",&num);
	int** maplist=Creat_Arr_int(num+3);
	for(int i=0;i<num;i++)
	{
		dfs(0,i,maplist,num);
	}
	printf("%d",total);
	return 0;
}
