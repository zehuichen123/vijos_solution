//Problem 1248: 最厉害的机器人 
//Status: Accepted 
//Used Time: 21ms 
//Peak Memory: 368.0 KiB
#include<iostream>
using namespace std;
double k,x1,x2,x3,x4;
double Min=100000000;
void calculate(int i,int j,int p,int q)
{
	//cout<<"**********"<<endl;
	//cout<<i<<' '<<j<<' '<<p<<' '<<q<<endl;
	//double index=(20-i*2)*x1+((100-j*7)*x2*2+(100-p*9)*x3)/((10+q)*x4);
	double index=(20-i*2)*x1+((100-j*7)*x2*2+(100-p*9)*x3)/((10+q)*x4);
	if(index<Min)
	{
		
		//cout<<index<<endl;
		Min=index;
	}
	//cout<<"**********"<<endl;
}
int main(void)
{
	cin>>k>>x1>>x2>>x3>>x4;
	for(int i=0;i<=10;i++)
	{
		for(int j=0;j<=10;j++)
		{
			for(int p=0;p<=10;p++)
			{
				for(int q=0;q<=10;q++)
				{
					if(i+j+p+q==k)
					{
						//cout<<"*****8"<<endl;
						calculate(i,j,p,q);
					}
				}
			}
		}
	} 
	printf("%.3lf",Min);
} 