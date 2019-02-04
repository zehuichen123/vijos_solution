//Problem 1435: 简单的邮递计划 
//Status: Wrong Answer 
//Used Time: 27ms 
//Peak Memory: 384.0 KiB
#include<iostream>
using namespace std;
unsigned long long data[1004];
//f(n)=2f(n-1)+2f(n-2)-2f(n-3)+f(n-4) 
int main(void)
{
	data[1]=0;
	data[2]=2;
	data[3]=4;
	data[4]=12;
	int n;
	cin>>n;
	if(data[n]!=0)
	{
		cout<<data[n]<<endl;
	}
	else
	{
		int m=5;
		do{
			//cout<<"****************"<<endl;
			//cout<<"data[m-1]="<<data[m-1]<<"data[m-2]="<<data[m-2]<<endl;
			data[m]=2*data[m-1]+data[m-2]*2-2*data[m-3]+data[m-4];
			m++;
		}while(m!=n+1);
		//cout<<m<<endl;
		cout<<data[n]<<endl;
	}
} 