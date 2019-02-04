//Problem 1216: 亲和数 
//Status: Accepted 
//Used Time: 1621ms 
//Peak Memory: 1.25 MiB
#include<stdio.h>
#include<math.h>
int data[200000]={0};
int x=0,y=0;
int check(int n,int flag)
{
	int m=0,sum=1;
	m=(int)sqrt((double)n);
	for(int i=2;i<=m;i++)
	{
		if(n%i==0)
		{
			sum+=(n/i);
			sum+=i;
			
		}
	}
	if(flag)
	data[n-x]=sum;
	else return sum;
}
int main(void)
{
	int count=0;
	scanf("%ld %ld",&x,&y);
	for(int i=x;i<=y;i++)
	{
		check(i,1);
	}
	for(int i=x;i<y;i++)
	{
		if(data[i-x]>=i)
		{
			if(data[i-x]<=y)
			{
				for(int j=i+1;j<=y;j++)
				{
					if(data[i-x]==j&&data[j-x]==i)
						count++;
				}
			}
			else
			{
				if(check(data[i-x],0)==i)
					count++;
			}
		}
	}
	printf("%d",count);
}