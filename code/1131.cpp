//Problem 1131: 最小公倍数和最大公约数问题 
//Status: Accepted 
//Used Time: 30ms 
//Peak Memory: 456.0 KiB
#include<iostream>
#include<stdio.h>
#include<stdlib.h> 
using namespace std; 
int judge(int x,int y)
{	int c;
	while(y!=0)  
   { 
   		c=x%y; x=y;  y=c;
   }
   return x;
}
int main(void)
{
	int n,m,count=0;
	cin>>n>>m;
	for(int i=n;i<=m;i++)
	{
		for(int j=n;j<=m;j++)
		{
			if(i*j==n*m)
			{
				if(judge(i,j)==n)
					count++;
			}
		}
	}
	cout<<count;
}
