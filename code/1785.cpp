//Problem 1785: 同学排序 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
int main(void)
{
	int n,m,sum=0;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)
	{
		sum+=m/2;
		m-=m/2;
	}
	printf("%d",sum);
} 