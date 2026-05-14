#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
    for (auto& dir : directions) {
        int r = i + dir[0];
        int c = j + dir[1];

        if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '.') {
            grid[r][c] = '#';
            dfs(grid, r, c, n, m);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                grid[i][j] = '#';
                dfs(grid, i, j, n, m);
                count++;
            }
        }
    }

    cout << count;

    return 0;
}