#include<stdio.h>
void subArraySum(int a[],int n,int sum)
{

    int current_sum,i,j;
    for(i=0;i<n;i++)
    {
        current_sum=a[i];
        for(j=i+1;j<=n;j++)
        {
            if(current_sum==sum)
            {

                printf("%d , %d",i,j-1);
                return 1;
            }
            if(current_sum>sum || j==n)
                break;
            current_sum+=a[j];
        }
    }
    printf("No subarray");
}
int main()
{
    int a[]={1,4,0,0,3,10,5},sum=7;
    int size=sizeof(a)/sizeof(a[0]);
    subArraySum(a,size,sum);
    return 0;
}
