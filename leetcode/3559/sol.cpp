#include <vector>
#include <cmath>
#include <iostream>


using namespace std;


int lca(int u, int v, int logn, const vector<int>& d, const vector<vector<int>>& p) {
    int du = d[u];
    int dv = d[v];
    if (du > dv) {
        swap(u, v);
        swap(du, dv);
    }
    int diff = dv - du;
    int ord = 0;
    while (diff > 0) {
        if (diff & 1) {
            v = p[ord][v];
        }
        ++ord;
        diff >>= 1;
    }
    if (v == u) {
        return u;
    }
    for (int i = logn; i >= 0; --i) {
        if (p[i][u] != p[i][v]) {
            u = p[i][u];
            v = p[i][v];
        }
    }
    return p[0][u];
}

vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
    const int n = edges.size() + 1;
    const int mod = 1e9 + 7;
    vector adj(n, vector<int>());
    int logn = static_cast<int>(ceil(log2(n)));
    vector<int> pow2(n, 1);
    vector p(logn + 1, vector<int>(n, 0));
    vector<int> d(n, -1);
    for (int i = 1; i < n; ++i) {
        pow2[i] = pow2[i - 1] * 2 % mod;
    }
    for (const auto& e: edges) {
        int u = e[0] - 1;
        int v = e[1] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto dfs = [&] (this auto dfs, int v) -> void {
        for (auto u: adj[v]) {
            if (d[u] == -1) {
                d[u] = d[v] + 1;
                p[0][u] = v;
                dfs(u);
            }
        }
    };
    d[0] = 0;
    dfs(0);
    for (int level = 1; level <= logn; ++level) {
        for (int i = 0; i < n; ++i) {
            p[level][i] = p[level - 1][p[level - 1][i]];
        }
    }
    vector<int> ans;
    for (const auto& q: queries) {
        int u = q[0] - 1;
        int v = q[1] - 1;
        int a = lca(u, v, logn, d, p);
        ans.push_back(u == v ? 0 : pow2[d[u] + d[v] - 2 * d[a] - 1]);
    }
    return ans;
}



int main() {
    vector<vector<int>> edges = {{1,2},{2,3},{2,4},{5,1},{6,1},{7,8},{8,6}};
    vector<vector<int>> queries = {{1,1}, {1,2}, {3,5},{3,3},{4,4},{5,6},{8,8},{8,6},{8,3},{7,3},{3,7},{1,7},{7,4},{6,7},{6,8},{6,3},{6,4},{5,4}};

    auto ans = assignEdgeWeights(edges, queries);
    for (auto x: ans) {
        cout << x << ' ';
    }
    cout << '\n';
}



