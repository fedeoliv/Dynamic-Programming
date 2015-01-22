#include<stdio.h>
#include<limits.h>

/*  Given a sequence of matrices, find the most efficient way to multiply these matrices together.
    We should return the minimum number of multiplications needed to multiply the chain.

    For example, suppose A is a 10x30 matrix, B is a 30x5 matrix, and C is a 5x60 matrix. Then:
    (AB)C = (10*30*5) + (10*5*60) = 1500 + 3000 = 4500 operations
    A(BC) = (30*5*60) + (10*30*60) = 9000 + 18000 = 27000 operations.

    Input: p[] = {40, 20, 30, 10, 30}
    Output: 26000

    There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30. Let the input 4 matrices
    be A, B, C and D. The minimum number of multiplications are obtained by putting parenthesis
    in following way: (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30. */


int matrixChain(int p[], int n) {

    /* For simplicity of the program, one extra row and one extra column are
       allocated in m[][].  0th row and 0th column of m[][] are not used */
    int m[n][n];
    int j, k, L, q;

    /* m[i,j] = Minimum number of scalar multiplications needed to compute
       the matrix A[i]A[i+1]...A[j] = A[i..j] where dimention of A[i] is p[i-1] x p[i] */

    /* Cost is zero when multiplying one matrix. */
    for(int i = 1; i < n; i++) m[i][i] = 0;

    /* L is chain length. */
    for(L = 2; L < n; L++) {
        for(int i = 1; i <= n-L+1; i++) {
            j = i+L-1;
            m[i][j] = INT_MAX;

            for(k = i; k <= j-1; k++) {
                /* q = cost/scalar multiplications */
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]) m[i][j] = q;
            }
        }
    }

    return m[1][n-1];
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("%d\n", matrixChain(arr, size));
    return 0;
}
