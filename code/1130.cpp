//Problem 1130: 数的计数 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 992.0 KiB
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int count=1;
void f(int n)
{
	for(int i=1;i<=n/2;i++)
	{
		count++;
		f(i);
	}
	if(n==1)
	{
		return;
	}
}
int main(void)
{
	int n;
	cin>>n;
	f(n);
	cout<<count<<endl;
}
