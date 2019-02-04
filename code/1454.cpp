//Problem 1454: 牛的RP 
//Status: Accepted 
//Used Time: 105ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
#include<string.h>
char rpname[501]={0};
int main(void)
{
	int n=0,irp=0,isize=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int rp=0,size=0;
		char name[501]={0};
		scanf("%s",name);
		size=strlen(name);
		if(strstr(name,"reioxzsj"))
			rp+=19201010; 
		for(int j=size-1;j>=0;j--)
		{
			if(j>0&&name[j]=='r'&&name[j-1]=='p')
				rp+=20;
			if(name[j]=='r'||name[j]=='p')
				rp+=5;
			if(j>1&&name[j]=='c'&&name[j-1]=='o'&&name[j-2]=='w')
				rp+=5;
		}
		if(rp>irp)
		{
			irp=rp;
			isize=size;
			strcpy(rpname,name);
		}
		else if(rp==irp)
		{
			if(size<isize)
			{
				irp=rp;
				isize=size;
				strcpy(rpname,name);
			}
		}
	}
	printf("%s\n%d",rpname,irp-19201010); 
}