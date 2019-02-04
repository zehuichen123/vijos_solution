//Problem 1217: 乒乓球 
//Status: Accepted 
//Used Time: 30ms 
//Peak Memory: 552.0 KiB
#include<iostream>
#include<stdio.h>
using namespace std;
char b[100000]={0};
int main(void)
{
	int count1=0,count2=0,now=0;
	char a;
	while((a=getchar())!='E')
	{
		if(a=='L'||a=='W')
			b[now++]=a;		
	}
	for(int i=0;i<now;i++)
	{
		if(b[i]=='W')
			count1++;
		else count2++;
		if((count1==11&&count2<=9)||(count2==11&&count1<=9))
		{
			cout<<count1<<':'<<count2<<'\n';
			count1=0;
			count2=0;
			continue;
		}
		else if((count1>=11&&count2>=10)||(count2>=11&&count1>=10))
		{
			if(count1-count2>=2||count1-count2<=-2)
			{
				cout<<count1<<':'<<count2<<'\n';
				count1=0;
				count2=0;
				continue;
			}
		}
	}
	cout<<count1<<':'<<count2<<'\n'<<'\n';
	count1=0;count2=0;
	for(int i=0;i<now;i++)
	{
		if(b[i]=='W')
			count1++;
		else count2++;
		if((count1==21&&count2<=19)||(count2==21&&count1<=19))
		{
			cout<<count1<<':'<<count2<<'\n';
			count1=0;
			count2=0;
			continue;
		}
		else if((count1>=21&&count2>=20)||(count2>=21&&count1>=20))
		{
			if(count1-count2>=2||count1-count2<=-2)
			{
				cout<<count1<<':'<<count2<<'\n';
				count1=0;
				count2=0;
				continue;
			}
		}
	}
	cout<<count1<<':'<<count2<<endl;
}