#include <bits/stdc++.h>

using namespace std;

int ways = 0;

void solve(vector<int>& coins, int target, vector<int>& dp) {
    if (target == 0) {
        ways++;
        return;
    }
    if (target < 0) return;

    for (int c : coins) {
        solve(coins, target - c, dp);
    }

    return;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, -1);

    solve(coins, x, dp);

    cout << ways << endl;
    return 0;
}