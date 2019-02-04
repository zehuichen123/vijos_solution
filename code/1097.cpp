//Problem 1097: 合并果子 
//Status: Accepted 
//Used Time: 323ms 
//Peak Memory: 1.012 MiB
#include<iostream>
#include<stdio.h>
#define maxn 999999999
using namespace std;
int a[10000]={0};
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
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quiksort(a,0,n-1);
	for(int i=0;i<n-1;i++)
	{
		sum+=a[i]+a[i+1];
		a[i+1]+=a[i];
		for(int j=i+1;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
			else break;
		}
	}
	cout<<sum<<endl;
}