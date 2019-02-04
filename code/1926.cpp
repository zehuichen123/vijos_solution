//Problem 1926: 紫色的手链 
//Status: Accepted 
//Used Time: 172ms 
//Peak Memory: 500.0 KiB
#include<iostream>
#include<stack>
using namespace std;
stack<int>data;
int main(void){
	int n,index,ans=-1;
	cin>>n;
	cin>>index;
	data.push(index);
	for(int i=1;i<n;i++){
		cin>>index;
		while(!data.empty()&&index>=data.top()){
			int dex=index^data.top();
			ans=dex>=ans?dex:ans;
			data.pop();
		}
		if(!data.empty()){
			int dex=index^data.top();
			ans=dex>=ans?dex:ans;
		}
		data.push(index);
	}
	cout<<ans<<endl;
}