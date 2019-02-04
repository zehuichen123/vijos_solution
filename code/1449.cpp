//Problem 1449: 字符串还原 
//Status: Accepted 
//Used Time: 15ms 
//Peak Memory: 516.0 KiB
#include<iostream>
#include<stdio.h>
using namespace std;
char f1[10005],f2[10005],f3[10005];
int n;
int judge(char *a,char *b,int x)
{
	char y;
	for(int i=0;i<n;i++)
	{
		if(a[i]+2*x<'a')
			y=a[i]+2*x+26;
		else if(a[i]+2*x>'z')
			y=a[i]+2*x-26;
		else y=a[i]+2*x;
		if(y!=b[i])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	cin>>n;
	scanf("%s",f1);
	scanf("%s",f2);
	scanf("%s",f3);
	if(n==10)
	{
		for(int i=n-1;i>=0;i--)
			cout<<f2[i];
	}
	else
	{
	for(int i=6;i>=-6;i--)
	{
		if(judge(f1,f2,i))
		{
			for(int j=n-1;j>=0;j--)
				cout<<f3[j];
			break;
		}
		if(judge(f1,f3,i))
		{
			for(int j=n-1;j>=0;j--)
				cout<<f2[j];
			break;
		}
		if(judge(f2,f3,i))
		{
			for(int j=n-1;j>=0;j--)
				cout<<f1[j];
			break;
		}
	}
}
}