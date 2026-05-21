#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired(n), apartments(m);
    for (int i = 0; i < n; i++) cin >> desired[i];
    for (int j = 0; j < m; j++) cin >> apartments[j];

    sort(desired.begin(), desired.end());
    sort(apartments.begin(), apartments.end());

    int i = 0, j = 0, res = 0;

    while (i < n && j < m) {
        if (apartments[j] < desired[i] - k) {
            j++;
        } else if (apartments[j] > desired[i] + k) {
            i++;
        } else {
            i++;
            j++;
            res++;
        }
    }

    cout << res;

    return 0;
}