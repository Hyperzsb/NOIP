#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int monster=0;
int xmonster[503];
int ymonster[503];
int fatal[501][501];
int final=0;
bool** Creat_Arr_bool(int n,int m)
{
	bool** arr=(bool**)malloc(n*sizeof(bool*));
	for(int i=0;i<n;i++)
	{
		arr[i]=(bool*)malloc(m*sizeof(bool));
	}
	return arr;
}
int snum(int a,int b)
{
	if(a>=b)
		return a-b;
	else
		return b-a;
}
int dengerous(int xV,int yV)
{
	int denger=snum(xV,xmonster[0])+snum(yV,ymonster[0]);
	for(int i=1;i<monster;i++)
	{
		if((snum(xV,xmonster[i])+snum(yV,ymonster[i]))<denger)
		{
			denger=snum(xV,xmonster[i])+snum(yV,ymonster[i]);
		}
	}
	return denger;
}
void dfs(int xV,int yV,int xJ,int yJ,int lin,int ro,bool** test,int minnum)
{
	if(test[xV][yV]==false)
	{
		
		return;
	}
	int num=fatal[xV][yV];
	if(num<final)
	{
		test[xV][yV]=false;
		return;
	}
	if(num<minnum)
	{
		num=num^minnum;
		minnum=minnum^num;
		num=num^minnum;
	}
	if(xV==xJ&yV==yJ)
	{
		if(minnum>final)
		{
			minnum=minnum^final;
			final=final^minnum;
			minnum=minnum^final;
		}
		return;
	}
	test[xV][yV]=false;
	int* minnumlist=(int*)malloc(4*sizeof(int));
	for(int i=0;i<4;i++)
	{
		minnumlist[i]=minnum;
	}
	if(xV>0) dfs(xV-1,yV,xJ,yJ,lin,ro,test,minnumlist[0]);
	if(xV<lin-1) dfs(xV+1,yV,xJ,yJ,lin,ro,test,minnumlist[1]); 
	if(yV>0) dfs(xV,yV-1,xJ,yJ,lin,ro,test,minnumlist[2]);
	if(yV<ro-1) dfs(xV,yV+1,xJ,yJ,lin,ro,test,minnumlist[3]);
	free(minnumlist);
	test[xV][yV]=true;
}
int main()
{
	int line,row;
	int xV,yV,xJ,yJ;
	scanf("%d %d",&line,&row);
	char flag;
	bool** isempty=Creat_Arr_bool(line,row);
	for(int i=0;i<line;i++)
	{
		for(int j=-1;j<row;j++)
		{
			scanf("%c",&flag);
			isempty[i][j]=true;
			if(flag=='.')
			{
				continue;
			}
			if(flag=='+')
			{
				xmonster[monster]=i;
				ymonster[monster]=j;
				monster++;
				continue;
			}
			if(flag=='V')
			{
				xV=i;
				yV=j;
				continue;
			}
			if(flag=='J')
			{
				xJ=i;
				yJ=j;
				continue;
			}
		}
	}
	for(int i=0;i<line;i++)
	{
		for(int j=-1;j<row;j++)
		{
			fatal[i][j]=dengerous(i,j);
		}
	}
	int minnumber=dengerous(xV,yV);
	dfs(xV,yV,xJ,yJ,line,row,isempty,minnumber);
	printf("%d",final);
	return 0;
}
