//Problem 1495: 笨小猴 
//Status: Accepted 
//Used Time: 15ms 
//Peak Memory: 496.0 KiB
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char letter[101]={0};
int time[101]={0};
int findmax(int *time,int count)
{
	int max=0;
	for(int i=0;i<count;i++)
	{
		if(time[i]>max)
		{
			max=time[i];
		}
	}
	return max;
}
int findmin(int *time,int count)
{
	int min=time[0];
	for(int i=1;i<count;i++)
	{
		if(time[i]<min)
		{
			min=time[i];
		}
	}
	return min;
}
int judge(int num)
{
	int return_1=1;
	for(int i=2;i<num;i++)
	{
		if(num%i==0)
		{
			return_1=0;
			break;
		}
	}
	if(num==0||num==1)
		return_1=0;
	if(num==2||num==3)
		return_1=1;
	if(return_1)
		return 1;                          //a prime
	else return 0;
}
int main(void)
{
	int num=0,count=0,return_1=1,max=0,min=0;
	char words[101]={0};
	gets(words);
	num=strlen(words);
	for(int i=0;i<num;i++)
	{
		return_1=1;
		for(int j=0;j<count;j++)
		{
			if(words[i]==letter[j])
			{
				time[j]++;
				return_1=0;
				break;
			}
		}
		if(return_1)
		{
			letter[count++]=words[i];
		}
	}
	max=findmax(time,count);
	min=findmin(time,count);
	if(judge(max-min))
	{
		printf("Lucky Word\n%d",max-min);
	}
	else printf("No Answer\n0");
}