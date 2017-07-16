#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//int numlist[100010],newlist[100010];
int main()
{
	int length,flag;
	int k=1;
	scanf("%d %d",&length,&flag);
	int* numlist=(int*)malloc(sizeof(int)*length);
	int* newlist=(int*)malloc(sizeof(int)*length);
	for(int i=0;i<length;i++)
	{
		scanf("%d",&numlist[i]);
	}
	sort(numlist,numlist+length);
	newlist[0]=numlist[0];
	for(int j=1;j<length;j++)
	{
		if(numlist[j]!=numlist[j-1])
		{
			newlist[k]=numlist[j];
			k++;
		}
		elsea
		{
			continue;
		}
	}
	printf("%d",newlist[flag-1]);
	//system("pause");
	return 0;
}
