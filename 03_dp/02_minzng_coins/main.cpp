#include <bits/stdc++.h>
using namespace std;

int minCoins = INT_MAX;

void backtrack(vector<int>& coins, int target, int sum, int count) {
    if (sum == target) {
        minCoins = min(minCoins, count);
        return;
    }

    if (sum > target) return;

    for (int c : coins) backtrack(coins, target, sum + c, count + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    backtrack(coins, x, 0, 0);

    cout << (minCoins == INT_MAX) ? -1 : minCoins;

    return 0;
}