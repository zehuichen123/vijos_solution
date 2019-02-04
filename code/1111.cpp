//Problem 1111: 小胖的水果 
//Status: Accepted 
//Used Time: 3ms 
//Peak Memory: 352.0 KiB
#include <iostream>
#include <memory.h>
using namespace std;
int dp[105][105];
int main(void){
    string a,b;
    while(cin>>a){
        cin>>b;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                if(a[i]==b[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                }
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        cout<<a.size()+b.size()-dp[a.size()][b.size()]<<endl;
    }
}