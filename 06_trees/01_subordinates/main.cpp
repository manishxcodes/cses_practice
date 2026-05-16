#include <bits/stdc++.h>
using namespace std;

vector<int> sub;
vector<vector<int>> tree;

int dfs(int node) {
    int count = 0;
    for (int v : tree[node]) {
        count += 1 + dfs(v);
    }

    sub[node] = count;
    return count;
}

int main() {
    int n;
    cin >> n;

    tree.resize(n + 1);
    sub.resize(n + 1);

    for (int e = 2; e <= n; e++) {
        int boss;
        cin >> boss;
        tree[boss].push_back(e);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << sub[i] << " ";
    }

    cout << endl;
    return 0;
}