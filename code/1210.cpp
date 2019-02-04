//Problem 1210: 盒子与球 
//Status: Wrong Answer 
//Used Time: 17ms 
//Peak Memory: 384.0 KiB
#include <iostream>
using namespace std;
long long C(int a,int b){
	long long ans=1;
	if(a==0||a==b){
		return 1;
	}
	long long child=1,parent=1;
	for(int i=0;i<a;i++){
		child*=(b-i);
		parent*=(i+1);
	}
	return child/parent;
}
int main(void){
	int r,n;
	long long ans=0;
	cin>>n>>r;
	for(int i=n;i>=0;i--){
		int oneOrZero=(n-i)%2?-1:1;
		long long temp=1;
		for(int j=0;j<n;j++){
			temp*=(r-n+i);
		}
		ans+=(oneOrZero)*C(i,n)*temp;
	}
	cout<<ans<<endl;
}