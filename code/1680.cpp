//Problem 1680: 距离 
//Status: Accepted 
//Used Time: 102ms 
//Peak Memory: 15.012 MiB
#include<iostream>
#include<memory.h>
#include<cmath>
using namespace std;
int dp[2005][2005];
int main(void){
	string a,b;
	int k;
	cin>>a>>b>>k;
	for(int i=0;i<a.size();i++){
		dp[i+1][0]=dp[i][0]+k;
	}
	for(int i=0;i<b.size();i++){
		dp[0][i+1]=dp[0][i]+k;
	}
	for(int i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){
			if(a[i]==b[j]){
				dp[i+1][j+1]=dp[i][j];
			}
			else{
				dp[i+1][j+1]=min(dp[i][j]+abs(a[i]-b[j]),min(dp[i+1][j],dp[i][j+1])+k);
			}
		}
	}
	cout<<dp[a.size()][b.size()]<<endl;
}