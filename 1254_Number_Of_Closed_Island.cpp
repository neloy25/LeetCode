#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<bool>> visited;
    vector<pair<int,int>> dxy = {{-1,0},{1,0},{0,-1},{0,1}};
    int n, m;

    bool valid(int i, int j) { return (i >= 0 && i < n && j >= 0 && j < m); }

    bool dfs(int i, int j, vector<vector<int>>& grid) {
        visited[i][j] = true;
        bool isClosed = true;

        for (auto [dx, dy] : dxy) {
            int ci = i + dx;
            int cj = j + dy;

            if (!valid(ci, cj)) {
                isClosed = false;
            } else if (grid[ci][cj] == 0 && !visited[ci][cj]) {
                if(!dfs(ci, cj, grid)) isClosed = false;
            }
        }

        return isClosed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        visited.assign(n, vector<bool>(m, false));
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 0) {
                    if (dfs(i, j, grid)) res++;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1,1,1,1,0,1,1,1},
        {1,0,0,1,0,1,0,1},
        {1,0,1,1,0,1,0,1},
        {1,0,1,1,1,1,0,1},
        {1,1,1,1,1,1,1,1}
    };

    int count = sol.closedIsland(grid);
    cout << "Number of closed islands: " << count << endl;

    return 0;
}
