#include<stdio.h>
//Complexity:O(n^2)
int maxIndexDiff(int a[], int n)
{
    int maxDiff=-1,i,j;
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[i]<a[j] && maxDiff<j-i)
                maxDiff=j-i;
        }
    }
    return maxDiff;
}
int main()
{
	int arr[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
	int n = sizeof(arr)/sizeof(arr[0]);
	int maxDiff = maxIndexDiff(arr, n);
	printf("%d", maxDiff);
	return 0;
}
