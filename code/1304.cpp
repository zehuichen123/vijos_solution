//Problem 1304: 回文数 
//Status: Accepted 
//Used Time: 15ms 
//Peak Memory: 1.199 MiB
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string m;
int len,n,a[100001]={0};
void repeat()
{
	int c[100001]={0};
	for(int i=0;i<len;i++)
	{
		c[i]+=a[i]+a[len-i-1];
		if(c[i]>=n)
		{
			c[i]%=n;
			c[i+1]++;
			if(i==len-1)
			{
				len++;
				break;
			}
		}
	}
	for(int i=0;i<len;i++)
	{
		a[i]=c[len-i-1];
	}
}
bool judge(int y[])
{
	for(int i=0;i<len;i++)
	{
		if(y[i]!=y[len-i-1])
			return 0;
	}
	return 1;
}
int main(void)
{
	cin>>n>>m;
	len=m.size();
	for(int i=0;i<len;i++)
	{
		if(m[i]<65)
			a[i]=m[i]-'0';
		else a[i]=m[i]-55;
	}
	for(int i=0;i<30;i++)
	{
		if(judge(a))
		{
			cout<<"STEP="<<i<<endl;
			return 0;
		}
		else
		{
			repeat();
		}
	}
	cout<<"Impossible!"<<endl;
}