//Problem 1104: 采药 
//Status: Accepted 
//Used Time: 46ms 
//Peak Memory: 1016.0 KiB
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
    cin>>size>>n;
    for(int i=0;i<n;i++){
        cin>>bag[i]>>value[i];
    }
    cout<<search(0,size)<<endl;
}