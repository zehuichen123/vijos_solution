//Problem 1728: Yakeeswap 
//Status: Accepted 
//Used Time: 31ms 
//Peak Memory: 384.0 KiB
#include<iostream>
using namespace std;
int data[55][55];
bool isBelong[2000];
int ans[55];
int main(void)
{
	for(int i=0;i<1999;i++)
	{
		isBelong[i]=true;
	}
	int n,index;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>index;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>data[i][j];
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		int j=n-1;
		while(isBelong[data[i][j]]==false)
		{
			j--;
		}
		isBelong[data[i][j]]=false;
		ans[i]=data[i][j];
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<' ';
	}
} 