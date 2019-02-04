//Problem 1116: 一元三次方程求解 
//Status: Accepted 
//Used Time: 15ms 
//Peak Memory: 744.0 KiB
#include<stdio.h>
#include<iostream>
#include<stdlib.h> 
using namespace std;
int main(void)
{
	double x=-100,a,b,c,d,fx;
	cin>>a>>b>>c>>d;
	for(x;x<=100;x+=0.01)
	{
		fx=a*x*x*x+b*x*x+c*x+d;
		if(fx<0.01&&fx>-0.01)
		{
			printf("%.2lf ",x);
		}
	}
	return 0;
}