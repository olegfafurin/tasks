#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector adj(n, vector<pair<int, long long>>());
    long long mstWeight = 0;

    for (int i = 0; i < m; ++i) {
        int u,v;
        long long w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
        adj[v - 1].push_back({u - 1, w});
    }

    vector<int> min_e(n, INT_MAX);
    vector<int> p(n, -1);
    min_e[0] = 0;

    
    set<pair<long long, int>> q; // min_e, v
    vector<bool> processed(n, false);
    vector<pair<int,int>> mst;

    q.insert({0ll, 0});
    for (int t = 0; t < n; ++t) {
        auto [w, v] = *q.begin(); // ?
        q.erase(q.begin());
        mstWeight += w;
        processed[v] = true;
        for (auto [u, edgeWeight]: adj[v]) {
            if (!processed[u] && min_e[u] > edgeWeight) {
                q.erase({min_e[u], u});
                min_e[u] = edgeWeight;
                p[u] = v;
                q.insert({min_e[u], u});
            }
        }
    }

    cout << mstWeight << '\n';
}
