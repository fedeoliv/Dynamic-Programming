#include <stdio.h>
#define KMAX 10
//int c[MAXN] = {2, 3, 5, 7, 1, 4, 1}; /* WEIGHT c[i] is the *COST* of the ith object; i.e. what
                //YOU PAY to take the object */
//int v[MAXN] = {10, 5, 15, 7, 6, 18, 3}; /* VALUEv[i] is the *VALUE* of the ith object; i.e.
                //what YOU GET for taking the object */
//int W = 15; /* The maximum weight you can take */


float knapSack(int W, int wt[], int val[], int n) {
    int cur_w;
    float tot_v;
    int i, maxi;
    int used[10];

    for(i = 0; i < n; ++i) used[i] = 0; /* I have not used the i-th object yet */
    cur_w = W;

    while(cur_w > 0) {  /* while there's still room */
        /* Find the best object */
        maxi = -1;
        for(i = 0; i < n; ++i)
            if(used[i] == 0 && (maxi == -1 || (float) val[i]/wt[i] > (float) val[maxi]/wt[maxi]))
                maxi = i;

        used[maxi] = 1;     /* mark the maxi-th object as used */
        cur_w -= wt[maxi];  /* with the object in the bag, I can carry less */
        tot_v += val[maxi];

        /*if(cur_w >= 0)
            printf("Added object %d (%d$, %dKg) completly in the bag. Space left: %d.\n", maxi + 1, val[maxi], wt[maxi], cur_w);
        */
        if(cur_w < 0) {
            printf("Added %d%% (%d$, %dKg) of object %d in the bag.\n", (int)((1 + (float)cur_w/wt[maxi]) * 100), val[maxi], wt[maxi], maxi + 1);
            tot_v -= val[maxi];
            tot_v += (1 + (float)cur_w/wt[maxi]) * val[maxi];
        }
    }

   return tot_v;
}

int main(int argc, char *argv[]) {
    int k;          /* Maximum weight */
    int m;          /* Amount of bags */
    int val[KMAX];  /* Value of the bag */
    int w[KMAX];    /* Weight of the bag */

    scanf("%d %d", &k, &m);
    for(int i = 0; i < m; i++) scanf("%d %d", &w[i], &val[i]);

    printf("%.2f\n", knapSack(k, w, val, m));

    return 0;
}
