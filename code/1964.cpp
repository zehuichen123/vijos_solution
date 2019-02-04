//Problem 1964: 夜夜的NOIP之旅 
//Status: Accepted 
//Used Time: 30ms 
//Peak Memory: 496.0 KiB
#include<stdio.h>
int main(void)
{
	long long n,m;
	scanf("%lld%lld",&n,&m);
	unsigned long long sum=0;
	unsigned long long num=1;
	if(n>=m)
	n=m-1;
	for(int i=1;i<=n;i++)
	{
		num*=i;
		num=num%m;
		sum+=num;
	}
	sum=sum%m;
	printf("%llu",sum);
}