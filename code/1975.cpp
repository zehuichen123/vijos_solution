//Problem 1975: 扫雷游戏 
//Status: Accepted 
//Used Time: 15ms 
//Peak Memory: 508.0 KiB
#include<stdio.h>
int n,m;
char map[101][101]={0};
int judge(int x,int y)
{
	int count=0;
	for(int i=x-1;i<x+2;i++)
	{
		for(int j=y-1;j<y+2;j++)
		{
			if(i==x&&j==y)	;
			else
			{
				if(i>=0&&i<=n&&j>=0&&j<=m)
				{
					if(map[i][j]=='*')
						count++;
				}
			}
		}
	}
	return count;
}
int main(void)
{
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			map[i][j]=getchar();
		}
		getchar();
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]=='?')
			{
				map[i][j]=judge(i,j);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]!='*')
				printf("%d",map[i][j]);
			else printf("*");
		}
		printf("\n");
	}
}