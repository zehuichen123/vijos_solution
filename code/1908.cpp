//Problem 1908: 无线网络发射器选址 
//Status: Accepted 
//Used Time: 15ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
int d;
int judge(int x,int y,int i,int j)
{
	if(x<=i+d&&x>=i-d&&y<=j+d&&y>=j-d)
		return 1;
	else return 0;
}
int main(void)
{
	int n,max=0,count=0,sum=0;
	int x[20]={0},y[20]={0},k[20]={0};
	scanf("%d",&d);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&k[i]);
	}
	for(int i=0;i<=128;i++)
	{
		for(int j=0;j<=128;j++)
		{
			for(int a=0;a<n;a++)
			{
				if(judge(x[a],y[a],i,j))
				{
					sum+=k[a];
				}
			}
			if(sum>max)
			{
				max=sum;
				count=1;
			}
			else if(sum==max)
			{
				count++;
			}
			else ;
			sum=0;
		}
	}
	printf("%d %d",count,max);
}