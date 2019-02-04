//Problem 1290: sk抓螃蟹 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 496.0 KiB
#include<stdio.h>
int main(void)
{
	int n=0,count1=0,count2=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		if(i%2)
		{
			printf("%d\n",n-count1);
			count1++;
		}
		else
		{
			printf("%d\n",count2);
			count2++;
		}
	}
}