#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int c : coins) {
        for (int sum = 0; sum <= x; sum++) {
            if (sum >= c) {
                dp[sum] = (dp[sum] + dp[sum - c]) % mod;
            }
        }
    }

    cout << dp[x];

    return 0;
}