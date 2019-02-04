//Problem 1165: 火烧赤壁 
//Status: Accepted 
//Used Time: 91ms 
//Peak Memory: 656.0 KiB
#include<stdio.h>
int arry1[20000]={0},arry2[20000]={0};
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
	int n=0,x=0,y=0,count1=0,count2=0,begin,end,sum=0,count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&arry1[i],&arry2[i]);
	}
	quiksort(arry1,0,n-1);
	quiksort(arry2,0,n-1);
	for(int i=0;i<2*n;i++)
	{
		if(arry1[count1]<arry2[count2]&&count1<n)
		{
			if(count==0)
				begin=arry1[count1];
			count1++;
			count++;
		}
		else if(arry1[count1]==arry2[count2])
		{
			count1++;
			count2++;
		}
		else
		{
			count--;
			if(count==0)
			{
				end=arry2[count2];
				sum+=end-begin;
			}
			count2++;
		}
	}
	printf("%d",sum);
}