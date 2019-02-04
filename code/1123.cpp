//Problem 1123: 均分纸牌 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 536.0 KiB
#include<stdio.h>
int card[10000]={0};
int main(void)
{
	int n=0,sum=0,average,count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&card[i]);
		sum+=card[i];
	}
	average=sum/n;
	for(int i=0;i<n;i++)
	{
		if(card[i]>average)
		{
			card[i+1]+=(card[i]-average);
			count++;
		}
		else if(card[i]<average)
		{
			card[i+1]-=(average-card[i]);
			count++;
		}
		else
		;
	}
	printf("%d",count);
} 