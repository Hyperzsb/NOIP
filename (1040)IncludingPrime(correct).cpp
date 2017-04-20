#include<cstdio>
#include<cmath>
bool su(int x)
{
	int i;
	for(i=2;i<=sqrt(x);i++)
	if(x%i==0) return false;
	return true;
}
int main()
{
	int a,b,i;
	bool can=true;
	scanf("%d%d",&a,&b);
	if(a<b)
	{
		printf("No");
		return 0;
	}
	for(i=2;i<=sqrt(b);i++)
	{
		if(su(i)&&b%i==0&&a%i!=0)
		{

			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}
