#include<stdio.h>
#include <stdlib.h>

/*  Find the sum of maximum sum subsequence of the given array such that the integers
    in the subsequence are sorted in increasing order.*/

/*  maxSum() returns the maximum sum of increasing subsequence in arr[] of size n */
int maxSum(int arr[], int n) {
    int *msis, i, j, max = 0;
    msis = (int*) malloc (sizeof(int)*n);

    /* Initialize msis values for all indexes */
    for(i = 0; i < n; i++) msis[i] = arr[i];

    /* Compute maximum sum values in bottom up manner */
    for(i = 1; i < n; i++)
        for(j = 0; j < i; j++)
            if(arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
                msis[i] = msis[j] + arr[i];

    /* Pick maximum of all msis values */
    for(i = 0; i < n; i++)
        if(max < msis[i]) max = msis[i];

    return max;
}

int main() {
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", maxSum(arr, n));
    return 0;
}
