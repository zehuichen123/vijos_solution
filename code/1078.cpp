//Problem 1078: 松鼠吃果子 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 496.0 KiB
#include<stdio.h>
#include<string.h>
int main(void)
{
	int n,m,pos,now=1,step,count=0,flag=0;
	int fruit[200]={0};
	scanf("%d%d",&n,&m);
	memset(fruit,1,n*sizeof(int));
	for(int i=1;i<=m;i++)
	{
		flag=0;
		count=0;
		step=(i*i*i)%5+1;
		pos=now+1;
		while(count<step)
		{
			if(fruit[pos]!=0)
			{
				count++;
				pos++;
			}
			else pos++;
			if(pos>n)
			{
				flag=1;               //restart
				break;
			}
		}
		if(flag)
		{
			now=1;
			pos=now+1;
			count=0;
			while(count<step)
			{
				if(fruit[pos]!=0)
				{
					count++;
					pos++;
				}
				else pos++;
			}
		}
		now=pos;
		fruit[now]=0;
		now--;
	}
	printf("%d",now);
}