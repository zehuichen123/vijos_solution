//Problem 1835: 维护数列 
//Status: Time Exceeded 
//Used Time: ≥14941ms 
//Peak Memory: ≥3.926 MiB
#include<iostream>
#include<deque>
#include<string>
#include<vector>
#include<stack>
using namespace std;
deque<int>Data;
void getSum() {
	//cout << "getSum" << endl;
	long long pos, tot, sum = 0;
	cin >> pos >> tot;
	pos--;
	for (int i = pos;i<pos + tot;i++) {
		sum += Data[i];
	}
	cout << sum << endl;
	/*for(const auto i:Data){
		cout<<i<<' ';
	}
	*/
}
void maxSum() {
	//cout << "maxSum" << endl;
	long long ans = 0, temp = 0;
	for (const auto i : Data) {
		temp += i;
		if (temp>ans) {
			ans = temp;
		}
		else if (temp <= 0) {
			temp = 0;
		}
	}
	cout << ans << endl;
	/*for(const auto i:Data){
		cout<<i<<' ';
	}*/
}
void Insert() {
	//cout << "Insert" << endl;
	int pos, tot, temp;
	vector<int>toBeInsert;
	cin >> pos >> tot;
	pos--;
	for (int i = 0;i<tot;i++) {
		cin >> temp;
		toBeInsert.push_back(temp);
	}
	auto itor = Data.begin() + pos+1;
	Data.insert(itor, toBeInsert.begin(), toBeInsert.end());
	/*for(const auto i:Data){
		cout<<i<<' ';
	}*/
}
void Delete() {
	//cout << "Del" << endl;
	int pos, tot;
	cin >> pos >> tot;
	pos--;
	auto itorBegin = Data.begin() + pos;
	auto itorEnd = Data.begin() + pos + tot;
	Data.erase(itorBegin, itorEnd);
	/*for(const auto i:Data){
		cout<<i<<' ';
	}*/
}
void makeSame() {
	//cout << "makEsame" << endl;
	long long pos, tot, temp;
	cin >> pos >> tot >> temp;
	pos--;
	for (int i = pos;i<pos + tot;i++) {
		Data[i] = temp;
	}
	/*for(const auto i:Data){
		cout<<i<<' ';
	}*/
}
void Reverse() {
	stack<int>toBeReverse;
	int pos, tot, i;
	cin >> pos >> tot;
	pos--;
	for (i = pos;i<pos + tot;i++) {
		toBeReverse.push(Data[i]);
	}
	for(i=pos;i<pos+tot;i++) {
		Data[i] = toBeReverse.top();
		toBeReverse.pop();
	}
	/*for(const auto i:Data){
		cout<<i<<' ';
	}*/
}
int main(void) {
	int N, M, temp;
	string order;
	cin >> N >> M;
	for (int i = 0;i<N;i++) {
		cin >> temp;
		Data.push_back(temp);
	}
	for (int i = 0;i<M;i++) {
		cin >> order;
		if (order == "GET-SUM") {
			getSum();
		}
		else if (order == "MAX-SUM") {
			maxSum();
		}
		else if (order == "INSERT") {
			Insert();
		}
		else if (order == "MAKE-SAME") {
			makeSame();
		}
		else if (order == "REVERSE") {
			Reverse();
		}
		else {
			Delete();
		}
	}
}