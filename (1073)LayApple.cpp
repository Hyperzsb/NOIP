#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int sum=0;
int apple(int n,int m)
{
    sum++;
    if(m==1)
    {
        return sum;
    }
    else
    {   
        if(n%2==1)
        {
            n--;
        }
        for(int i=1;i<=(n/2);i++)
        {
            sum++;
            apple(n-i,m-1);
        }
    }
    return sum;
}
int main()
{
    int tasknum;
    int appnum,pan;
    scanf("%d",&tasknum);
    for(int j=0;j<tasknum;j++)
    {
        scanf("%d %d",&appnum,&pan);
        printf("%d\n",apple(appnum,pan));
    }
    //getchar();
    //getchar();
    //system("pasue");
    return 0;
}
