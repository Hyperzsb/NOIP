#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int total=0;
void dfs(int number,int depth,int flag)
{
	if(number<flag)
	{
		return;
 }
	if(number==flag&&depth>1)
	{
		return;
	}
	if(depth==1&&number>0)
	{
		total++;
		return;
	}
	depth--;
	for(int i=flag;i<=number;i++)
	{
		dfs(number-i,depth,i);
	}
	depth++;
}
int main()
{
	int number;
	int depth=0;
	scanf("%d%d",&number,&depth);
	depth--;
	for(int i=1;i<=number/2;i++)
	{
		dfs(number-i,depth,i);
	}
	printf("%d",total);
	return 0;
}
