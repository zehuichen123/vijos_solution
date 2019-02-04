//Problem 1662: 最大配对 
//Status: Accepted 
//Used Time: 389ms 
//Peak Memory: 1.25 MiB
#include<stdio.h>
int a[100000]={0},b[100000]={0};
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
int compare(int i,int j)
{
	if(i>j)
		return i-j;
	else return j-i;
}
int main(void)
{
	int n,k,counta1=0,counta2,countb1=0,countb2,i=0;
	unsigned long long sum=0;
	scanf("%d%d",&n,&k);
	counta2=countb2=n-1;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	quiksort(a,0,n-1);
	quiksort(b,0,n-1);
	while(i<k)
	{
		int p,q;
		p=compare(a[counta1],b[countb2]);
		q=compare(a[counta2],b[countb1]);
		if(p>q)
		{
			counta1++;
			countb2--;
			sum+=p;
		}
		else
		{
			counta2--;
			countb1++;
			sum+=q;
		}
		i++;
	}
	printf("%lld",sum);
} 