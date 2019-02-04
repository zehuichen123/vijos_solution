//Problem 1003: 等价表达式 
//Status: Wrong Answer 
//Used Time: 28ms 
//Peak Memory: 384.0 KiB
#include <iostream>
using namespace std;
long long mm[100];
int main(void){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>mm[i];
    }
    for(int p=0;p<t;p++){
        int yinzi[10005];
        for(int i=0;i<10005;i++){
            yinzi[i]=0;
        }
        long long n;
        n=mm[p];
        bool is_change=false;
        for(int i=2;i*i<=n;i++){
            while(n%i==0){
                //cout<<"i is"<<i<<endl;
                n/=i;
                yinzi[i]+=1;
                is_change=true;
            }
        }
        yinzi[n]+=1;
        long long my_result=1;
        if(!is_change){
            my_result=n;
        }
        else{
            //cout<<"here"<<endl;
            for(int i=1;i<10005;i++){
                if(yinzi[i]%2!=0){
                    my_result*=i;
                    if(my_result==0){
                        cout<<i<<endl;
                    }
                }
            }
        }
        cout<<"Case #"<<p+1<<":"<<endl;
        cout<<my_result<<endl;
    }
}