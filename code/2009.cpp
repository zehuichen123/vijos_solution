//Problem 2009: 买铅笔 
//Status: Accepted 
//Used Time: 64ms 
//Peak Memory: 384.0 KiB
#include <iostream>
using namespace std;
int main(void){
    int needNum;
    cin>>needNum;
    unsigned long long min=0xffffffffffffffff;
    int percelNum[3],price[3];
    for(int i=0;i<3;i++){
        cin>>percelNum[i]>>price[i];
    }
    for(int i=0;i<3;i++){
        unsigned long long needBuy;
        if(needNum%percelNum[i]==0){
            needBuy=needNum/percelNum[i];
        }
        else{
            needBuy=needNum/percelNum[i]+1;
        }
        unsigned long long cost=needBuy*price[i];
        if(cost<min){
            min=cost;
        }
    }
    cout<<min<<endl;
}