//Problem 1425: 子串清除 
//Status: Accepted 
//Used Time: 186ms 
//Peak Memory: 1000.0 KiB
#include<stdio.h>
#include<string.h>
char a[257]={0};
char b[512000]={0};
int alen=0;
int check(int n)
{
	int k=0;
	while(b[n-k]==a[alen-1-k]&&k<alen)
		k++;
	if(k==alen)
		return 1;
	else return 0;
}
int main(void)
{
	int count=0,i=-1;
	char c;
	scanf("%s ",a);
	alen=strlen(a); 
	while((b[++i]=getchar())!='\n')
	{
		if(i>=alen-1)
		{
			if(b[i]==a[alen-1])
			{
				if(check(i))
				{
					count++;
					i-=alen;
				}
			}
		}
	}
	printf("%d",count);
}