//Problem 1625: 精卫填海(HOI) 
//Status: Accepted 
//Used Time: 150ms 
//Peak Memory: 452.0 KiB
#include <iostream>
using namespace std;
int k[10000],m[100000];
int dp[10000];
int main(void){
	int v,n,c;
	cin>>v>>n>>c;
	for(int i=0;i<n;i++){
		cin>>k[i]>>m[i];
	}
	for(int i=0;i<n;i++){
		for(int j=v;j>=m[i];j--){
			dp[j]=max(dp[j],dp[j-m[i]]+k[i]);
		}
	}
	for(int i=0;i<=c;i++){
		if(dp[i]>=v) {
			cout << c - i<<endl;
			exit(0);
		}
	}
	cout<<"Impossible"<<endl;
}