#include <stdio.h>
#include <string.h>

/*  Given a value N, if we want to make change for N cents, and we have infinite supply valued coins,
    how many ways can we make the change? The order of coins doesn’t matter.
    For N = 4 and S = {1,2,3}, there are 4 solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}.*/

int count( int S[], int m, int n ) {
    int table[n+1];
    memset(table, 0, sizeof(table));
    table[0] = 1;

    for(int i = 0; i < m; i++)
        for(int j = S[i]; j <= n; j++) table[j] += table[j-S[i]];

    return table[n];
}

int main() {
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    printf("%d\n", count(arr, m, n));
    return 0;
}
