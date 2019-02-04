//Problem 1356: 比较傻的人学英语 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
#include<string.h>
int cum[11]={0};
char num[11]={0};
int flag=0;
void eleven(int a)
{
	switch(a)
	{
		case 0:{
			printf("ten");
			break;
		}
		case 1:{
			printf("eleven");
			break;
		}
		case 2:{
			printf("twelve");
			break;
		}
		case 3:{
			printf("thirteen");
			break;
		}
		case 4:{
			printf("fourteen");
			break;
		}
		case 5:{
			printf("fifteen");
			break;
		}
		case 6:{
			printf("sixteen");
			break;
		}
		case 7:{
			printf("seventeen");
			break;
		}
		case 8:{
			printf("eighteen");
			break;
		}
		case 9:{
			printf("nineteen");
			break;
		}
	}
}
void num_ty(int a)
{
	switch(a)
	{
		case 2:{
			printf("twenty");
			break;
		}
		case 3:{
			printf("thirty");
			break;
		}
		case 4:{
			printf("forty");
			break;
		}
		case 5:{
			printf("fifty");
			break;
		}
		case 6:{
			printf("sixty");
			break;
		}
		case 7:{
			printf("seventy");
			break;
		}
		case 8:{
			printf("eighty");
			break;
		}
		case 9:{
			printf("ninety");
			break;
		}
		case 0:{
			break;
		}
	} 
}
void num_en(char a)
{
	switch(a)
	{
		case 0:{
			break;
		}
		case 1:{
			printf("one");
			break;
		}
		case 2:{
			printf("two");
			break;
		}
		case 3:{
			printf("three");
			break;
		}
		case 4:{
			printf("four");
			break;
		}
		case 5:{
			printf("five");
			break;
		}
		case 6:{
			printf("six");
			break;
		}
		case 7:{
			printf("seven");
			break;
		}
		case 8:{
			printf("eight");
			break;
		}
		case 9:{
			printf("nine");
			break;
		}
	}
}
void zero(int a,int b,int c)
{
	if(flag)
		printf(" ");
	if(a!=0)
	{
		num_en(a);
		printf(" hundred");
		flag=1;
		if(b!=0||c!=0)
			printf(" ");
	}
	if(b!=0||c!=0)
	{
		if(flag)
			printf("and ");
		if(b==1)
		{
			eleven(c);
		}
		else if(b!=0)
		{
			num_ty(b);
			if(c!=0)
			printf("-");
			num_en(c);
		}
		else num_en(c);
		flag=1;
	}
}
int main(void)
{
	scanf("%s",num);
	int len=strlen(num);
	for(int i=0;i<len;i++)
	{
		cum[10-len+i]=num[i]-48;
	}
	if(len==10)
	{
		flag=1;
		num_en(cum[0]);
		printf(" billion");
		len--;
	}
	if(len/3==0||(len/3==1&&len%3==0))
	{
		if(len==1&&cum[9]==0)
		printf("zero");
		else  zero(cum[7],cum[8],cum[9]);
	}
	else if((len/3==1&&len%3!=0)||(len/3==2&&len%3==0))
	{
		if(cum[4]==0&&cum[5]==0&&cum[6]==0)
		;
		else
		{
			zero(cum[4],cum[5],cum[6]);
			printf(" thousand");
		}
		zero(cum[7],cum[8],cum[9]);
	}
	else if((len/3==2&&len%3!=0)||(len/3==3&&len%3==0))
	{
		if(cum[1]==0&&cum[2]==0&&cum[3]==0)
		;
		else
		{
			zero(cum[1],cum[2],cum[3]);
			printf(" million");
		}
		if(cum[4]==0&&cum[5]==0&&cum[6]==0)
		;
		else
		{
			zero(cum[4],cum[5],cum[6]);
			printf(" thousand");
		}
		zero(cum[7],cum[8],cum[9]);
	}
} 