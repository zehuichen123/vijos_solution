//Problem 1409: 纪念品分组 
//Status: Accepted 
//Used Time: 45ms 
//Peak Memory: 1.633 MiB
#include<stdio.h>
int gift[300010]={0};
void quiksort(int a[],int low,int high)
{
    int i = low;
    int j = high;  
    int temp = a[i]; 
  
    if( low < high)
    {          
        while(i < j) 
        {
            while((a[j] >= temp) && (i < j))
            { 
                j--; 
            }
            a[i] = a[j];
            while((a[i] <= temp) && (i < j))
            {
                i++; 
            }  
            a[j]= a[i];
        }
        a[i] = temp;
        quiksort(a,low,i-1);
        quiksort(a,j+1,high);
    }
    else
    {
        return;
    }
}
int main(void)
{
	int w=0,n=0,count1=0,count2,count=0;
	scanf("%d",&w);
	scanf("%d",&n);
	count2=n-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&gift[i]);
	}
	quiksort(gift,0,n-1);
	while(count1<=count2)
	{
		if(count1==count2)
		{
			count++;
			count1++;
		}
		else if(gift[count2]+gift[count1]>w)
		{
			count2--;
			count++;
		}
		else
		{
			count1++; 
			count2--;
			count++;
		}
	}
	printf("%d",count);
} 