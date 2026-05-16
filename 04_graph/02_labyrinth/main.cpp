#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
    if (grid[i][j] == 'B') return true;

    grid[i][j] = '#';  // mark visited

    for (auto& dir : directions) {
        int r = i + dir[0];
        int c = j + dir[1];

        if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != '#') {
            if (dfs(grid, r, c, n, m)) return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    bool hasReached = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                hasReached = dfs(grid, i, j, n, m);
            }
        }
    }

    cout << (hasReached ? "YES" : "NO");
}
