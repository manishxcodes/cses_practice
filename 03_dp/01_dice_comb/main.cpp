#include <bits/stdc++.h>
using namespace std;

// recursive solution
int countWays(int n) {
    if (n == 0 || n == 1) return 1;
    if (n < 0) return 0;

    int total = 0;

    for (int i = 1; i <= 6; i++) {
        total += countWays(n - i);
    }

    return total;
}

// dp
const int mod = 1e9 + 7;

int countWaysDP(int n, vector<int>& dp) {
    if (n == 0 || n == 1) return 1;
    if (n < 0) return 0;

    if (dp[n] != -1) return dp[n];

    int total = 0;

    for (int i = 1; i <= 6; i++) {
        if (n - i >= 0) total += countWaysDP(n - i, dp) % mod;
    }

    return dp[n] = total;
}

int main() {
    int n;
    cin >> n;

    // int ways = countWays(n);
    vector<int> dp(n + 1, -1);
    int ways = countWaysDP(n, dp);

    cout << ways << endl;

    return 0;
}