//Problem 1911: 珠心算测验 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 532.0 KiB
#include<iostream>
#include<stdio.h>
using namespace std;
int a[20002],num[101];
int main(void)
{
	int n,count=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			a[num[i]+num[j]]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[num[i]]==1)
		count++;
	}
	cout<<count<<endl;
}