#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& coins, int target, vector<int>& dp) {
    if (target == 0) return 0;
    if (target < 0) return 1e9;

    if (dp[target] != -1) return dp[target];

    int ans = 1e9;
    for (int c : coins) {
        ans = min(ans, 1 + solve(coins, target - c, dp));
    }

    return dp[target] = ans;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, -1);
    int res = solve(coins, x, dp);

    if (res >= 1e9)
        cout << -1 << endl;
    else
        cout << res << endl;

    return 0;
}