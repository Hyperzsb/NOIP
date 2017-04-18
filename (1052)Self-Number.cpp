#include<stdio.h>
#include<malloc.h>
#include<algorithm>
#define PR printf
#define SC scanf
using namespace std;
int step=0;
int step1=0;
int filtration(int arr[],int len);
int d(int number);
int selfnum(int array[],int tes[],int le,int tot);
int find(int arr[], int n, int val);
int main()
{
	int length,total;
	SC("%d%d",&length,&total);
	int *num=(int *)malloc(length*sizeof(int));
	int *test=(int *)malloc(total*sizeof(int));
	for(int k=0;k<total;k++)
	{
		SC("%d",&test[k]);
	}
	for(int i=1;i<length+1;i++)
	{
		num[i-1]=d(i);
	}
	sort(num,&num[length]);
	filtration(num,length);
	selfnum(num,test,length,total);
	return 0;
}
int filtration(int arr[],int len)
{
	for(int j=0;j<len;j++)
	{
		if((j+1)<=len)
		{
			if(arr[j]==arr[j+1])
			{
				for(int k=j+1;k<len-1;k++)
				{
					arr[k]=arr[k+1];
				}
				j--;
				len--;
				step++;
			}
		}
	}
	return 0;
}
int d(int number)
{
	int sum=number;
	while(number)
	{
		sum+=number%10;
		number/=10;
	}
	return sum;
}
int selfnum(int array[],int tes[],int le,int tot)
{
	int *selfnumber=(int *)malloc(tot*sizeof(int));
	for(int i=1;i<le+1;i++)
	{
		if(find(array,le-step,i)==-1)
		{
			selfnumber[step1]=i;
			step1++;
		}
	}
	PR("%d\n",step1);
	for(int k=0;k<tot;k++)
	{
		PR("%d ",selfnumber[tes[k]-1]);
	}
	return 0;	
}
int find(int arr[], int n, int val)
{
    for (int i = 0; i < n; ++i)
    {
        if (val == arr[i])
            return i;
    }
    return -1;
}
