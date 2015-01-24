#include <stdio.h>
#include <algorithm>

using namespace std;

/*  Problems using binomial coefficient:
    - There are C(n, k) ways to choose k elements from a set of n elements without repetitions.
    - There are C(n+k-1, k) ways to choose k elements from a set of n elements if repetitions are allowed.
    - There are C(n+k, k) strings containing k ones and n zeros.
    - There are C(n+1, k) strings consisting of k ones and n zeros such that no two ones are adjacent.
    - Catalan numbers: (1/(n+1))* C(2*n, n).
    - Binomial distribution:    Number of successes in a sequence of n independent yes/no experiments,
                                each of which yields success with probability p.
                                C(n, k)*p^k*(1-p)^(n-k).
*/

/*  A space optimized Dynamic Programming Solution */
int binomialCoeff(int n, int k) {
    int* C = (int*) calloc(k+1, sizeof(int));
    int i, j, res;

    C[0] = 1;

    for(i = 1; i <= n; i++)
        for(j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j-1];

    res = C[k]; /* Store the result before freeing memory */
    free(C);    /* Free dynamically allocated memory to avoid memory leak */

    return res;
}

int main() {
    int n = 5, k = 2;
    printf("%d\n", binomialCoeff(n, k));
    return 0;
}
