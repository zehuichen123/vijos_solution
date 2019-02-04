//Problem 1756: 数字反转 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 496.0 KiB
#include<stdio.h>
#include<string.h>
int main(void)
{
	char num[11]={0};
	scanf("%s",num);
	int len=strlen(num),flag=1,check=0;
	if(num[0]=='-')
	{
		printf("-");
		flag=0;
	}
	for(int i=0;i<len-1;i++)
	{
		if(num[len-1-i]!='0')
		{
			check=1;
		}
		if(check)
			printf("%c",num[len-1-i]);
	}
	if(flag)
		printf("%c",num[0]);
}