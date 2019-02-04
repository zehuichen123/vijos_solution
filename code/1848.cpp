//Problem 1848: 记数问题 
//Status: Accepted 
//Used Time: 75ms 
//Peak Memory: 456.0 KiB
#include<iostream>
#include<stdio.h>
using namespace std;
int main(void)
{
	int n,m,count=0,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		x=i;
		do
		{
			if(x%10==m)
				count++;
			x=x/10;
		}
		while(x);
	}
	cout<<count<<endl;
}