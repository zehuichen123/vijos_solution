//Problem 1309: 分凸多边形 
//Status: Wrong Answer 
//Used Time: 13ms 
//Peak Memory: 364.0 KiB
#include<iostream>
using namespace std;
int main(void)
{
	size_t n,m,index=1;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		index*=2;
	}
	size_t ans=(2*n*n-2*n+4)%index;
	cout<<ans<<endl;
}