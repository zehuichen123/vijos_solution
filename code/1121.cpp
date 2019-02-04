//Problem 1121: 马拦过河卒 
//Status: Accepted 
//Used Time: 370ms 
//Peak Memory: 384.0 KiB
#include<iostream>
#include<cstdio>
using namespace std;
int m,n,x,y;
int f(int p,int q)
{
	if((p==x-2&&q==y-1)||(p==x+2&&q==y-1)||(p==x-2&&q==y+1)||(p==x-1&&q==y-2)
	||(p==x-1&&q==y+2)||(p==x+1&&q==y-2)||(p==x+1&&q==y+2)||(p==x+2&&q==y+1)||(p==x&&q==y))
		return 0;
	else if(p==0&&q!=0)     //can't miss,because in this way,there may exist some positions can't pass
		return f(0,q-1);
	else if(p!=0&&q==0)
		return f(p-1,0);
	else if(p==0&&q==0)
		return 1;
	else return f(p-1,q)+f(p,q-1);
}
int main(void)
{
	cin>>m>>n>>x>>y;
	cout<<f(m,n)<<endl;
} 