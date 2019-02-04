//Problem 1041: 神风堂人数 
//Status: Accepted 
//Used Time: 1ms 
//Peak Memory: 1008.0 KiB
#include<iostream>
using namespace std;
int main(void)
{
	double a,b;
	cin>>a>>b;
	a/=100;
	b/=100;
	for(int i=1;i<=10004;i++)
	{ 
		if((i*b)-(int)(i*a)-1>1e-4)
		{
			cout<<i<<endl;
			return 0;
		}
	}
}