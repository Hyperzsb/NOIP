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
	int times;
	scanf("%d",&times);
	while(times>0)
	{
		int number;
		int depth=0;
		scanf("%d%d",&number,&depth);
		depth--;
		while(depth>0)
		{
			for(int i=1;i<=number/2;i++)
			{
				dfs(number-i,depth,i);
			}
			depth--;
		}
		printf("%d\n",total+1);
		total=0;
		times--;
	}
	return 0;
}
