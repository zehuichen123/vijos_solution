//Problem 1786: 质因数分解 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 496.0 KiB
#include<stdio.h>
int judge(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}
int main(void)
{
	int m,i;
	scanf("%d",&m);
	for(i=2;i*i<m;i++)
	{
		if(judge(i))
		{
			if(m%i==0)
				break;
		}
	}
	printf("%d",m/i);	
}