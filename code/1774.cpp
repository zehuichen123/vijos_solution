//Problem 1774: 机器翻译 
//Status: Accepted 
//Used Time: 33ms 
//Peak Memory: 384.0 KiB
#include<iostream>
#include<vector>
using namespace std;
int main(void){
	vector<int>memory;
	int Capacity,wordsNum,word,count=0;
	cin>>Capacity>>wordsNum;
	for(int i=0;i<wordsNum;i++){
		int flag=0;
		cin>>word;
		for(const auto p:memory){
			if(p==word){
				flag=1;
				break;
			}
		}
		if(flag){
		}
		else{
			count++;
			memory.push_back(word);
			if(memory.size()>Capacity){
				memory.erase(memory.begin());
			}
		}
	}
	cout<<count<<endl;
} 