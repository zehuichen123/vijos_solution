//Problem 1034: 家族 
//Status: Accepted 
//Used Time: 118ms 
//Peak Memory: 372.0 KiB
#include <iostream>
#define Max 5005
using namespace std;
int father[Max];
int rankArr[Max];
void makeSet(){
    for(int i=0;i<Max;i++){
        father[i]=i;                //首先每个节点的父节点都是本身
        rankArr[i]=0;               //每个树的初始高度都是0
    }
}
int findSet(int x){
    if(x!=father[x]){
        father[x]=findSet(father[x]);           //将每个寻找的子节点都直接指向最根节点
    }
    return father[x];
}
void unionSet(int x,int y){
    x=findSet(x);
    y=findSet(y);
    if(x==y){
        return;
    }
    else if(rankArr[y]<rankArr[x]){
        father[x]=y;
    }
    else if(rankArr[x]>rankArr[y]){
        father[y]=x;
    }
    else{
        father[x]=y;
        rankArr[y]++;
    }
}
int main(void){
    makeSet();
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=0;i<m;i++){
        int num1,num2;
        cin>>num1>>num2;
        num1=findSet(num1);
        num2=findSet(num2);
        unionSet(num1,num2);
    }
    for(int i=0;i<p;i++){
        int num1,num2;
        cin>>num1>>num2;
        num1=findSet(num1);
        num2=findSet(num2);
        if(num1==num2){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}