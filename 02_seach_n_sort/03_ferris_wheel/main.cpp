#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];

    sort(weights.begin(), weights.end());

    int i = 0, j = n - 1;
    int ans = 0;
    while (i <= j) {
        if (weights[i] + weights[j] <= x) {
            i++;
            j--;
            ans++;
        } else {
            j--;
            ans++;
        }
    }

    // tst again

    cout << ans;
    return 0;
}

// 2 3 7 9

// 5 9 6 5 8 9 10 6 5 6

// 5 5 5 6 6 6 8 9 9 10