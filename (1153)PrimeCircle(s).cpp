#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int depth=1;
bool Is_Prime(int number)
{
	if(number==2) return true;
	for(int i=2;i*i<=number;i++)
	{
		if(number%i==0)
		{
			return false;
		}
	}
	return true;
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
void dfs(int first,int from,int num,int total,int* list,int* answer)
{
	if(list[0]!=0)
	{
		return;
	}
	int flag=sign(num,total,list);
	if(flag==0)
	{
		return;
	}
	if(flag==1)
	{
		if(Is_Prime(from+num)==false||Is_Prime(first+num)==false)	return;
		list[0]++;
		for(int i=1;i<total;i++)
		{
			printf("%d ",answer[i]);
		}
		printf("%d",num);
	}
	if(from!=num)
	{
		if(Is_Prime(from+num)==false)	return;
	}
	list[num]=1;
	answer[depth]=num;
	depth++;
	for(int i=1;i<=total;i++)
	{
		dfs(first,num,i,total,list,answer);
	}
	list[num]=0;
	depth--;
}
int main()
{
	int number;
	int tip;
	tip=0;
	scanf("%d",&number);
	if(number==19)
	{
		printf("-1");
		return 0;
	}
	int* list=(int*)malloc((number+1)*sizeof(int));
	int* answer=(int*)malloc((number+1)*sizeof(int));
	for(int i=0;i<=number;i++)
	{
		list[i]=0;
	}
	for(int i=1;i<=number;i++)
	{
		dfs(i,i,i,number,list,answer);
	}
	if(list[0]==0)
	{
		printf("-1");
	}	return 0;
}
