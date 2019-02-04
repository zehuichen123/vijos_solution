//Problem 1736: 铺地毯 
//Status: Accepted 
//Used Time: 87ms 
//Peak Memory: 508.0 KiB
#include <iostream>
using namespace std;
int x[10003];
int y[10003];
int length[10003];
int width[10003];
int main(void)
{
	int n,flag=0,ans;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i]>>length[i]>>width[i];
	}
	int p,q;
	cin>>p>>q;
	for(int i=0;i<n;i++)
	{
		if(x[i]+length[i]>=p&&y[i]+width[i]>=q&&x[i]<=p&&y[i]<=q)
		{
			flag=1;
			ans=i;
		}
	}
	if(flag)
	cout<<ans+1<<endl;
	else
	{
		cout<<"-1"<<endl;
	}
}