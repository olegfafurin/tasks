#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;


void bfs(int v, const vector<vector<int>> &adj, vector<bool> &visited) {
    visited[v] = true;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (const auto& neighbor : adj[v]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}


bool graphComp() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n);
    unordered_set<int> startSet;
    for (int i = 0; i < k; ++i) {
        int v;
        cin >> v;
        startSet.insert(v - 1);
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<bool> visited(n, false);
    for (const auto &v: startSet) {
        if (!visited[v]) {
            bfs(v, adj, visited);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!startSet.contains(i) && visited[i]) {
            return false;
        }
    }
    return true;    
}



int main() {
    int t;
    cin >> t;
    for (int tn = 0; tn < t; ++tn) {
        cout << (graphComp() ? "YES\n" : "NO\n");
    }
}
