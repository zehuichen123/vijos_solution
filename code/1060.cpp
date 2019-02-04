//Problem 1060: 盒子 
//Status: Accepted 
//Used Time: 32ms 
//Peak Memory: 500.0 KiB
#include <iostream>
using namespace std;
unsigned long long C(int a,int b){
    unsigned long long ans=1;
    for(int i=a+1;i<=a+b;i++){
        ans=(ans*i)/(i-a);
    }
    return ans;
}
int main(void){
    int m,a,b;
    unsigned long long temp1=0,temp2=0;
    cin>>m>>a>>b;
    //cout<<C(10,1)<<endl;
    temp1=C(m,a);
    temp2=C(m,b);
    cout<<temp1*temp2<<endl;

}