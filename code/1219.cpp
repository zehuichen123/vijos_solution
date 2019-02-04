//Problem 1219: 拉面之窗 
//Status: Accepted 
//Used Time: 30ms 
//Peak Memory: 384.0 KiB
#include<iostream>
#include<deque>
using namespace std;
typedef struct Win{
	int leftX;
	int leftY;
	int rightX;
	int rightY;
}Win;
deque<Win>windows;
void Open(){
	auto temp=new Win;
	cin>>temp->leftX>>temp->leftY>>temp->rightX>>temp->rightY;
	windows.push_back(*temp);
}
void Click(){
	int touchX,touchY;
	cin>>touchX>>touchY;
	for(int i=windows.size()-1;i>=0;i--){
		if(windows[i].leftX<=touchX&&windows[i].leftY<=touchY
			&&windows[i].rightX>=touchX&&windows[i].rightY>=touchY){
				auto temp=windows[i];
				windows.erase(windows.begin()+i);
				windows.push_back(temp);
				break;
			}
	}
}
void Move(){
	int touchX,touchY,moveX,moveY;
	cin>>touchX>>touchY>>moveX>>moveY;
	for(int i=windows.size()-1;i>=0;i--){
		if(windows[i].leftX<=touchX&&windows[i].leftY<=touchY
			&&windows[i].rightX>=touchX&&windows[i].rightY>=touchY){
				auto temp=windows[i];
				temp.leftX+=moveX;
				temp.leftY+=moveY;
				temp.rightX+=moveX;
				temp.rightY+=moveY;
				windows.erase(windows.begin()+i);
				windows.push_back(temp);
				break;
			}
	}
}
void Close(){
	int touchX,touchY;
	cin>>touchX>>touchY;
	for(int i=windows.size()-1;i>=0;i--){
		if(windows[i].leftX<=touchX&&windows[i].leftY<=touchY
			&&windows[i].rightX>=touchX&&windows[i].rightY>=touchY){
				windows.erase(windows.begin()+i);
				break;
			}
	}
}
int main(void){
	int n;
	cin>>n;
	string order;
	for(int i=0;i<n;i++){
		cin>>order;
		if(order=="Open"){
			Open();
		}
		else if(order=="Click"){
			Click();
		}
		else if(order=="Move"){
			Move();
		}
		else{
			Close();
		}
	}
	if(windows.empty()){
		cout<<"Nothing"<<endl;
	}
	else{
		cout<<windows.back().leftX<<' '<<windows.back().leftY<<' '
		<<windows.back().rightX<<' '<<windows.back().rightY<<endl;
	}
}