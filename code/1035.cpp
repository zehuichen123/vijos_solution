//Problem 1035: 贪婪的送礼者 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
#include<string.h>
int main(void)
{
	int num,i,j;
	char name[100][15];
	int rece[100]={0},give[100]={0},fri[100];
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%s",&name[i]);	
	}
	for(i=0;i<num;i++)
	{
		int every=0;
		char name1[15];
		scanf("%s",&name1);
		for(j=0;j<num;j++)
		{
			if(strcmp(name1,name[j])==0)
			break;
		}
		scanf("%d %d",&give[j],&fri[j]);
		if(fri[j]!=0)
		{
			every=give[j]/fri[j];
			give[j]=give[j]-give[j]%fri[j];
			for(int k=0;k<fri[j];k++)
			{
				char name2[15];
				scanf("%s",&name2);
				for(int l=0;l<num;l++)
				{
					if(strcmp(name2,name[l])==0)
					{rece[l]+=every;
					break;}
				}
			}
    	}
	}
	for(i=0;i<num;i++)
	{
		printf("%s %d\n",name[i],rece[i]-give[i]);
	}
	
 } 