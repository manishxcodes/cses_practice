#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> weight(n);
    vector<int> val(n);

    for (int i = 0; i < n; i++) cin >> weight[i];
    for (int i = 0; i < n; i++) cin >> val[i];

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    // dp[i][j] = max value that can be attached from first i element
    // such that j weight is allowed to be used

    // base case
    // dp[0][k] = 0 for every k because we cannot add any more valu
    //            if 0 elements are left

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            int take = (weight[i - 1] <= j)
                           ? val[i - 1] + dp[i - 1][j - weight[i - 1]]
                           : 0;
            int skip = dp[i - 1][j];

            dp[i][j] = max(skip, take);
        }
    }

    cout << dp[n][x];

    return 0;
}