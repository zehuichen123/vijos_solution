//Problem 1320: 清点人数 
//Status: Accepted 
//Used Time: 1105ms 
//Peak Memory: 2.395 MiB
#include<stdio.h>
int carri[500002]={0};
int main(void)
{
	int n=0,k=0,teacher=1,sum=0;
	char alph='\0'; 
	scanf("%d %d",&n,&k);
	getchar();
	for(int m=0;m<k;m++)
	{
		int a,b;
		scanf("%c",&alph);
		if(alph=='A')
		{
			scanf("%d",&a);
			for(int i=teacher;i<=a;i++)
			{
				sum+=carri[i];
			}
			teacher=a+1;
			printf("%d\n",sum);
		}
		else
		{
			scanf("%d %d",&a,&b);
			if(alph=='B')
			{
				if(a<teacher)
					sum+=b;
				else carri[a]+=b;
			}
			else
			{
				if(a<teacher)
					sum-=b;
				else carri[a]-=b;
			}
		}
		getchar();
	}
 } 