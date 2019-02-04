//Problem 1772: 巧妙填数 
//Status: Accepted 
//Used Time: 3ms 
//Peak Memory: 384.0 KiB
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
void check(int num)
{
	bool index[10]={0};
	int num1,num2;
	for(int i=0;i<10;i++)
	{
		index[i]=0;
	}
	if(num*3>=1000)
	{
		return;
	}
	string check1,check2,check3;
	check1=to_string(num);
	num1=num*2;
	check2=to_string(num1);
	num2=num*3;
	check3=to_string(num2);
	for(int i=0;i<3;i++)
	{
		if(index[check1[i]-48])
		{
			return;
		}
		index[check1[i]-48]=1;
		if(index[check2[i]-48])
		{
			return;
		}
		index[check2[i]-48]=1;
		if(index[check3[i]-48])
		{
			return ;
		}
		index[check3[i]-48]=1;
	}
	if(index[0]==0)
	cout<<num<<" "<<num*2<<" "<<num*3<<endl;
}
int main(void)
{
	bool used[10]={0};
	for(int i=0;i<10;i++)
	{
		used[i]=0;
	}
	for(int i=1;i<4;i++)
	{
		used[i]=1;
		for(int j=1;j<10;j++)
		{
			if(!used[j])
			{
				used[j]=1;
				for(int p=1;p<10;p++)
				{
					if(!used[p])
					{
						int num=i*100+j*10+p;
						check(num);
					}
				}
				used[j]=0;
			}
		}
		used[i]=0;
	}
} 