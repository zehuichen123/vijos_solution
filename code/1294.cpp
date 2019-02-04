//Problem 1294: 拯救OIBH总部 
//Status: Accepted 
//Used Time: 72ms 
//Peak Memory: 512.0 KiB
#include<iostream>
using namespace std;
char map[505][505];
int m,n,flag=1,sum=0,count=0;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void dfs(int x,int y)
{
	int gx,gy;
	map[x][y]='*';
	for(int i=0;i<4;i++)
	{
		gx=x+dx[i];
		gy=y+dy[i];
		if(gx>=1&&gx<=n&&gy>=1&&gy<=m)
		{
			if(map[gx][gy]=='0')
			{
				sum++;
				dfs(gx,gy);
			}
		}
		else
		{
			flag=0;
		}
	}
}
int main(void)
{
	//int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>map[i][j];
		}
	}
	for(int i=2;i<=n-1;i++)
	{
		for(int j=2;j<=m-1;j++)
		{
			if(map[i][j]=='0')
			{
				flag=1;
				sum=1;
				dfs(i,j);
				if(flag)
				{
					count+=sum;
				}
			}
		}
	}
	cout<<count<<endl;
}