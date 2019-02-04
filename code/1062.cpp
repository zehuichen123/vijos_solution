//Problem 1062: 迎春舞会之交谊舞 
//Status: Accepted 
//Used Time: 30ms 
//Peak Memory: 372.0 KiB
#include<iostream>
#include<stack>
using namespace std;
int girl[1503];
stack<int>boy;
int main(void){
	int i,n,count=0,index=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>girl[i];
	}
	for(int i=0;i<n;i++){
		for(;index<girl[i];index++){
			boy.push(index);
		}
		cout<<girl[i]-boy.top()<<' ';
		boy.pop();
	}
}