//Problem 1058: 粘贴文本 
//Status: Accepted 
//Used Time: 1183ms 
//Peak Memory: 3.539 MiB
#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(con)
typedef struct con
{
	int content;
	struct con *next;
}con;
int main(void)
{
	con *head,*p1,*p2,*p3,*p4,*p0;
	int n,k,i;
	scanf("%d %d",&n,&k);
	p1=(con*)malloc(LEN);
	head=p1;
	for(i=0;i<n-1;i++)
	{
		p1->content=i+1;
		p2=(con*)malloc(LEN);
		p2->next=NULL;
		p1->next=p2;
		p1=p1->next;
	}
	p1->content=i+1;
	p1->next=NULL;
	for(int j=0;j<k;j++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		p0=p2=p3=p4=head;
		for(i=0;i<b;i++)
		{
			if(i==a-2) p2=p0;
			if(i==a-1) p3=p0;
			if(i==b-1) p4=p0;
			p0=p0->next;
		}
		if(a==1)
		{
			head=p4->next;
		}
		else
		{
			p2->next=p4->next;
		}
		p1=head;
		for(i=0;i<c-1;i++)
		    p1=p1->next;
		if(c==0)
		{
			p4->next=head;
			head=p3;
		}
		else
		{
			p4->next=p1->next;
			p1->next=p3;	
		}
	}
	p1=head;
	for(i=0;i<10;i++)
	{
		printf("%d\n",p1->content);
		p1=p1->next;
	}
 } 