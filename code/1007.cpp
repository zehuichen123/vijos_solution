//Problem 1007: 绕钉子的长绳子 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
#include<math.h>
#define pie 3.1415
float dis(float x1,float y1,float x2,float y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(void)
{
	int n,j;
	float r,dist,sum=0,length;
	float x[100],y[100];
	scanf("%d %f",&n,&r);
	if(1==n)
	{	
		scanf("%f %f",&x[0],&y[0]);
		printf("%.2f",2*pie*r);
	}
    else if(2==n)
	{
		scanf("%f %f %f %f",&x[0],&y[0],&x[1],&y[1]);
		dist=dis(x[0],y[0],x[1],y[1]);
		printf("%.2f",2*dist+2*pie*r);
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			scanf("%f %f",&x[i],&y[i]);
		}
		for(j=0;j<n-1;j++)
		{
			length=dis(x[j],y[j],x[j+1],y[j+1]);
			sum+=length;
		}
		sum+=dis(x[j],y[j],x[0],y[0]);
		printf("%.2f",sum+2*pie*r);
	}
 } 