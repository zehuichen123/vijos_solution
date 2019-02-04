//Problem 1122: 出栈序列统计 
//Status: Accepted 
//Used Time: 28ms 
//Peak Memory: 384.0 KiB
#include <iostream>
using namespace std;
long long C(int a,int b){
	long long ans=1;
	for(int i=0;i<a;i++){
		ans=ans*(b-i)/(i+1);
	}
	return ans;
}
int main(void){
	int n;
	cin>>n;
	cout<<C(n,2*n)-C(n-1,n*2)<<endl;
}