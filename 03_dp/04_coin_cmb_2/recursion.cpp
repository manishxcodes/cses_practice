#include <bits/stdc++.h>

using namespace std;

int ways = 0;

void solve(int i, vector<int>& coins, int target) {
    if (target == 0) {
        ways++;
        return;
    };
    if (i == coins.size() || target < 0) return;

    solve(i + 1, coins, target);

    solve(i, coins, target - coins[i]);
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    solve(0, coins, x);

    cout << ways;

    return 0;
}