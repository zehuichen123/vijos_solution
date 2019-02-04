//Problem 1132: 求二叉树的先序序列 
//Status: Accepted 
//Used Time: 11ms 
//Peak Memory: 256.0 KiB
#include<iostream>
#include<string>
using namespace std;
void findPas(string a,string b){
	int ll,lr,i;
	for(int i=0;i<a.size();i++){
		if(a[i]==b[b.size()-1]){
			cout<<b[b.size()-1];
			ll=i;
			lr=a.size()-ll-1;
			if(ll){
				string index1(a,0,ll),index2(b,0,ll);
				findPas(index1,index2);
			}
			if(lr){
				string index3(a,i+1,lr),index4(b,i,lr);
				findPas(index3,index4);
			}
			break;
		}
	}
}

int main(void){
	string a,b;
	cin>>a>>b;
	findPas(a,b);
} 