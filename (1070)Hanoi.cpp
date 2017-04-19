#include<stdio.h>
#define PR printf
static int i=1;
void ann(int num,char fro,char t);
void move(int heig,char from,char to,char dep);
int main()
{
	int tow[20];
	int height;
	char x='a',y='c',z='b';
	scanf("%d",&height);
	move(height,x,y,z);
}
void move(int heig,char from,char to,char dep)
{
	if(heig==1)
	{
		ann(heig,from,to);	
	}
	else
	{
		move(heig-1,from,dep,to);
		ann(heig,from,to);
		move(heig-1,dep,to,from);
	}
}
void ann(int num,char fro,char t)
{
	PR("%d.Move %d from %c to %c\n",i,num,fro,t);
	i++;
}
