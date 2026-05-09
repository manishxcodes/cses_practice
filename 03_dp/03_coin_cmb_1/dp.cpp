#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int solve(vector<int>& coins, int target, vector<int>& dp) {
    if (target == 0) return 1;
    if (target < 0) return 0;

    if (dp[target] != -1) return dp[target];

    long long ways = 0;
    for (int c : coins) {
        ways += solve(coins, target - c, dp);
        ways %= mod;
    }

    return dp[target] = ways;
}

int main() {
    int n, x;

    cin >> n >> x;

    vector<int> coins(n);
    vector<int> dp(x + 1, -1);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int res = solve(coins, x, dp);

    cout << res << endl;
}