//Problem 1784: 数字统计 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
int ten(int i)
{
	int num=1;
	for(int j=0;j<i;j++)
	{
		num*=10;
	}
	return num;
}
int judge(int i)
{
	if(i<10)
		return 1;
	else if(i>=10&&i<100)
		return 2;
	else if(i>=100&&i<1000)
		return 3;
	else if(i>=1000&&i<10000)
		return 4;
	else return 5;
} 
int main(void)
{
	int left,right,count=0,count1=0,abs;
	scanf("%d%d",&left,&right);
	for(int i=left;i<=right;i++)
	{
		count=judge(i);
		for(int j=0;j<count;j++)
		{
			abs=ten(j);
			if(((i/abs)%10)==2)
				count1++;
		}
	}
	printf("%d",count1);
}
