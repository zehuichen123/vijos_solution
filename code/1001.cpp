//Problem 1001: 谁拿了最多奖学金 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
int main(void)
{
	int n,sum=0,max=0,name1;
	char name[100][21];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&name[i]);
		int final,banji,lunwen,scolar=0;
		char pos,west;
		scanf("%d %d %c %c %d",&final,&banji,&pos,&west,&lunwen);
		if(final>80&&lunwen>0)
		scolar+=8000;
		if(final>85&&banji>80)
		scolar+=4000;
		if(final>90)
		scolar+=2000;
		if(final>85&&west=='Y')
		scolar+=1000;
		if(banji>80&&pos=='Y')
		scolar+=850;
		if(scolar>max)
		{
			name1=i;
			max=scolar;
		}
		sum+=scolar;
	}
	printf("%s\n%d\n%d",name[name1],max,sum);
 } 