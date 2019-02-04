//Problem 1317: 开心的金明 
//Status: Accepted 
//Used Time: 36ms 
//Peak Memory: 508.0 KiB
#include<iostream>
#include<memory.h>
using namespace std;
int bag[26],value[26],dp[30005];
int main(void){
    int n,size;
    cin>>size>>n;
    memset(dp,0,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<n;i++){
        cin>>bag[i]>>value[i];
    }
    for(int i=0;i<n;i++){
        for(int j=size;j>=bag[i];j--){
            dp[j]=max(dp[j],dp[j-bag[i]]+bag[i]*value[i]);
        }
    }
    cout<<dp[size]<<endl;
}