//Problem 1742: 数据统计 
//Status: Accepted 
//Used Time: 98ms 
//Peak Memory: 1.625 MiB
#include<iostream>
#include <algorithm>
#include <map>
using namespace std;
map<int,int>num;
int data[50005];
int main(void){
    int m;
    cin>>m;
    double sum=0;
    for(int i=0;i<m;i++){
        cin>>data[i];
        sum+=data[i];
        num[data[i]]++;
    }
    printf("%.2lf\n",sum/m);
    sort(data,data+m);
    if(m%2){
        printf("%.2lf\n",(double)data[m/2]);
    }
    else{
        int temp=data[m/2]+data[(m-1)/2];
        printf("%.2lf\n",temp/2.);
    }
    //auto iter=num.begin();
    int max=0;
    for(auto iter=num.begin();iter!=num.end();iter++){
        if(iter->second>max){
            max=iter->second;
        }
    }
    for(auto iter=num.begin();iter!=num.end();iter++){
        if(iter->second==max){
            cout<<iter->first<<' ';
        }
    }
}