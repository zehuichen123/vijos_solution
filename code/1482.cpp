//Problem 1482: 信息筛选 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
#include<string.h>
int len=0;
int check2(int n,char *str)
{
	int return_1=0;
	for(int i=n+1;i<len-2;i++)
	{
		if(str[i]==str[n])
		{
			for(int j=i+1;j<len-1;j++)
			{
				for(int p=j+1;p<len;p++)
				{
					if(str[j]==str[p])
					{
						return_1=1;
						break;
					}
				}
				if(return_1)
					break;
			}
		}
		if(return_1)
			break;
	}
	return return_1;
}
int check1(int n,char *str)
{
	int return_1=0,return_2=0,check=0;
	for(int i=n+3;i<len;i++)
	{
		if(str[i]==str[n])
		{
			check=i;
			return_1=1;
		}
	}
	if(return_1)
	{
		for(int i=n+1;i<check-1;i++)
		{
			for(int j=i+1;j<check;j++)
			{
				if(str[i]==str[j])
				{
					return_2=1;
					break;
				}
			}
		} 
	}
	return return_1*return_2;
}
int main(void)
{
	int n=0;
	scanf("%d",&n);
	getchar(); 
	for(int i=0;i<n;i++)
	{
		int return_1=0;
		char str[11]={0};
		gets(str);
		len=strlen(str);
		if(len>=4)
		{
			for(int j=0;j<=len-4;j++)
			{
				if(check1(j,str))
				{
					return_1=1;
					break;
				}
				if(check2(j,str))
				{
					return_1=1;
					break;
				}
			}
		}
		if(return_1)
			printf("de1ete");
		else	printf("safe");
		if(i<n-1)
		printf("\n");
	}
}