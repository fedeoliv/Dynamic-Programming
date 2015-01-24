#include<stdio.h>
#include <algorithm>
#define KMAX 1001
using namespace std;

/*  Given weights and values of n items, put these items in a knapsack
    of capacity W to get the maximum total value in the knapsack.

    Input: val[] = {60, 100, 120}, wt[] = {10, 20, 30}, W = 50
    Output: 220 */

/*  Returns the maximum value that can be put in a knapsack of capacity W */
int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n+1][W+1];

    /* Build table K[][] in bottom up manner */
    for(i = 0; i <= n; i++) {
        for(w = 0; w <= W; w++) {
            if(i == 0 || w == 0) K[i][w] = 0;
            else if(wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
            else K[i][w] = K[i-1][w];
        }
    }

    return K[n][W];
}

int main() {
    int k;          /* Maximum weight */
    int m;          /* Amount of bags */
    int val[KMAX];  /* Value of the bag */
    int w[KMAX];    /* Weight of the bag */

    scanf("%d %d", &k, &m);
    for(int i = 0; i < m; i++) scanf("%d %d", &w[i], &val[i]);

    printf("%d\n", knapSack(k, w, val, m));
    return 0;
}
