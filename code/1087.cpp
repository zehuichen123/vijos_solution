//Problem 1087: 铁人三项 
//Status: Accepted 
//Used Time: 7097ms 
//Peak Memory: 384.0 KiB
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef struct Player{
	int a;
	int b;
	int c;
}Player;
bool first[100]={false};
Player player[100];
int n,canWin;
void Compare(double a,double b,double c){
	double x1,x2,x3,total,min=100000;
	bool flag=0;
	for(int i=0;i<n;i++){
		x1=a/player[i].a;
		x2=b/player[i].b;
		x3=c/player[i].c;
		total=x1+x2+x3;
		if(fabs(min-total)<10e-15){
			flag=0;
		}
		if(min-total>10e-15){
			min=total;
			canWin=i;
			flag=1;
		}
	}
	if(flag)
	first[canWin]=true;
}
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>player[i].a>>player[i].b>>player[i].c;
	}
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			if(i+j>1000){
				break;
			}
			int p=1000-i-j;
			Compare(i,j,p);
		}
	}
	for(int i=0;i<n;i++){
		if(first[i]){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
}