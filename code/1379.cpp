//Problem 1379: 字符串的展开 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
int main(void)
{
	int p1,p2,p3,flag=1;
	char a,b,c;
	scanf("%d%d%d ",&p1,&p2,&p3);
	a=getchar();
	while((b=getchar())!='\n')
	{
		if(b!='-')
		{
			printf("%c",a);
			a=b;
		}
		else   //b=='-'
		{
			c=getchar();
			if(c=='\n')
			{
				printf("%c%c",a,b);
				flag=0;
				break;
			}
			else
			{
				if((97<=c&&c<=122&&97<=a&&a<=122)||(48<=c&&c<=57&&48<=a&&a<=57))
				{
					if(c-a>1)
					{
						printf("%c",a);
						if(p3==1)
						{
							for(int i=a+1;i<c;i++)
							{
								for(int j=0;j<p2;j++)
								{
									if(p1==2&&i>96&&i<123)
										printf("%c",i-32);
									else if(p1==3)
										printf("*");
									else printf("%c",i);
								}
							}
						}
						else
						{
							for(int i=c-1;i>a;i--)
							{
								for(int j=0;j<p2;j++)
								{
									if(p1==2&&i>96&&i<123)
										printf("%c",i-32);
									else if(p1==3)
										printf("*");
									else printf("%c",i);
								}
							}
						}
						a=c;
					}
					else if(c-a==1)
					{
						printf("%c",a);
						a=c;
					}
					else
					{
						printf("%c%c",a,b);
						a=c;
					}
				}
				else
				{
					printf("%c%c",a,b);
					a=c;
				}
			}
		}
	}
	if(a!='\n'&&flag==1)
		printf("%c",a);
}