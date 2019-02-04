//Problem 1549: 中位数 
//Status: Accepted 
//Used Time: 99ms 
//Peak Memory: 1.09 MiB
#include<iostream>
#include<set>
using namespace std;
set<int>hashName;
int data[100000];
int hashTableR[200000];
int hashTableL[200000];
int main(void){
	int n,b,temp,pos;
	cin>>n>>b;
	for(int i=0;i<n;i++){
		cin>>temp;
		if(temp<b){
			data[i]=-1;
		}
		else if(temp>b){
			data[i]=1;
		}
		else{
			data[i]=0;
			pos=i;
		}
	}
	int Count=0;
	for(int i=1;i<=pos;i++){
		Count+=data[pos-i];
		hashTableL[Count+100000]++;
		hashName.insert(Count+100000);
	}
	Count=0;
	for(int i=1;i<n-pos;i++){
		Count+=data[pos+i];
		hashTableR[Count+100000]++;
	}
	int sum=0;
	for(const auto i:hashName){
		sum+=hashTableL[i]*hashTableR[200000-i];
	}
	sum+=hashTableL[100000]+hashTableR[100000];
	cout<<sum+1<<endl;
} 