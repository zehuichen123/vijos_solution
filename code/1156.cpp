//Problem 1156: 猩猩散步 
//Status: Compile Error 
//Used Time: 293ms 
//Peak Memory: 37.125 MiB
#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
vector<int>prim;
bool array[50001];

char* Calculate(int p,int n){
	static char index[102];
	memset(index,0,102*sizeof(char));
	for(int i=0;i)
}
//use shai way to produce prim
void produce(const int num){
	int i=0;
	prim.clear();
	memset(array,0,50001*sizeof(bool))
	prim.push_back(2);
	for(i=3;i*i<=num;i+=2){
		if(!array[i]){
			for(int j=i*i;j<=num;j+=i){
				array[j]=true;
			}
			prim.push_back(i);
		}
	}
	while(i<=num){
		if(!array[i]){
			prim.push_back(i);
		}
		i+=2;
	}
}
//get the x! include p^ans
int Cal(int x, int p){
	int ans = 0;
	long long rec = p;
	while(x>=rec){
	 ans += x/rec;
	 rec *= p;
	}
	 return ans;
}

void C(int n,int m){
	for(int i=0;i<prim.size();i++){
		int a=Cal(m,prim[i]);
		int b=Cal(n,prim[i]);
		int c=Cal(m-n,prim[i]);
		char* index=Calculate(prim[i],a-b-c);
		plus(index,result);
	}
	cout<<"flds"<<endl;
}
int main(void){
	int m,n;
	cin>>m>>n;
	C(n,m+n);
} 