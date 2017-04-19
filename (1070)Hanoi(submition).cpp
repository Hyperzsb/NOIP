#include<stdio.h>
#define PR printf
static int i=1;
void move(int heig,char from,char to,char dep);
int main()
{
	int height;
	char x='a',y='c',z='b';
	scanf("%d",&height);
	move(height,x,y,z);
}
void move(int heig,char from,char to,char dep)
{
	if(heig==1)
	{	
		PR("%d.Move %d from %c to %c\n",i,heig,from,to);
		i++;
	}
	else
	{
		move(heig-1,from,dep,to);
		PR("%d.Move %d from %c to %c\n",i,heig,from,to);
		i++;
		move(heig-1,dep,to,from);
	}
}
