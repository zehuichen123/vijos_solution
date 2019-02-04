//Problem 1002: 过河 
//Status: Memory Exceeded 
//Used Time: ≥9717ms 
//Peak Memory: ≥512.5 MiB
#include<stdio.h>
int min=100000000;
int tone[10000]={0};
int check(int length,int m)
{
	int return_1=0;
	for(int i=0;i<m;i++)
	{
		if(length==tone[i])
		{
			return_1=1;
			break;
		}
	}
	if(return_1)
	{
		return 1;
	}
	else return 0;
}
int cross(int s,int t,int L,int length,int count,int size,int m)
{
	if(length>=L)
	{
		if(count<min)
			min=count;
		return 0;
	}
	else
	{
		if(check(length,m))
		{
			count++;
		}
		for(int i=s;i<=t;i++)
		{
			cross(s,t,L,length+i,count,i,m);
		}
	}
}
int main(void)
{
	int l=0,s=0,t=0,m=0;
	scanf("%d%d%d%d",&l,&s,&t,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&tone[i]);
	}
	for(int i=s;i<=t;i++)
		{
			cross(s,t,l,i,0,i,m);
		}
	printf("%d",min);
}