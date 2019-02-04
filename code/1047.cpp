//Problem 1047: 最小公倍数 
//Status: Time Exceeded 
//Used Time: ≥7541ms 
//Peak Memory: ≥496.0 KiB
#include<stdio.h>
int main()
{
long long a,b,k;
scanf("%lld%lld",&a,&b);
for(k=1; ;k++)
{
if(k%a==0&&k%b==0) 
break;
}
printf("%d",k);
}