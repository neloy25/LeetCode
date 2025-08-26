#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<bool>> visited;
    int n, m;
    vector<pair<int, int>> dxy = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }

    bool dfs(int si, int sj, vector<vector<int>>& grid1,
             vector<vector<int>>& grid2) {
        visited[si][sj] = true;
        bool is_sub = (grid1[si][sj] == 1); // check current cell

        for (auto [dx, dy] : dxy) {
            int ci = si + dx;
            int cj = sj + dy;

            if (valid(ci, cj) && grid2[ci][cj] && !visited[ci][cj]) {
                if (!dfs(ci, cj, grid1, grid2)) {
                    is_sub = false;
                }
            }
        }
        return is_sub;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        visited.assign(n, vector<bool>(m, false));
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] && !visited[i][j]) {
                    if (dfs(i, j, grid1, grid2))
                        res++;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {1, 1, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 1},
        {1, 0, 1, 1, 1}
    };

    vector<vector<int>> grid2 = {
        {1, 1, 1, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1}
    };

    int count = sol.countSubIslands(grid1, grid2);
    cout << "Number of sub-islands: " << count << endl;

    return 0;
}
