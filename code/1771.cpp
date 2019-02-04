//Problem 1771: 瑞士轮 
//Status: Accepted 
//Used Time: 2751ms 
//Peak Memory: 2.75 MiB
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct Member{
	int ability;
	int score;
	int num;
}Member;
Member member[200050];
bool cmp(const Member& a,const Member& b){
	if (a.score==b.score) return a.num<b.num;
    return a.score>b.score;
}
void Rank(int n){
	sort(member,member+2*n,cmp);
}
void compare(int a,int b){
	if(member[a].ability>member[b].ability){
		member[a].score++;
	}
	else{
		member[b].score++;
	}
	return;
}
int main(void){
	int n,r,q;
	scanf("%d%d%d",&n,&r,&q);
	for(int i=0;i<2*n;i++){
		scanf("%d",&member[i].score);
		member[i].num=i;
	}
	for(int i=0;i<2*n;i++){
		scanf("%d",&member[i].ability);
	}
	Rank(n);
	for(int i=0;i<r;i++){
		for(int j=0;j<2*n;j+=2){
			compare(j,j+1);
		}
		Rank(n);
	}
	cout<<member[q-1].num+1<<endl;
} 