
#include<stdio.h>
#include<malloc.h>
#define PR printf
#define SC scanf
int a[1000];
static int step=0;
static int step1=0;
int sep(int number);
int sep1(int number,int lim);
int main()
{
	int total;
	SC("%d",&total);
	int *num=(int*)malloc(total*sizeof(int));
	int i,j,l;
	for(i=0;i<total;i++)
	{
		SC("%d",&num[i]);
	}
	for(j=0;j<total;j++)
	{
		sep1(num[j],2);
	}
	printf("%d",step1+1);	
	/*for(l=0;l<step;l++)
	{
		PR("%d\n",a[l]);
	}
	*/
	return 0;
}
int sep(int number)
{
	int k;
	if(number==1)
	{
		return 0;
	}
	for(k=2;k<=number;k++)
	{
		if(number%k==0)
		{
			a[step]=k;
			step++;
			sep(number/k);
			break;
		}
	}
return 0;
}
int sep1(int number,int lim)
{
	int k;
	if(number==1)
	{
		return 0;
	}
	for(k=lim;k<=number;k++)
	{
		if(number%k==0&&k<=(number/k))
		{
			step1++;
			sep1(number/k,k);
		}
	}
return 0;
}

