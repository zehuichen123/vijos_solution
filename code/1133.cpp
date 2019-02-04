//Problem 1133: 装箱问题 
//Status: Accepted 
//Used Time: 54ms 
//Peak Memory: 1.043 MiB
#include<iostream>
using namespace std;
int array[20001]={0};
int main(void)
{
	int n,v,ex;
	cin>>v>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ex;
		for(int j=v;j>=0;j--)
		{
			if(array[j]!=0)
			{
				if(j+ex<=v)
				array[j+ex]=1;
			}
		}
		array[ex]=1;
	}
	for(int i=v;i>=0;i--)
	{
		if(array[i]!=0)
		{
			cout<<v-i<<endl;
			break;
		}
	}
	return 0;
} 