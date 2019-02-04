//Problem 1691: 输油管道问题 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 540.0 KiB
#include<stdio.h>
int y[10000]={0};
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
	int n=0,count1=0,count2=0;
	long long sum=0;
	scanf("%d",&n);
	count2=n-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&y[i]);
		scanf("%d",&y[i]);
	}
	quiksort(y,0,n-1);
	while(count1<count2)
	{
		sum+=(y[count2]-y[count1]);
		count1++;
		count2--;
	}
	printf("%lld",sum);
}