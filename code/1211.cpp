//Problem 1211: 生日日数 
//Status: Accepted 
//Used Time: 15ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
int judge(int year)
{
	if(year%4==0&&year%100!=0)
		return 1;
	else if(year%400==0)
		return 1;
	else return 0;
}

int main(void)
{
	int year0,month0,date0,m,sum=0,return_1=0,return_2=1;
	int ping[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int run[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	scanf("%d %d %d",&year0,&month0,&date0);
	for(m=0;m<26;m++)
	{
		if((judge(year0+m+1)))
			sum+=366;
		else	sum+=365;
	}
	if(judge(year0))
	{
		sum+=run[month0-1]-date0;
		for(int m=month0;m<12;m++)
		{
			sum+=run[m];
		} 
	}
	else
	{
		sum+=ping[month0-1]-date0;
		for(m=month0;m<12;m++)
		{
			sum+=ping[m];
		}
	}
	if(judge(year0+27))
	{
		for(m=0;m<12;m++)
		{
			sum+=run[m];
			if(sum>=10000)
			{
				sum-=run[m];
				return_2=0;
				break;
			 } 
		}
	}
	else
	{
		for(m=0;m<12;m++)
		{
			sum+=ping[m];
			if(sum>=10000)
			{
				sum-=ping[m];
				return_2=0;
				break;
			}
		}
	}
	if(sum<10000&&return_2==1)
	{
		return_1=1;
		if(judge(year0+28))
		{
			for(m=0;m<12;m++)
			{
				sum+=run[m];
				if(sum>=10000)
				{
					sum-=run[m];
					break;
				}
			}
		}
		else 
		{
			for(m=0;m<12;m++)
			{
				sum+=ping[m];
				if(sum>=10000)
				{
					sum-=ping[m];
					break;
				}
			}
		}
	}
	if(return_1)
	{
			printf("%d-%d-%d",year0+28,m+1,10000-sum);
	}
	else	printf("%d-%d-%d",year0+27,m+1,10000-sum);
}