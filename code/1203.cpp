//Problem 1203: CoVH之资料页数 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 504.0 KiB
#include<stdio.h>
int file[1001]={0};
int main(void)
{
	int n,k,f,x,y,now=1,content=0,page=0;
	scanf("%d%d",&n,&k);
	scanf("%d",&f);
	for(int i=0;i<f;i++)
	{
		scanf("%d%d",&x,&y);
		file[x]+=y;       //数组从1开始 
	}
	while(now<=n)
	{
		do
		{
			content+=(file[now]+1);
			now++;
		}
		while(content<k);
		if(content>k)
		{
			content=0;
			content+=(file[now-1]+1);
		}
		else content=0;
		page++;
	}
	printf("%d",page);
}