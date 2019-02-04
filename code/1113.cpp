//Problem 1113: 不高兴的津津 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
int main(void)
{
	int a,b,sum=0,num,return_1=1;
	for(int i=0;i<7;i++)
	{
		scanf("%d %d",&a,&b);
		if(a+b>8)
		{
			if(a+b>sum)
			{
				sum=a+b;
				num=i;
				return_1=0;
			}
		}
	}
		if(return_1==1)
			printf("0");
		else
		printf("%d",num+1);
 } 