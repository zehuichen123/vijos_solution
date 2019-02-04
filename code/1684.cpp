//Problem 1684: 丢失的筷子 
//Status: Accepted 
//Used Time: 267ms 
//Peak Memory: 872.0 KiB
#include <iostream>
//#include <algorithm>
#include <set>
using namespace std;
set<long long>data;
using namespace std;
int main(void){
    long long n,temp;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>temp;
        auto same=data.find(temp);
        if(same==data.end()){
            data.insert(temp);
        }
        else{
            data.erase(same);
        }
    }
    cout<<(*data.begin())<<endl;
}