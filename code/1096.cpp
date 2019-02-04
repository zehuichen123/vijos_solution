//Problem 1096: 津津的储蓄计划 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
int main(void)
{
	int mom=0,i,sum=0,return_1=1;
	int exp[12];
	int now=0;
	float c;
	for(i=0;i<12;i++)
	{
		scanf("%d",&exp[i]);
	}
	for(i=0;i<12;i++)
	{
		mom=((300+now-exp[i])/100)*100;
		sum+=mom;
		now=now+300-mom-exp[i];
		if(now<0)
		{
			return_1=0;
			break;
		}
	}
	if(return_1==0)
	printf("%d",-i-1);
	else
	{
		c=(float)sum*1.2+now;
		printf("%.0f",c);
	}
 } 