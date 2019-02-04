//Problem 1291: 苹果摘陶陶 
//Status: Accepted 
//Used Time: 30ms 
//Peak Memory: 504.0 KiB
#include<stdio.h>
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
	int taotao[2000]={0},apple[2000]={0};
	int n,m,pos,count=0;
	scanf("%d%d",&n,&m);
	pos=m;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&apple[i]);
	}
	for(int j=0;j<m;j++)
	{
		scanf("%d",&taotao[j]);
	}
	quiksort(taotao,0,m-1);
	for(int i=m-1;i>=0;i--)
	{
		for(int j=0;j<n;j++)
		{
			if(apple[j]>taotao[i]&&taotao[i]!=0)
			{
				apple[j]=0;
				pos--;
				break;
			}
		}
	}
	printf("%d",pos);
}