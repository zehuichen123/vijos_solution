//Problem 1415: 生命游戏 
//Status: Accepted 
//Used Time: 91ms 
//Peak Memory: 2.398 MiB
#include<stdio.h>
#include<string.h>
char cell1[1000][1000]={0},cell2[1000][1000]={0};
int judge(int i,int j,int p,int q)
{
	int cell=0;
	for(int m=i-1;m<i+2;m++)
	{
		for(int n=j-1;n<j+2;n++)
		{
			if(m>=0&&m<q&&n>=0&&n<p)
			{
				if(m==i&&n==j)
				;
				else
				{
					if(cell1[m][n]=='1')
						cell++;
				}
			}
		}
	}
	return cell;
}
int main(void)
{
	int m,n,t,cell=0;
	scanf("%d %d %d",&m,&n,&t);
	for(int k=0;k<n;k++)
	{
		scanf("%s",cell1[k]);
	}
	for(int k=1;k<t;k++)
	{
		for(int a=0;a<n;a++)
		{
			for(int b=0;b<m;b++)
			{
				cell=judge(a,b,m,n);
				if(cell==3)
					cell2[a][b]='1';
				else
				{
					if(cell1[a][b]=='1'&&cell==2)
					{
						cell2[a][b]='1';
					}
					else
					{
						cell2[a][b]='0';
					}
				}
			}
		}
		for(int e=0;e<n;e++)
			strcpy(cell1[e],cell2[e]);
	}
	for(int k=0;k<n;k++)
	{
		printf("%s\n",cell1[k]);
	}
} 