//Problem 1181: CoVH之密码破解 
//Status: Accepted 
//Used Time: 77ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
int num(int a)
{
	if(a<100000&&a>9999)
		return 5;
	else if(a<1000000&&a>99999)
		return 6;
	else if(a<10000000&&a>999999)
		return 7;
	else if(a<100000000&&a>9999999)
		return 8;
	else if(a>999&&a<10000)
		return 4;
	else if(a>99&&a<1000)
		return 3;
	else if(a>9&&a<100)
		return 2;
	else return 1;
}
int main(void)
{
	int i=1,n,sum=0,diff,final=1;
	scanf("%d",&n);
	while(sum<n)
	{
		sum+=num(i);
		i++;
	}
	diff=sum-n;
	for(int m=0;m<diff;m++)
		final*=10;
	final=(i-1)/final;
	final=final%10;
	printf("%d",final);
}