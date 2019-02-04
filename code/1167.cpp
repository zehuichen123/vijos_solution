//Problem 1167: 南蛮图腾 
//Status: Accepted 
//Used Time: 0ms 
//Peak Memory: 16.52 MiB
#include<stdio.h>

char a[1<<12][1<<12];
int n,m;

void fill(int i,int j,int k)
 {
    if (k!=1) {
        fill(i,j+(1<<k),k-1);
        fill(i-(1<<(k-1)),j+(1<<(k-1)),k-1);
        fill(i,j,k-1);
    }
    else {
        a[i][j]=a[i-1][j+1]='/';
        a[i][j+1]=a[i][j+2]='_';
        a[i][j+3]=a[i-1][j+2]='\\';
    }
}

int main(void) 
{
    int k; 
	scanf("%d",&k);
    n=(1<<k);
	m=(1<<(k+1));
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j) 
            a[i][j]=' ';
    fill(n,1,k);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j) {
            putchar(a[i][j]);
        }
        printf("\n");
    }
    return 0;
}