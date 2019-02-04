//Problem 1989: 迷宫 
//Status: Accepted 
//Used Time: 2554ms 
//Peak Memory: 596.0 KiB
#include<stdio.h>
int main(void)
{
	int n,q,num;
	int t,x1,y1,x2,y2;
	int x[8000],y[8000],r[8000];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&x[i],&y[i],&r[i]);
	}
	scanf("%d",&q);
	for(int j=0;j<q;j++)
	{
		num=0;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		for(int k=0;k<n;k++)
		{
			if((((x[k]-x1)*(x[k]-x1)+(y[k]-y1)*(y[k]-y1)-r[k]*r[k])<0)&&((x[k]-x2)*(x[k]-x2)+(y[k]-y2)*(y[k]-y2)-r[k]*r[k])>0)
			num++;
			if((((x[k]-x1)*(x[k]-x1)+(y[k]-y1)*(y[k]-y1)-r[k]*r[k])>0)&&((x[k]-x2)*(x[k]-x2)+(y[k]-y2)*(y[k]-y2)-r[k]*r[k])<0)
			num++;
		}
		printf("%d\n",num);
	}
} 