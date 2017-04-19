#include<stdio.h>
#include<malloc.h>
#include<algorithm>
#define PR printf
#define SC scanf
int main()
{
	int a,b;
	SC("%d%d",&a,&b);
	for(int i=1;i<=a*b;i++)
	{
		if((i>=a)&&(i>=b))
		{
			if(((i%a)==0)&&((i%b==0)))
			{
				PR("%d",i);
				break;
			}
		}
	}
	return 0;
}
