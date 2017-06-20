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
	int* ans=(char*)malloc(total*sizeof(int)*2);
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
		/*for(int x=0;x<symnum;x++)
		{
			printf("%d\n",numlist[x]);
			printf("%c\n",symble[x]);
		}
		printf("====================\n");*/
		*(&ans[i])=numlist[0];
		*(&ans[i]+1)=1;
		for(int y=0;y<symnum-1;y++)
		{
			switch(symble[symnum])
				case '+':
					*(&ans[i])+=(*(&ans[i]+1))*symble[symnum+1];
				case '-':
					*(&ans[i])-=(*(&ans[i]+1))*symble[symnum+1];
				case '*':
					*(&ans[i])=(*(&ans[i]))*symble[symnum+1];
		}
	}
	return 0;
}
