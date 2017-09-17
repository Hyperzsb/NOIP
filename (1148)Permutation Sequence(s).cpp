#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int depth=1;
int sign(int number,int total,int* list)
{
	if(list[number]==1)
	{
		return 0;
	}
	int flag=0;
	for(int i=1;i<=total;i++)
	{
		if(list[i]==0)
		{
			flag=flag+1;
		}
	}
	return flag;
}
void dfs(int num,int total,int* list,int* answer)
{
	int flag=sign(num,total,list);
	if(flag==0)
	{
		return;
	}
	if(flag==1)
	{
		for(int i=1;i<total;i++)
		{
			printf("%d ",answer[i]);
		}
		printf("%d\n",num);
	}
	list[num]=1;
	answer[depth]=num;
	depth++;
	for(int i=1;i<=total;i++)
	{
		dfs(i,total,list,answer);
	}
	list[num]=0;
	depth--;
	answer[depth]=0;
}
int main()
{
	int number;
	scanf("%d",&number);
	int* list=(int*)malloc((number+1)*sizeof(int));
	int* answer=(int*)malloc((number+1)*sizeof(int));
	for(int i=1;i<=number;i++)
	{
		list[i]=0;
		answer[i]=0;
	}
	for(int i=1;i<=number;i++)
	{
		dfs(i,number,list,answer);
	}
	return 0;
}
