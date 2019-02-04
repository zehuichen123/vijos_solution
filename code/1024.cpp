//Problem 1024: 卡布列克圆舞曲 
//Status: Accepted 
//Used Time: 38ms 
//Peak Memory: 384.0 KiB
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
set<string>dataNum;
vector<unsigned long long>record;
void init(){
	dataNum.clear();
	record.clear();
}
unsigned long long sortString(string& data){
	sort(data.begin(),data.end());
	unsigned long long min=atoll(data.c_str());
	reverse(data.begin(),data.end());
	unsigned long long max=atoll(data.c_str());
	return max-min;
}
unsigned long long get10(int num){
	unsigned long long ans=1;
	for(int i=0;i<num;i++){
		ans*=10;
	}
	return ans;
}
void check(string& data){
	unsigned long long index=sortString(data);
	string value=to_string(index);
	if(value.size()<data.size()){
		index*=get10(data.size()-value.size());
	}
	value=to_string(index);
	if(dataNum.find(value)==dataNum.end()){
		dataNum.insert(value);
		record.push_back(index);
		check(value);
	}
	else{
		int i=0;
		for(i=0;i<record.size();i++){
			if(record[i]==index){
				break;
			} 
		}
		for(int j=i;j<record.size();j++){
			cout<<record[j]<<' ';
		}
		cout<<endl;
		return;
	}
}
int main(void){
	string num;
	while(cin>>num){
		init();
		record.push_back(atoll(num.c_str()));
		dataNum.insert(num);
		check(num);
	}
}