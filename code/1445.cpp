//Problem 1445: 陶陶抢苹果 
//Status: Accepted 
//Used Time: 122ms 
//Peak Memory: 4.746 MiB
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
typedef struct taotao{
	int weight;
	int apple;
}taotao;
size_t num[100000];
int appleSize[100000];
map<int,size_t>myMap;
int main(void)
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>appleSize[i];
		taotao* p=new taotao;
		num[i]=(size_t)p;
	}
	for(int i=0;i<m;i++)
	{
		int index;
		cin>>index;
		((taotao*)num[i])->weight=index;
		myMap[index]=num[i];
	}
	sort(appleSize,appleSize+n);
	map<int,size_t>::iterator iter=myMap.end();
	int count1=0;
	for(int i=0;i<n;i++)
	{
		iter--;
		((taotao*)(iter->second))->apple+=appleSize[n-i-1];
		if(iter==myMap.begin())
		iter=myMap.end();
	}
	for(int i=0;i<m;i++)
	{
		cout<<((taotao*)num[i])->apple<<' ';
	}
} 
