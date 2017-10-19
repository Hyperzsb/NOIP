#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int final=0;
int sum=0;
bool Is_Prime(int num)
{
	for(int i=2;i*i<=num;i++) {
        if(num%i==0) return false;
    }    
    return true;
}
int check(int depth,int num,int* testlist)
{
	int flag=0;
	for(int i=1;i<=num;i++)
	{
		if(testlist[i]==1)
			flag++;
	}
	return depth-flag;
}
void dfs(int now,int depth,int num,int* maplist,int* testlist)
{
	if(check(depth,num,testlist)==1)
	{
		sum+=maplist[now];
		if(Is_Prime(sum))
			final++;
		sum-=maplist[now];
		return;
	}
	sum+=maplist[now];
	testlist[now]=1;
	for(int i=now;i<=num;i++)
	{
		if(testlist[i]!=1)
			dfs(i,depth,num,maplist,testlist);
	}
	sum-=maplist[now];
	testlist[now]=0;
	return;
}
int main()
{
	int num,depth;
	scanf("%d%d",&num,&depth);
	int* maplist=(int*)malloc((num+3)*sizeof(int));
	int* testlist=(int*)malloc((num+3)*sizeof(int));
	for(int i=1;i<=num;i++)
	{
		maplist[i]=0;
		testlist[i]=0;
		scanf("%d",&maplist[i]);
	}
	sort(&maplist[1],&maplist[1]+num);
	for(int i=1;i<=num;i++)
	{
		dfs(i,depth,num,maplist,testlist);
	}
	printf("%d",final);
	return 0;
}
