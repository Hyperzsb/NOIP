#include<stdio.h>
#include<malloc.h>
#include<algorithm>
#include<math.h>
#define PR printf
#define SC scanf
using namespace std;
int main()
{
	int total,i=0,test;
	char num[1000];
	SC("%d",&total);
	for(int i=0;i<total;i++)
	{
		test=getchar();
		while(test!='=')
		{	
			if(test=='*'&&test=='/'&&test=='-'&&test=='+')
			{
				putchar(test);
			}
			num[i]=getchar();
			i++;
			num[i]='\0';
		}
	}
	return 0;
}
