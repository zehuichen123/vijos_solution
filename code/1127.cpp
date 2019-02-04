//Problem 1127: 级数求和 
//Status: Accepted 
//Used Time: 15ms 
//Peak Memory: 500.0 KiB
#include<stdio.h>
int main(void)
{
  int n,i=1;
  double each,sum=0;
  scanf("%d",&n);
  while(sum<n)
  {
    each=1.0/i;
    sum+=each;
    i++;
    }
    printf("%d",i-1);
    return 0;
    }