//Problem 1988: 自行车比赛 
//Status: Accepted 
//Used Time: 1494ms 
//Peak Memory: 1.637 MiB
#include<stdio.h>
int arry[300000];
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
	int n,i,num,max,extra=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arry[i]);
	}
    quiksort(arry,0,n-1);
    max=arry[0]+n;
	num=0;
    for(i=0;i<n;i++)
    {
    	if(arry[i]+n-i>max)
    	{max=arry[i]+n-i;
    	num=i;
		}
	}
	for(int j=num;j>0;j--)
	{
		if(arry[j]+n>=max&&arry[j]+n>=arry[0]+n-j)
		extra++;
		if(j==1)
			extra--;
	}
	printf("%d",n-num+extra);
}