//Problem 1093: 文科生的悲哀 
//Status: Accepted 
//Used Time: 15ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
int main()
{
int a=1,b=1,c,d,i=1;
scanf("%d",&d);
for(i=3;i<=d;i++)
{   
    c=(a+b)%7654321;
	a=b;
	b=c;
}
if(d>2)
	printf("%d",c);
else
    printf("1");
	return 0;
}