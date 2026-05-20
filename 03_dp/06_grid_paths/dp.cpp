#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
const int MOD = 1e9 + 7;

int solve(int i, int j, vector<vector<char>>& grid) {
    if (i < 0 || j < 0) return 0;
    if (grid[i][j] == '*') return 0;

    if (i == 0 && j == 0) return 1;

    if (dp[i][j] != -1) return dp[i][j];

    int left = solve(i - 1, j, grid);
    int up = solve(i, j - 1, grid);

    return dp[i][j] = (up + left) % MOD;
}

int main() {
    int n;
    cin >> n;

    dp.resize(n, vector<int>(n, -1));
    vector<vector<char>> grid(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << solve(n - 1, n - 1, grid);

    return 0;
}
