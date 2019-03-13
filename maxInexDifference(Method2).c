#include <stdio.h>
#include<stdlib.h>
//Complexity:O(n)
int max(int x, int y)
{
	return x > y? x : y;
}
int min(int x, int y)
{
	return x < y? x : y;
}
int maxIndexDiff(int arr[], int n)
{
	int maxDiff,i,j;
	int *LeftMin = (int *)malloc(sizeof(int)*n);
	int *RightMax = (int *)malloc(sizeof(int)*n);
	LeftMin[0] = arr[0];
	for (i = 1; i < n; ++i)
		LeftMin[i] = min(arr[i], LeftMin[i-1]);
	RightMax[n-1] = arr[n-1];
	for (j = n-2; j >= 0; --j)
		RightMax[j] = max(arr[j], RightMax[j+1]);
	i = 0, j = 0, maxDiff = -1;
	while (j < n && i < n)
	{
		if (LeftMin[i] < RightMax[j])
		{
			maxDiff = max(maxDiff, j-i);
			j = j + 1;
			printf("%d\n",maxDiff);
		}
		else
			i = i+1;
	}

	return maxDiff;
}
int main()
{
	int arr[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
	int n = sizeof(arr)/sizeof(arr[0]);
	int maxDiff = maxIndexDiff(arr, n);
	printf("\n %d", maxDiff);
	return 0;
}
