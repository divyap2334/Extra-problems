#include<iostream>
using namespace std;

void findNumbers(int a[],int n)
{
    int axorb=0,rsetbit,k,i=0,j=0,av=0,b=0,minval,maxval;
    int setbit[n],unsetbit[n];
    for(k=0;k<n;k++)
        axorb^=a[k];
    rsetbit=axorb & ~(axorb-1);
    for(k=0;k<n;k++)
    {

        if(a[k]&rsetbit)
            setbit[i++]=a[k];
        else
            unsetbit[j++]=a[k];
    }
    for(k=0;k<i;k++)
        av^=setbit[k];
    for(k=0;k<j;k++)
        b^=unsetbit[k];
    minval=av<b?av:b;
    maxval=av>b?av:b;
    printf("%d %d",minval,maxval);
}
int main()
{
    int t,n,num,i,j,a[1000];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        num=2*n+2;
        for(j=0;j<num;j++)
            scanf("%d",&a[j]);
        findNumbers(a,num);
    }
    return 0;
}
