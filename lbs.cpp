#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;

/*  A subsequence of arr[] is called Bitonic if it is first increasing, then decreasing.
    Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
    Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1) */

/*  Function to copy a[] content to b[]. */
void revArrCpy(int a[], int b[], int n) {
    for(int i = 0; i < n; i++) b[n-i-1] = a[i];
}

/*  Binary search function to return the index. */
int binSearch(int a[], int low, int high, int x) {
    while(low < high) {
        int mid = low + (high - low)/2;

        if(a[mid] < x) low = mid+1;
        else if(a[mid] > x) high = mid;
        else return mid;
    }

    return low;
}

/*  Longest increasing subsequence to lis[] based on the content in a[]. */
void getLISArray(int a[], int lis[], int n) {
    int i = 0, len = 0, end[n];

    end[i] = a[0];
    lis[i] = len+1;

    for(i = 1; i < n; i++) {
        if(a[i] <= end[len]) {
            int pos = binSearch(end, 0, len, a[i]);
            lis[i] = pos+1;
            end[pos] = a[i];
        } else {
            end[++len] = a[i];
            lis[i] = len+1;
        }
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*  Function to reverse values in a[]. */
void reverse(int a[], int n) {
    int low = 0,high = n-1;

    while(low < high) {
        swap(a+low, a+high);
        low++;
        high--;
    }
}

int lbs(int a[], int n) {
    int lis[n], lds[n], rev[n];
    int m = INT_MIN;

    for(int i = 0; i < n; i++) lis[i] = lds[i] = 1;

    getLISArray(a, lis, n);
    revArrCpy(a, rev, n);

    getLISArray(rev, lds, n);
    reverse(lds, n);

    for(int i = 0; i < n; i++)
        m = max(m, lis[i]+lds[i]-1);

    return m;
}

int main() {
    int a[] = {80, 60, 30, 40, 20, 10};
    int n = sizeof(a)/sizeof(a[0]);
    printf("%d\n", lbs(a,n));
    return 0;
}
