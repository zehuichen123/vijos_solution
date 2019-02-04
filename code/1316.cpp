//Problem 1316: 明明的随机数 
//Status: Accepted 
//Used Time: 31ms 
//Peak Memory: 384.0 KiB
#include<iostream>
#include<set>
using namespace std;
int main(void)
{
	set<int>a;
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int num=0;
		cin>>num;
		a.insert(num);
	}
	set<int>::iterator iter;
	cout<<a.size()<<endl;
	for(iter=a.begin();iter!=a.end();iter++)
	{
		cout<<*iter<<' ';
	}
} 