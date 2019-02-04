//Problem 1359: Superprime 
//Status: Accepted 
//Used Time: 9ms 
//Peak Memory: 384.0 KiB
#include<iostream>
using namespace std;
int n=0,num=0;
bool check(int num)
{
	if(num==1)
	return false;
	for(int i=2;i*i<=num;i++)
	{
		if(num%i==0)
		{
			return false;
		}
	}
	return true;
}
void dfs(int pos)
{
	if(pos==n+1)
	{
		cout<<num<<endl;
		return;
	}
	for(int i=1;i<=9;i++)
	{
		num=num*10+i;
		if(check(num))
		{
			//index*=10;
			//count++;
			dfs(pos+1);
			//index/=10;
		}
		num=(num-i)/10;
	}
}
int main(void)
{
	
	cin>>n;
	dfs(1);
	
} 