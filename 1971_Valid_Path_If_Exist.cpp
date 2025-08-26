#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n,false);

        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()) {
            int par = q.front();
            q.pop();
            if (par == destination) return true;
            
            for(int child : adj[par]) {
                if(!visited[child]) {
                    q.push(child);
                    visited[child] = true;
                }
            }
        }

        return visited[destination];
    }
};

int main() {
    Solution sol;
    int n = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    int source = 0;
    int destination = 5;

    bool result = sol.validPath(n, edges, source, destination);
    if(result)
        cout << "There is a valid path from " << source << " to " << destination << endl;
    else
        cout << "No valid path exists from " << source << " to " << destination << endl;

    return 0;
}
