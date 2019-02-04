//Problem 1090: 连续数之和 
//Status: Accepted 
//Used Time: 297ms 
//Peak Memory: 1.125 MiB
#include<iostream>
using namespace std;
unsigned long long sum=0,count=0;
unsigned long long data[100001];
int n,k;
int main(void)
{
	cin>>n>>k;
	long index;
	for(int i=0;i<n;i++)
	{
		cin>>index;
		sum+=index;
		if(sum%k==0)
		{
			count++;
		}
		count=(count+data[sum%k])%1234567;
		data[sum%k]++;
	}
	
	cout<<count<<endl;
} 