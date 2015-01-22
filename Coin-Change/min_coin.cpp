#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*  Example: Given S{1,3,4}. Also assume that we have infinite supply of coins for each denomination.
    To make change for 6, we can have three combinations: {1,1,4}, {1,1,1,3}, {3,3}.
    The minimum number of coins to make change for 6 is '2'.

    Input:  3 6
            1 3 4

    Output: 2 */

int getMinCoins(vector<int> &s, int amount) {
	int * counts = new int[ amount + 1 ];
	int coins = 0;
	counts[0] = 0;

	int i, j;
	for(i = 1; i <= amount; i++) {
		coins = INT_MAX;

		for(j = 0; j < s.size(); j++)
            /* Coin value should not exceed the amount itself */
			if(s[j] <= i) coins = min( coins, counts[i-s[j]] );

		if(coins < INT_MAX) counts[i] = coins + 1;
		else counts[i] = INT_MAX;
	}

	coins = counts[amount];
	delete[] counts;
	return coins;
}

int main() {
	int n;      /*  Size of array */
	int amount; /*  Number to reach*/

	cin >> n >> amount;
	vector<int> s(n);

	for(int i = 0; i < n ; i++) cin >> s[i];

	cout << "Minimum number of coins: " << getMinCoins(s, amount) << endl;
	return 0;
}
