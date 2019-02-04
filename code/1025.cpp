//Problem 1025: 小飞侠的游园方案 
//Status: Accepted 
//Used Time: 41ms 
//Peak Memory: 1.0 MiB
#include<iostream>
#include<memory.h>
using namespace std;
int n,size;
int value[105],bag[105];
int record[105][1500];
int search(int count,int rest){
    if(count==n){
        return 0;
    }
    else if(rest-bag[count]<0){
        record[count][rest]=search(count+1,rest);
    }
    if(record[count][rest]<0){
        record[count][rest]=max(search(count+1,rest),search(count+1,rest-bag[count])+value[count]);
    }
    return record[count][rest];
}
int main(void){
    memset(record,-1,sizeof(record));
    cin>>n>>size;
    for(int i=0;i<n;i++){
        cin>>value[i]>>bag[i];
    }
    cout<<search(0,size)<<endl;
}