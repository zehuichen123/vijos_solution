//Problem 1057: 盖房子 
//Status: Accepted 
//Used Time: 122ms 
//Peak Memory: 4.578 MiB
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int a[1005][1005];
int main(void)
{
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			if(a[i][j])
			{
				a[i][j]+=min(min(a[i-1][j],a[i-1][j-1]),a[i][j-1]);
			}
		}
	}
	for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans=max(ans,a[i][j]);
	cout<<ans<<endl;
}