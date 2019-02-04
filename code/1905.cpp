//Problem 1905: 生活大爆炸版 石头剪刀布 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 496.0 KiB
#include<stdio.h>
int judge(int i,int j)
{
	if(i==j)
		return 0;
	else if((i==0&&(j==1||j==4))||(i==1&&(j==2||j==4))||(i==2&&(j==0||j==3))||(i==3&&(j==0||j==1))||(i==4&&(j==2||j==3)))
		return -1;
	else return 1;
}
int main(void)
{
	int n,na,nb,counta=0,countb=0,result;
	int a[200]={0},b[200]={0};
	scanf("%d %d %d",&n,&na,&nb);
	getchar(); 
	for(int i=0;i<na;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<nb;i++)
	{
		scanf("%d",&b[i]);
	}
	for(int i=0;i<n;i++)
	{
		result=judge(a[i%na],b[i%nb]);
		if(result>0)
			counta++;
		else if(result<0)
			countb++;
	}
	printf("%d %d",counta,countb);
}