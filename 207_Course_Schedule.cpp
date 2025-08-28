#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> adj;
    vector<bool> path;
    vector<bool> visited;
    bool cycle;

    void dfs(int src) {
        visited[src] = true;
        path[src] = true;
        for (int child : adj[src]) {
            if (visited[child] && path[child])
                cycle = true;
            if (!visited[child]) {
                dfs(child);
            }
        }
        path[src] = false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        adj.assign(numCourses, {});
        path.assign(numCourses, false);
        visited.assign(numCourses, false);

        for (int i = 0; i < n; i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a); // b → a (must take b before a)
        }

        cycle = false;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return !cycle;
    }
};

int main() {
    Solution sol;
    
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}}; 
    // means: take 1 after 0 → possible

    if (sol.canFinish(numCourses, prerequisites))
        cout << "You can finish all courses" << endl;
    else
        cout << "Cannot finish all courses" << endl;

    return 0;
}
