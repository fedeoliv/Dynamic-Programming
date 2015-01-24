#include <stdio.h>
#include <algorithm>
#define MAXK 2000001
#define MAXN 501
using namespace std;

int arr[2][MAXK]={0};

struct node {
    int v;  /* Value of the bag */
    int w;  /* Weight of the bag */
} obj[MAXN];

int knapSack(int W, int n) {
    for(int i = 1; i <= n; i++) {
        if(i % 2) {
            for(int j = 1; j <= W; j++) {
                if(obj[i].w <= j)
                    arr[1][j] = max(obj[i].v + arr[0][j-obj[i].w] , arr[0][j]);
                else arr[1][j] = arr[0][j];
            }
        } else {
            for(int j = 1; j <= W; j++) {
                if(obj[i].w <= j)
                    arr[0][j] = max(obj[i].v + arr[1][j-obj[i].w], arr[1][j]);
                else arr[0][j] = arr[1][j];
            }
        }
    }

    if(n&1) return arr[1][W];
    else return arr[0][W];
}

int main() {
    int k;          /* Maximum weight */
    int m;          /* Amount of bags */
    scanf("%d %d", &k, &m);

    for(int i = 1; i <= m; i++) scanf("%d %d", &obj[i].v, &obj[i].w);

    printf("%d\n", knapSack(k, m));
    return 0;
}
