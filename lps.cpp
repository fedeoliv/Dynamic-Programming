#include <iostream>
using namespace std;

/*  Given a sequence, find the length of the longest palindromic subsequence in it.

    For example, if the given sequence is "BBABCBCAB", then the output should be 7 as "BABCBAB"
    is the longest palindromic subsequence in it. "BBBBB" and "BBCBB" are also palindromic
    subsequences of the given sequence, but not the longest ones.*/

/*  Using longest common subsequence in a reversed string. */
int lcs(string x, string y, int m, int n) {
    int ans[m+1][n+1];

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) ans[i][j] = 0;
            else if (x[i-1] == y[j-1])
                ans[i][j] = 1 + ans[i-1][j-1];
            else ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
        }
    }

    return ans[m][n];
}

/*  Function that will reverse the string and use LCS.*/
int palindrome(string x, int n) {
    string y;
    int index = 0;

    for(int i = n-1; i >= 0; i--) y.push_back(x[i]);
    return lcs(x, y, n, n);
}

int main() {
    string s = "BBABCBCAB";
    cout << palindrome(s, s.length()) << endl;
    return 0;
}
