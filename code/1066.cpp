//Problem 1066: 弱弱的战壕 
//Status: Accepted 
//Used Time: 176ms 
//Peak Memory: 512.0 KiB
#include <iostream>
#include <vector>
using namespace std;
typedef struct Data{
    int x;
    int y;
    int count;
}Data;
vector<Data>fort;
int protect[40000];
int main(void){
    int n=0;
    cin>>n;
    Data* p;
    for(int i=0;i<n;i++){
        p=new Data;
        cin>>p->x;
        cin>>p->y;
        p->count=0;
        fort.push_back(*p);
    }
    for(int i=0;i<fort.size();i++){
        for(int j=0;j<fort.size();j++){
            if(fort[i].x>=fort[j].x&&fort[i].y>=fort[j].y&&i!=j){
                fort[i].count++;
            }
        }
        protect[fort[i].count]++;
    }

    for(int i=0;i<n;i++){
        cout<<protect[i]<<endl;
    }
}