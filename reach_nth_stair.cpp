#include<stdio.h>

/*  There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either
    1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top.

    ways(n) = ways(n-1) + ways(n-2). The value of ways(n) is equal to fibonacci(n+1).

    int fib(int n) {
        if (n <= 1) return n;
        return fib(n-1) + fib(n-2);
    }

    int countWays(int s) {
        return fib(s + 1);
    } */

int countWaysUtil(int n, int m) {
    int res[n];
    res[0] = 1; res[1] = 1;

    for(int i = 2; i < n; i++) {
       res[i] = 0;
       for(int j = 1; j <= m && j <= i; j++) res[i] += res[i-j];
    }
    return res[n-1];
}

int countWays(int s, int m) {
    return countWaysUtil(s+1, m);
}

int main() {
    int s = 4;  /* Number of stairs */
    int m = 2;  /* Max number of stairs a person can climb */
    printf("Number of ways = %d", countWays(s, m));
    return 0;
}
