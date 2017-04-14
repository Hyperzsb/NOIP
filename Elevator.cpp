#include<stdio.h>
int floor(int st,int to,int al,int allf[])
int main()
{
int first,last,all;
scanf("%d%d%d",&first,&last,&all);
int  flonum[100];
for(int i=0;i<all;i++)
{
scanf("%d",&flonum[i]);
}
floor(first,last,all,flonum);
getchar();
return 0;
}
int floor(int st,int to,int al,int fn[])
{
if(st==to)
{
printf("OK\n");
}
if(st!=to)
{
if((st+fn[st-1])<=al)
{
floor(st+fn[st-1],to,al,fn)
}
if(((st+fn[st-1])>al)&&((st-fn[st-1])>=1))
}
return ;
}
