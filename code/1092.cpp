//Problem 1092: 全排列 
//Status: Time Exceeded 
//Used Time: ≥3026ms 
//Peak Memory: ≥368.0 KiB
#include<iostream>
#include<cstdlib>
#include<memory.h>
using namespace std;
int n,m,count=0;
int ans[25]={0};
void dfs(int num,bool used[]){
	if(num==n){
		count++;
		if(count==m){
			for(int i=0;i<n;i++){
				cout<<ans[i]+1<<' ';
			}
			exit(0);
		}
		return;
	}
	for(int i=0;i<n;i++){
		if(used[i]){
			ans[num]=i;
			used[i]=0;
			dfs(num+1,used);
			used[i]=1;
		}
	}
}
int main(void){
	cin>>n>>m;
	bool used[25];
	memset(used,1,sizeof(bool)*n);
	dfs(0,used);
}