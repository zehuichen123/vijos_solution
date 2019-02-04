//Problem 1439: 区间 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 888.0 KiB
#include<stdio.h>
int right[50000]={0};
int left[50000]={0};
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
	int n=0,count=0,count1=0,count2=0,begin;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&left[i],&right[i]);
	}
	quiksort(right,0,n-1);
	quiksort(left,0,n-1);
	left[n]=0xffffff;
	while(count1<=n||count2<=n)
	{
		if(left[count1]<=right[count2])
		{
			if(count==0)
				begin=left[count1];
			count1++;
			count++;
		}
		else
		{
			count--;
			count2++;
		}
		if(count==0)
			printf("%d %d\n",begin,right[count2-1]);
	}
 } 