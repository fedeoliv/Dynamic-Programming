#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;

/*  Finf the minimum number of trials in worst case in egg dropping game. The rules are:

    1)  An egg that survives a fall can be used again.
    2)  A broken egg must be discarded.
    3)  The effect of a fall is the same for all eggs.
    4)  If an egg breaks when dropped, then it would break if dropped from a higher floor.
    5)  If an egg survives a fall then it would survive a shorter fall.
    6)  It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor
        do not cause an egg to break.

    Input: n = 2, k = 36 (2 eggs and 36 floors) */

/* Function to get minimum number of trails needed in worst
  case with n eggs and k floors */
int eggDrop(int n, int k) {
    /* A 2D table where entery eggFloor[i][j] will represent minimum
       number of trials needed for i eggs and j floors. */
    int eggFloor[n+1][k+1];
    int res;

    /* We need one trial for one floor and 0 trials for 0 floors */
    for(int i = 1; i <= n; i++) {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }

    /* We always need j trials for one egg and j floors. */
    for(int j = 1; j <= k; j++) eggFloor[1][j] = j;

    /* Fill rest of the entries in table using optimal substructure property */
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= k; j++) {
            eggFloor[i][j] = INT_MAX;

            for(int x = 1; x <= j; x++) {
                res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
                if(res < eggFloor[i][j]) eggFloor[i][j] = res;
            }
        }
    }

    /* eggFloor[n][k] holds the result */
    return eggFloor[n][k];
}

int main() {
    int n = 2, k = 36;
    printf ("\nMinimum number of trials in worst case: %d \n", eggDrop(n, k));
    return 0;
}
