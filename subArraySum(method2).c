#include<stdio.h>

int subArraySum(int a[],int n,int sum)
{

    int current_sum=a[0],start=0,i;
    for(i=1;i<=n;i++)
    {
        while(current_sum>sum&& start<i-1)
        {
            current_sum-=a[start];
            start++;
        }
        if(current_sum==sum)
        {
            printf("%d , %d",start,i-1);
            return 1;
        }
        if(i<n)
            current_sum+=a[i];
    }
    printf("No subarray");
    return 0;
}
int main()
{
    int a[]={1,4,0,0,3,10,5},sum=7;
    int size=sizeof(a)/sizeof(a[0]);
    subArraySum(a,size,sum);
    return 0;
}
