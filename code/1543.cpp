//Problem 1543: 极值问题 
//Status: Accepted 
//Used Time: 31ms 
//Peak Memory: 348.0 KiB
#include<iostream>
using namespace std;
int main(void){
	long long k,a=1,b=1;
	cin>>k;
	while(b<k){
		long long index=b;
		if(a+b>k){
			break;
		}
		b=a+b;
		a=index;
	}
	cout<<a*a+b*b<<endl;
} 