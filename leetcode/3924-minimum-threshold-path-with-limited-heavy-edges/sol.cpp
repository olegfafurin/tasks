#include <vector>
#include <utility>
#include <functional>
#include <queue>
#include <iostream>

using namespace std;


int pathCost(int n, vector<vector<pair<int, int>>>& adj, int source, int target, int threshold) {
    vector<int> d(n, 10'000);
    d[source] = 0;
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
    q.push({0, source});
    while (!q.empty()) {
        auto [dist, u] = q.top();
        q.pop();
        if (d[u] < dist) {
            continue;
        }
        if (u == target) {
            return d[target];
        }
        for (auto [v, w]: adj[u]) {
            int weight = w > threshold ? 1 : 0;
            if (d[v] > d[u] + weight) {
                d[v] = d[u] + weight;
                q.push({d[v], v});
            }
        }
    }
    return d[target];
}

int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
    vector adj(n, vector<pair<int,int>>());
    for (auto &e: edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int l = -1;
    int r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l + 1) / 2;
        int cost = pathCost(n, adj, source, target, m);
        if (cost == 10'000) {
            return -1;
        } else if (cost > k) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}


int main() {
    const int n = 2;
    vector<vector<int>> edges = {{0,1,2}};
    cout << minimumThreshold(n, edges, 0, 1, 0) << '\n';
}
