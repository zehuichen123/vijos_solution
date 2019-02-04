//Problem 1236: 上帝的爱好 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 516.0 KiB
#include<stdio.h>
#include<string.h>
int num[4010]={0};
int main(void)
{
	int count=0,n,x,flag=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		num[x]+=1;
		if(num[x]==2)
		{
			if(flag)
			{
				count++;
				memset(num,0,4010*sizeof(int));
				flag=0;
			}
			else
			{
				flag=x;
			}
		}
		else if(num[x]==4)
		{
			flag=0;
			memset(num,0,4010*sizeof(int));
			count++;
		}
	}
	printf("%d",count);
}