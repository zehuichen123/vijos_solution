//Problem 1201: 高低位交换 
//Status: Accepted 
//Used Time: 15ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
int main(void)
{
	long long a,b,c;
	scanf("%d",&a);
	b=(a>>16)&65535;
	c=(a<<16)&4294901760;
	printf("%lld",b+c);
}