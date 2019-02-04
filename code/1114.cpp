//Problem 1114: FBI树 
//Status: Accepted 
//Used Time: 30ms 
//Peak Memory: 384.0 KiB
#include<iostream>
#include<string>
using namespace std;
string index;
void judge(int _begin,const int _end){
	bool flag1=0,flag2=0;
	do{
		if(index[_begin]=='1'){
			flag1=1;
			if(flag2){
				cout<<'F';
				return;
			}
		}
		else if(index[_begin]=='0'){
			flag2=1;
			if(flag1){
				cout<<'F';
				return;
			}
		}
		_begin++;
	}while(_begin<=_end);
	if(flag1){
		cout<<'I';
	}
	else{
		cout<<'B';
	}
	return;
}
void print(const int begin,const int end){
	if(end==begin){
		judge(begin,end);
	}
	else{
		print(begin,(begin+end)/2);
		print((begin+end)/2+1,end);
		judge(begin,end);
	}
}
int main(void){
	int n;
	int count=1<<n;
	cin>>n;
	cin>>index;
	print(0,index.size()-1);
}