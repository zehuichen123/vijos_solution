//Problem 1484: ISBN号码 
//Status: Accepted 
//Used Time: 45ms 
//Peak Memory: 452.0 KiB
#include<iostream>
#include<stdio.h>
using namespace std;
int main(void)
{
	int count=0,sum=0;
	char m[20]={0};
	int num[10]={0};
	gets(m);
	for(int i=0;i<13;i++)
	{
		if(m[i]!='-')
		{
			num[count]=m[i]-'0';
			count++;
		}
	} 
	if(m[12]=='X')
		num[9]=10;
	for(int i=0;i<9;i++)
	{
		sum=sum+(i+1)*num[i];
	}
	if(sum%11==num[9])
		cout<<"Right"<<endl;
	else
	{
		for(int i=0;i<9;i++)
		{
			if(i==1||i==4)
				cout<<'-';
			cout<<num[i];
		}
		cout<<'-';
		if(sum%11==10)
			cout<<'X'<<endl;
		else cout<<sum%11<<endl;
	}
}