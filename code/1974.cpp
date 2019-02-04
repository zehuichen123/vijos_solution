//Problem 1974: 金币 
//Status: Accepted 
//Used Time: 15ms 
//Peak Memory: 496.0 KiB
#include<stdio.h>
int main(void)
{
	int day=0,k,return_1=0,return_2=0;
	unsigned long long sum=0;
	scanf("%d",&k); 
	while(day<k)
	{
		for(int i=1;i<=100000;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(day==k)
				{
					return_1=1;
					break;
				}
				sum+=i;
				day++;
			}
			if(return_1)
			{
				return_2=1;
				break;
			}
		}
		if(return_2)
			break;
	}
	printf("%llu",sum); 
}