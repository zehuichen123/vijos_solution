//Problem 1102: 陶陶摘苹果 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
int main(void)
{
	int height,num=0,chair=30;
	int apple[10];
	for(int i=0;i<10;i++)
	{
		scanf("%d",&apple[i]);
	}
	scanf("%d",&height);
	for(int j=0;j<10;j++)
	{
		if(height+chair>=apple[j])
		num++;
	}
	printf("%d",num);
}