//Problem 1405: 古韵之同心锁 
//Status: Accepted 
//Used Time: 69ms 
//Peak Memory: 384.0 KiB
#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
int main(void)
{
	string index;
	int a,b,c;
	cin>>index;
	cin>>a>>b>>c;
	string index1(index,0,a-1);
	string index2(index,a-1);
	//cout<<index1<<' '<<index2;
	switch(b)
	{
		case 1:{
			for(int i=0;i<index.size();i++)
			{
				if('a'<=index[i]&&index[i]<='z')
				{
					index[i]=index[i]+'A'-'a';
				}
				else if('A'<=index[i]&&index[i]<='Z')
				{
					index[i]=index[i]+'a'-'A';
				}
			}
			index+="Immorta1";
			break;
		}
		case 2:{
			index=index1;
			while(index.find(index2)!=string::npos)
			{
				index.replace(index.find(index2),index2.size(),"");
			}
			while(index.find("1013")!=string::npos)
			{
				index.replace(index.find("1013"),4,"hh4742");
			}
			break;
		}
		
		case 3:{
			if(0==index1.size())
			{
				index1+=index2;
			}
			else
			index1.insert(abs(a-b)-1,index2);
			index=index1;
			break;
		}
	}
	for(int i=0;i<index.size();i++)
	{
		for(int j=0;j<c+1;j++)
		{
			cout<<index[i];
		}
	}
}