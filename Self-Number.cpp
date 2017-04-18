#include<stdio.h>
#include<malloc.h>
#include<algorithm>
#define PR printf
#define SC scanf
using namespace std;
int filtration(int arr[],int len);
int main()
{
	int length;
	int *num=(int *)malloc(length*sizeof(int));
	SC("%d",&length);
	for(int i=0;i<length;i++)
	{
		SC("%d",&num[i]);
	}
	sort(num,&num[length]);
	for(int j=0;j<length;j++)
	{
		PR("%d\t",num[j]);
	}
	filtration(num,length);
}
int filtration(int arr[],int len)
{
	for(j=0;j<len;j++)
	{
		
	}
}
