#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;

int solve(int i, vector<int>& prices, vector<int>& pages, int x) {
    if (i >= prices.size() || x == 0) return 0;
    if (dp[i][x] != -1) return dp[i][x];

    int take = 0, skip = 0;
    if (prices[i] <= x) {
        take = pages[i] + solve(i + 1, prices, pages, x - prices[i]);
    }
    skip = solve(i + 1, prices, pages, x);

    return dp[i][x] = max(take, skip);
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> prices(n);
    vector<int> pages(n);

    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    dp.resize(n + 1, vector<int>(x + 1, -1));

    cout << solve(0, prices, pages, x);

    return 0;
}