#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    res += 4;
                    if (i > 0 && grid[i - 1][j])
                        res -= 2;
                    if (j > 0 && grid[i][j - 1])
                        res -= 2;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    int perimeter = sol.islandPerimeter(grid);
    cout << "The perimeter of the island is: " << perimeter << endl;

    return 0;
}
