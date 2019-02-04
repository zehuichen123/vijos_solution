//Problem 1572: 小委出发 
//Status: Accepted 
//Used Time: 132ms 
//Peak Memory: 37.484 MiB
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
char stringData[5000000];
bool Data[5000000];
typedef struct slash{
	char Slash;
	int pos;
}slash;
stack<slash>check;
int main(void){
	cin>>stringData;
	int index=0,ansBegin=0,ansEnd=0,length=0;
	while(stringData[index]!='\0'){
		if(stringData[index]=='('||stringData[index]=='['||stringData[index]=='{'){
			auto p=new slash;
			p->Slash=stringData[index];
			p->pos=index;
			check.push(*p);
		}
		else{
			if(check.size()==0){
			}
			else if((check.top().Slash=='('&&stringData[index]==')')||(check.top().Slash=='['&&stringData[index]==']')||
			(check.top().Slash=='{'&&stringData[index]=='}')){
				{
					ansBegin=check.top().pos;
					ansEnd=index;
					for(int i=ansBegin;i<=ansEnd;i++){
						Data[i]=1;
					}
				}
				check.pop();
			}
			else{
				//clear the stack
				int Size=check.size();
				for(int i=0;i<Size;i++){
					check.pop();
				}
			}
		}
		index++;
	}
	int begin=0,end=0;
	for(int i=0;i<strlen(stringData);i++){
		if(i==0&&Data[i]==1){
			begin=0;
		}
		else if(Data[i]==1&&Data[i-1]==0){
			begin=i;
		}
		else if(Data[i]==1&&Data[i+1]==0){
			end=i;
			if(length<end-begin){
				ansEnd=end;
				ansBegin=begin;
				length=ansEnd-ansBegin; 
			}
		}
	}
	for(int i=ansBegin;i<=ansEnd;i++){
		cout<<stringData[i];
	}
} 