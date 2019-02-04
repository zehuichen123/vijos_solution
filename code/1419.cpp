//Problem 1419: Dejected Birthday-替身 
//Status: Accepted 
//Used Time: 16ms 
//Peak Memory: 380.0 KiB
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<string>sen;
char words[100][100]={0};
bool check(int p,int q)
{
	int count=0;
	for(int i=0;i<sen[p].size();i++)
	{
		if(sen[p][i]!=words[q][i]&&count==0)
		{
			count++;
		}
		else if(sen[p][i]!=words[q][i]&&count!=0)
		{
			return false;
		}
	}
	return true;
}
int main(void)
{
	string sentence,index;
	int n=0,count=0;
	char symbol='\0';
	cin>>n;
	while(1)
	{
		getchar();
		cin>>index;
		if(index[index.size()-1]=='!')
		{
			symbol=index[index.size()-1];
			index.erase(index.end()-1);
			sen.push_back(index);
			break;
		}
		sen.push_back(index);
	}
	
	sen[0][0]+='a'-'A';
	
	for(int i=0;i<n;i++)
	{
		cin>>words[i];
	}
	for(int i=0;i<sen.size();i++)
	{
		for(int j=0;j<n;j++)
		{
			if(sen[i].size()==strlen(words[j]))
			{
				if(strcmp(sen[i].c_str(),words[j])==0)
				{
					break;
				}
				if(check(i,j))
				{
					sen[i]=words[j];
					count++;
					break;
				}
			}
		} 
	}
	sen[0][0]+='A'-'a';
	cout<<count<<endl;
	for(int i=0;i<sen.size();i++)
	{
		if(sen.size())
		cout<<sen[i];
		int p=sen.size();
		if(i!=p-1)
		{
			cout<<' ';
		}
		else
		{
			cout<<symbol;
		}
	}
	//cout<<symbol<<endl; 
}