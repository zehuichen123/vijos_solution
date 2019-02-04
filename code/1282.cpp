//Problem 1282: 佳佳的魔法照片 
//Status: Accepted 
//Used Time: 304ms 
//Peak Memory: 756.0 KiB
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int E[11];
typedef struct person{
	int num;
	int weight;
}person;
person name[50005];
bool temp(person a,person b){
	//return (a->weight)<(b->weight);
	if(a.weight>b.weight){
		return true;
	}
	else if(a.weight<b.weight){
		return false;
	}
	else{
		return a.num<b.num;
	}
}
int main(void){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=10;i++){
		cin>>E[i];
	}
	for(int i=1;i<=n;i++){
		name[i].num=i;
		cin>>name[i].weight;
	}
	sort(name+1,name+n+1,temp);
	for(int i=1;i<=n;i++){
		name[i].weight+=E[(i-1)%10+1];
	}
	sort(name+1,name+n+1,temp);
	for(int i=1;i<=k;i++){
		cout<<name[i].num<<' ';
	}
}