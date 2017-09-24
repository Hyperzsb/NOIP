#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int depth=1;
bool Prime[45];
bool Is_Prime(int number)
{
	return Prime[number];
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
void dfs(int first,int from,int num,int total,int* list,int* answer,int* ptip)
{
	if(*
	ptip!=0)
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
		(*ptip)++;
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
			dfs(first,num,i,total,list,answer,ptip);
	}
	list[num]=0;
	depth--;
}
int main()
{
	for(int i=1;i<=45;i++)
	{
		Prime[i]=false;
	}
	Prime[3]=true;
	Prime[5]=true;
	Prime[7]=true;
	Prime[11]=true;
	Prime[13]=true;
	Prime[17]=true;
	Prime[19]=true;
	Prime[23]=true;
	Prime[29]=true;
	Prime[31]=true;
	Prime[37]=true;
	Prime[41]=true;
	Prime[43]=true;
	int number;
	int tip=0;
	int* ptip;
	ptip=&tip;
	scanf("%d",&number);
	int* list=(int*)malloc((number+1)*sizeof(int));
	int* answer=(int*)malloc((number+1)*sizeof(int));
	for(int i=0;i<=number;i++)
	{
		list[i]=0;
	}
	for(int i=1;i<=(number/2);i++)
	{
		dfs(i,i,i,number,list,answer,ptip);
	}
	if(*ptip==0)
	{
		printf("-1");
	}	return 0;
}
