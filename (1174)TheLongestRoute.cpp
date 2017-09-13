#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int final=0;
int sum=0;
int snum(int a,int b)
{
	if(a>=b)
		return a-b;
	else
		return b-a;
}
int dfs(int first,int from,int num,int total,int* list)
{
	if(list[num]==1)
	{
		return 0;
	}
	int flag=1;
	for(int i=1;i<=total;i++)
	{
		if(list[i]=0)
		{
			flag=0;
		}
	}
	if(flag)
	{
		sum+=snum(first,num)*snum(first,num)+snum(from,num)*snum(from,num);
		if(sum>final)
		{
			sum=sum^final;
			final=final^sum;
			sum=sum^final;
		}
		sum=0;
		return 1;
	}
	list[num]=1;
	int cpsum=sum;
	for(int i=1;i<=total;i++)
	{
		if(dfs(first,num,i,total,list)!=0)
		{
			sum+=snum(i,num)*snum(i,num);
		}
	}
}
int main()
{
	int number;
	scanf("%d",&number);
	int* numlist=(int*)malloc((number+1)*sizeof(int));
	for(int i=1;i<=number;i++)
	{
		numlist[i]=0;
	}
	for(int i=1;i<=number;i++)
	{
		dfs(i,i,i,number,numlist);
	}
	printf("%d",final);
	return 0;
}
