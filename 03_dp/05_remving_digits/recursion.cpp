#include <bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

void solve(int num, int count) {
    if (num == 0) {
        ans = min(count, ans);
        return;
    }

    if (num < 0) return;

    int temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        solve(num - digit, count + 1);
        temp /= 10;
    }
}

int main() {
    int n;
    cin >> n;

    solve(n, 0);

    cout << ans;

    return 0;
}