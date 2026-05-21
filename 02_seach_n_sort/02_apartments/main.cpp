#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired(n);
    vector<int> apartments(m);
    int res = 0;

    for (int i = 0; i < n; i++) {
        cin >> desired[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> apartments[i];
    }

    for (auto d : desired) {
        for (int i = 0; i < m; i++) {
            if (apartments[i] >= (d - k) && apartments[i] <= (d + k) &&
                apartments[i] != 0) {
                res = res + 1;
                apartments[i] = 0;
                break;
            }
        }
    }

    cout << res;

    return 0;
}