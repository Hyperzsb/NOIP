#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int final=0;
int snum(int a,int b)
{
	if(a>=b)
		return (a-b)*(a-b);
	else
		return (b-a)*(b-a);
}
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
void dfs(int first,int from,int num,int total,int sum,int* list)
{
	int flag=sign(num,total,list);

	if(flag==0)
	{
		return;
	}
	if(flag==1)
	{
		if(final<(sum+snum(from,num)+snum(first,num)))
		{
			final=sum+snum(from,num)+snum(first,num);
		}
	}
	list[num]=1;
	sum+=snum(from,num);
	int* sumlist=(int*)malloc(total*sizeof(int));
	for(int i=1;i<=total;i++)
	{
		sumlist[i]=sum;
		dfs(first,num,i,total,sumlist[i],list);
	}
	list[num]=0;
}
int main()
{
	int number;
	scanf("%d",&number);
	int* list=(int*)malloc((number+1)*sizeof(int));
	for(int i=1;i<=number;i++)
	{
		list[i]=0;
	}
	for(int i=1;i<=number;i++)
	{
		int sum=0;
		dfs(i,i,i,number,sum,list);
	}
	printf("%d",final);
	return 0;
}
