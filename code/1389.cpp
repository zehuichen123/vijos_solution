//Problem 1389: 婚礼上的小杉 
//Status: Accepted 
//Used Time: 30ms 
//Peak Memory: 764.0 KiB
#include<stdio.h>
int main(void)
{
	int first[1000]={0};
	char second[1000][260]={0};
	int i=0,j=0,k=0;
	scanf("%d",&first[i++]);
	while(getchar()==' ')
	{
		scanf("%d",&first[i]);
		i++;
	}            //i就是总共的个数 
	for(int m=0;m<i;m++)
	{
		j=0;
		while((second[first[m]][j]=getchar())!=' ')
		{
			if(second[first[m]][j]=='\n')
			{
				second[first[m]][j]=' ';
				break;
			}
			j++;
		} 
	}
	for(int m=1;m<i+1;m++)
	{
		printf("%s\n",second[m]);
	}
}