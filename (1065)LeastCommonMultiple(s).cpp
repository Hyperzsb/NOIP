#include<stdio.h>
#include<malloc.h>
#include<algorithm>
#define PR printf
#define SC scanf
int f(int a,int b);
int main()
{
	int a,b,c;
	SC("%d%d",&a,&b);
	c=f(a,b);
	PR("%d",a*(b/c));
	return 0;
}
int f(int a,int b)
{
	int t;
	if(a<b)
	{
		a=a^b;
		b=a^b;
		a=a^b;
	}
	while(b!=0)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
