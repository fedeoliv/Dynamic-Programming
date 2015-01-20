#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define SENTINEL (-1)
#define EDIT_COST (1)

/*  Given two strings of size m, n and set of operations replace (R), insert (I) and delete (D) all at equal cost.
    Find minimum number of edits (operations) required to convert one string into another.

    Example: Convert SUNDAY to SATURDAY:
    Add 'A', add 'T', replace 'N' to 'R'. Total: 3 changes */

inline int min(int a, int b) {
   return a < b ? a : b;
}

/*  Returns Minimum among a, b, c */
int minimum(int a, int b, int c) {
    return min(min(a, b), c);
}

/*  Strings of size m and n are passed. Construct the Table for X[0...m, m+1], Y[0...n, n+1] */
int editDistance(char X[], char Y[]) {
    int cost = 0;   /* Cost of alignment */
    int leftCell, topCell, cornerCell;
    int m = strlen(X) + 1;
    int n = strlen(Y) + 1;

    /*  T[m][n] */
    int *T = (int *)malloc(m * n * sizeof(int));

    /*  Initialize table */
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) *(T + i * n + j) = SENTINEL;

    /*  Set up base cases T[i][0] = i */
    for(int i = 0; i < m; i++) *(T + i * n) = i;

    /*  Set up base cases T[0][j] = j */
    for(int j = 0; j < n; j++) *(T + j) = j;

    /*  Build the T in top-down fashion */
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            /*  T[i][j-1] - Deletion */
            leftCell = *(T + i*n + j-1);
            leftCell += EDIT_COST;

            /*  T[i-1][j] - Insertion */
            topCell = *(T + (i-1)*n + j);
            topCell += EDIT_COST;

            /*  Top-left (corner) cell, T[i-1][j-1] */
            cornerCell = *(T + (i-1)*n + (j-1) );

            /*  edit[(i-1), (j-1)] = 0 if X[i] == Y[j], 1 otherwise */
            cornerCell += (X[i-1] != Y[j-1]); /* May be replaced */

            /*  Minimum cost of current cell. Fill in the next cell T[i][j] */
            *(T + (i)*n + (j)) = minimum(leftCell, topCell, cornerCell);
        }
    }

    /* Cost is in the cell T[m][n] */
    cost = *(T + m*n - 1);
    //free(T);
    return cost;
}

int main() {
    char X[] = "SUNDAY"; // vertical
    char Y[] = "SATURDAY"; // horizontal

    printf("Minimum edits: %d\n", editDistance(X, Y));
    return 0;
}
