//Problem 1230: 数的朗读 
//Status: Accepted 
//Used Time: 28ms 
//Peak Memory: 376.0 KiB
#include <iostream>
#include <cstring>
using namespace std;
char num[50];
char zheng[50];
void read(char* wan,int flag)
{
	if(wan[0]!='0')
	{
		cout<<wan[0]<<'Q';
		flag=1;
	}
	if(wan[1]!='0')
	{
		if(wan[0]=='0'&&flag)
		{
			cout<<wan[0];
		}
		cout<<wan[1]<<'B';
		//flag=1;
	}
	if(wan[2]!='0')
	{
		if(wan[1]=='0'&&flag)
		cout<<wan[1];
		cout<<wan[2]<<'S';
	}
	if(wan[3]!='0'&&wan[2]=='0'&&flag)
	{
		cout<<wan[2]<<wan[3];
	}
	if(wan[3]!='0'&&wan[2]=='0'&&!flag)
	{
		cout<<wan[3];
	}
	if(wan[3]!='0'&&wan[2]!='0')
	{
		//if(wan[1]=='0')
		//cout<<wan[1];
		cout<<wan[3];
	}
	return;
} 
int main(void)
{
	int count1=0,count2=0,count3=0;
	int length=0;
	
	char wan[5];
	char wan2[5];
	char wan1[5];
	for(int i=0;i<5;i++)
	{
		wan[i]='0';
		wan1[i]='0';
		wan2[i]='0';
	}
	for(int i=0;i<50;i++)
	{
		zheng[i]='\0';
	}
	cin>>num;
	//sprintf(num,"%llf",m);
	//cout<<num<<endl;
	//cout<<strlen(num)<<endl;
	//cout<<"*****"<<endl;
	length=strlen(num);
	int flag3=0;
	for(int i=0;i<length;i++)
	{
		if(num[i]=='.')
		{
			flag3=1;
			count3=i;
		}
	}
	
	if(num[0]=='-')
	{
		cout<<'F';
		count1++;
	}
	else if(num[0]=='+')
	{
		count1++;
	}
	int flag=0;
	for(int i=count1;i<length;i++)
	{
		if(num[i]=='.')
		{
			break;
		}
		if(num[i]!='0')
		{
			flag=1;
		}
		if(flag)
		{
			zheng[count2]=num[i];
			count2++;
		}
	}
	//cout<<zheng<<"********"<<endl;
	//cout<<"*********"<<endl;
	int ptr=0;
	//cout<<count2<<endl;
	//Y
	if(count2==9)
	{
		cout<<zheng[0]<<'Y';
		ptr++;
	}
	//W
	if(count2>4)
	{
		int index=count2-4-ptr;
		for(int i=0;i<index;i++)
		{
			wan[3-i]=zheng[count2-1-4-i];
		}
		read(wan,ptr);
		if(wan[1]!='0'||wan[0]!='0'||wan[2]!='0'||wan[3]!='0')
		cout<<'W';
		for(int i=0;i<4;i++)
		{
			wan2[3-i]=zheng[count2-1-i];
		}
		read(wan2,1);
	}
	if(count2<=4)
	{
		for(int i=0;i<count2;i++)
		{
			wan1[3-i]=zheng[count2-1-i];
		}
		read(wan1,0);
	}
	if(count2==0)
	{
		cout<<'0';
	}
	//cout<<"**********"<<endl;
	//cout<<length<<endl;
	if(flag3&&!((num[length]=='\0')&&num[length-1]=='.'))
	{
		cout<<'D'; 
		for(int i=count3+1;i<length;i++)
		{
			cout<<num[i];
		}
	}
	
}