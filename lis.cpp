#include <stdio.h>
#include <vector>
using namespace std;

/*  The longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence
    of a given sequence such that all elements of the subsequence are sorted in increasing order.

    For example, length of LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6
    and LIS is {10, 22, 33, 50, 60, 80}.*/

void print(vector<vector<int> > v, int start, int end) {
    for(int i = 0; i < end; i++) printf("%d ", v[start][i]);
    printf("\n");
}

int LIS(int a[], int n) {
    int ans[n], index;
    vector<vector<int> > temp;
    vector<int> v;

    v.push_back(0);
    temp.push_back(v);
    v.clear();

    int val = 0;
    for(int i = 0; i < n; i++) ans[i] = 1;

    for(int i = 1; i < n; i++) {
        v.clear();
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j] && ans[i] < ans[j] + 1) {
                ans[i] = ans[j] + 1;
                v.push_back(a[j]);
            }
        }

        v.push_back(a[i]);
        temp.push_back(v);
    }

    for(int i = 0; i < n; i++)
        if (val < ans[i]) {
            val = ans[i];
            index = i;
        }

    print(temp, index, val);
    return val;
}

int main() {
    int a[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(a) / sizeof(a[0]);

    printf("%d\n", LIS(a, n));

    return 0;
}
