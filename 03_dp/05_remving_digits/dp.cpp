#include <bits/stdc++.h>

using namespace std;

vector<int> dp;

int solve(int num) {
    if (num == 0) return 0;
    if (dp[num] != -1) return dp[num];

    int res = INT_MAX;
    int temp = num;

    while (temp > 0) {
        int digit = temp % 10;
        if (digit > 0) {
            res = min(res, 1 + solve(num - digit));
        }
        temp = temp / 10;
    }

    return dp[num] = res;
}

int main() {
    int n;
    cin >> n;

    dp.resize(n + 1, -1);
    cout << solve(n);

    return 0;
}