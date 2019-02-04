//Problem 1021: Victoria的舞会1 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 496.0 KiB
#include<stdio.h>
int main(void)
{
	int n,k,m=0,c,count=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		count=0;
		do
		{
			scanf("%d",&c);
			if(c!=0)
			count++;
		}
		while(c!=0);
		if(count>=k)
			m++;
		getchar();
	}
	printf("%d",m);
}