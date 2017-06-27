#include<stdio.h>
#include<malloc.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define PR printf
#define SC scanf
using namespace std;
int main()
{
	int total;
	SC("%d",&total);
	char* str=(char*)malloc(total*sizeof(char)*10000);
	int* ans=(int*)malloc(total*sizeof(int)*4);
	int anslist[500][2];
	for(int i=0;i<total;i++)
	{
		scanf("%s",&str[i]);
		int length=(int)strlen(&str[i]);
		char number[10];
		char symble[5000];
		int numlist[5000];
		int symnum=0;
		int k=0;
		for(int j=0;j<length;j++)
		{
			if(*(&str[i]+j)=='+'||*(&str[i]+j)=='-'||*(&str[i]+j)=='*'||*(&str[i]+j)=='/'||*(&str[i]+j)=='=')
			{
				symble[symnum]=*(&str[i]+j);
				sscanf(number,"%d",&numlist[symnum]);
				symnum++;
				for(int l=0;l<10;l++)
				{
					number[l]=NULL;
				}
				k=0;
				continue;
			}
			number[k]=*(&str[i]+j);
			k++;	
		}
		*(&ans[i]+1)=numlist[0];
		*(&ans[i]+2)=1;
		for(int y=0;y<symnum-1;y++)
		{
			switch(symble[y])
			{
				case '+':
					*(&ans[i]+1)+=(*(&ans[i]+2))*numlist[y+1];
					break;
				case '-':
					*(&ans[i]+1)-=(*(&ans[i]+2))*numlist[y+1];
					break;
				case '*':
					*(&ans[i]+1)=(*(&ans[i]+1))*numlist[y+1];
					break;
				case '/':
					*(&ans[i]+2)=(*(&ans[i]+2))*numlist[y+1];
					break;
			}
		}
		anslist[i][0]=*(&ans[i]+1);
		anslist[i][1]=*(&ans[i]+2);
	}
	for(int b=0;b<total;b++)
	{
		for(int a=2;a<=anslist[b][1];a++)
		{
			if((anslist[b][0]%a)==0&&(anslist[b][1]%a)==0)
			{
				anslist[b][0]=anslist[b][0]/a;
				anslist[b][1]=anslist[b][1]/a;
				a--;
			}
		}
		if(anslist[b][0]==0)
		{
			printf("0");
			break;
		}
		printf("%d/%d\n",anslist[b][0],anslist[b][1]);
	}
	return 0;
}
