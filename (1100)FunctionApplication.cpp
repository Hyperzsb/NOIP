#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<malloc.h> 
typedef float (*FP)(int num); 
float f1(int num)
{
	return (num*11+24);
} 
float f2(int num)
{
	return ((num>>3)+3);
} 
float f3(int num)
{
	return (num*num+10*num+31);
} 
float f4(int num)
{
	return (num/13+31);
} 
float f5(int num)
{
	return (num-sqrt(num));
}
float f6(int num)
{
	return (sqrt(num));
} 
float f7(int num)
{
	return (num%206211);	
} 
float f8(int num)
{
	return (num|10311999);	
}
float f9(int num)
{
	return (num&19991124);	
} 
float f10(int num)
{
	return (num^11241031);
} 
int main()
{
	int operate;
	FP fp;
	scanf("%d",&operate);
	int* opelist=(int *)malloc(3*operate*sizeof(int));
	for(int i=0;i<operate;i++)
	{
		scanf("%d %d %d",&opelist[i*3],&opelist[i*3+1],&opelist[i*3+2]);
	}
	for(int k=0;k<operate;k++)
	{
		FP flist[10]={f1,f2,f3,f4,f5,f6,f7,f8,f9,f10};
		fp=flist[(opelist[k*3])];
		flist[(opelist[k*3])]=flist[(opelist[k*3+1])];
		flist[(opelist[k*3+1])]=fp;
		for(int j=0;j<10;j++)
		{
			opelist[k*3+2]=(int)(*flist[j])(opelist[k*3+2]);
		}
		printf("%d\n",opelist[k*3+2]);
	}
	return 0; 
}
