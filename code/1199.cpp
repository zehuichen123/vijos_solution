//Problem 1199: 核弹危机 
//Status: Accepted 
//Used Time: 16ms 
//Peak Memory: 372.0 KiB
#include<iostream>
using namespace std;
int map[100][100];
int main(void)
{
	int m,n,max=0;
	cin>>m>>n;
	char index;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>index;
			if(index=='.')
			{
				map[i][j]=1;
			}
			else
			{
				map[i][j]=2;
			}
		}
	}
	for(int i=0;i<m-n+1;i++)
	{
		for(int q=0;q<m-n+1;q++)
		{
			int count=0;
			for(int j=0;j<n;j++)
			{
				for(int p=0;p<n;p++)
				{
					if(map[i+j][q+p]==2)
					{
						count++;
					}
				}
			}
			if(count>max)
			max=count;
		}
	}
	cout<<max<<endl;
}