//Problem 1788: 第k大 
//Status: Accepted 
//Used Time: 92ms 
//Peak Memory: 884.0 KiB
#include<stdio.h>
int score[100000]={0};
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
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&score[i]);
	}
	quiksort(score,0,n-1);
	printf("%d",score[n-k]);
}