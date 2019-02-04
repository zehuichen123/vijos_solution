//Problem 1380: 盗窃-巴黎阳光普照 
//Status: Accepted 
//Used Time: 8ms 
//Peak Memory: 384.0 KiB
#include<iostream>
using namespace std;
int num[1005];
int main(void)
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	int floor=0,sum=0;
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(num[i]*i==num[j]*j)
			{
				floor=(i+j)/2;
			}
		}
	}
	switch(m)
	{
		case 1:
			{
				for(int i=n;i>=floor;i--)
				{
					sum+=num[i];
				}
			}
			break;
		case 0:
			{
				for(int i=1;i<=floor;i++)
				{
					sum+=num[i];
				}
			}
	}
	cout<<floor<<' '<<sum<<endl;
} 