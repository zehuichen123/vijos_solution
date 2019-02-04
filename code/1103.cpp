//Problem 1103: 校门外的树 
//Status: Accepted 
//Used Time: 15ms 
//Peak Memory: 528.0 KiB
#include<stdio.h>
int main(void)
{
	int tree[10001]={0};
	int L,M,a,b,i,num=0;
	scanf("%d %d",&L,&M);
	for(i=0;i<M;i++)
	{
		scanf("%d %d",&a,&b);
		for(int j=a;j<=b;j++)
		{
			tree[j]=1;
		}
	}
	for(i=0;i<=L;i++)
	{
		if(tree[i]==0)
		num++;
	}
	printf("%d",num);
 } 