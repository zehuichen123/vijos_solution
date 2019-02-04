//Problem 1125: 自由落体 
//Status: Accepted 
//Used Time: 16ms 
//Peak Memory: 348.0 KiB
#include<iostream>
#include<cmath>
using namespace std;
int main(void){
	double H,s1,v,L,k;
	int n,ans=0;
	cin>>H>>s1>>v>>L>>k>>n;
	double tmin=sqrt((2*(H-k))/10);
	double tmax=sqrt(2*H/10);
	double begin=s1-tmax*v;
	double end=s1-tmin*v+L;
	for(int i=0;i<n;i++){
		if(begin-i<=0.00001&&i-end<=0.00001){
			ans++;
		}
	}
	cout<<ans<<endl;
} 