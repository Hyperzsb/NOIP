#include<stdio.h>
#include<malloc.h>
#include<algorithm>
#include<math.h>
#define PR printf
#define SC scanf
using namespace std;
bool isprime(int number);
int main()
{
	int a,b;
	SC("%d%d",&a,&b);
	for(int i=2;i<=b;i++)
	{
		if((b%i)==0)
		{
			if(isprime(i))
			{
				if((a%i)!=0)
				{
					PR("%d",i);
					PR("No");
					return 0;
				}
			}
		}
	}
	PR("Yes");
	return 0;
}
bool isprime(int number)
{
	for(int i=2;i<=sqrt(number);i++)
	{
		if((number%i)==0)
		{
			return false;
			break;
		}
	}
	return true;
}
