//Problem 1335: 数独验证 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 508.0 KiB
#include<stdio.h>
int shudu[20][9][9]={0};
int row_judge(int a)
{
	int judge=0;
	for(int i=0;i<9;i++)
	{
		judge=1;
		int check[9]={0};
		for(int j=0;j<9;j++)
		{
			check[shudu[a][j][i]-1]=1;
		}
		for(int j=0;j<9;j++)
		{
			judge*=check[j];
		}
		if(judge==0)
			break;
	}
	return judge;
}
int line_judge(int a)
{
	int judge=0;
	for(int i=0;i<9;i++)
	{
		judge=1;
		int check[9]={0};
		for(int j=0;j<9;j++)
		{
			check[shudu[a][i][j]-1]=1;
		}
		for(int j=0;j<9;j++)
		{
			judge*=check[j];
		}
		if(judge==0)
			break;
	}
	return judge;
}
int fur_judge(int i,int j,int a)
{
	int judge=1;
	int check[9]={0};
	for(int m=i-1;m<i+2;m++)
	{
		for(int n=j-1;n<j+2;n++)
		{
			check[shudu[a][m][n]-1]=1;
		}
	}
	for(int b=0;b<9;b++)
	{
		judge*=check[b];
	}
	if(judge==0)
		return 0;
	else	return 1;
}
int nine_judge(int a)
{
	int judge=1;
	for(int i=1;i<9;i+=3)
	{
		for(int j=1;j<9;j+=3)
		{
			judge*=fur_judge(i,j,a);
		}
	}
	return judge;
}
int main(void)
{
	int n=0,check=0,judge1=0,judge2=0,judge3=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<9;j++)
		{
			for(int k=0;k<9;k++)
			{
				scanf("%d",&shudu[i][j][k]);
			}
		}
		getchar();
	}
	for(int i=0;i<n;i++)
	{
		judge1=row_judge(i);
		judge2=line_judge(i);
		judge3=nine_judge(i);
		if(judge1*judge2*judge3==0)
			printf("Wrong\n");
		else printf("Right\n");
	} 
}