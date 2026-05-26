#include <iostream>
#include <vector>
#include <utility>
#include <array>
#include <algorithm>

using namespace std;


class DSU {

vector<int> p;
vector<int> rank;

public:

    DSU(int n): p(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }

    int get(int v) {
        if (p[v] != v) {
            p[v] = get(p[v]);
        }
        return p[v];
    }

    int merge(int u, int v) {
        int rootU = get(u);
        int rootV = get(v);
        if (rootU == rootV) {
            return rootU;
        }
        if (rank[rootV] < rank[rootU]) {
            swap(rootU, rootV);
        }
        p[rootU] = rootV;
        rank[rootV] += rank[rootU];
        return rootV;
    }
};


int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<array<int, 3>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u - 1, v - 1, 1 - w});
    }

    DSU dsu = DSU(n);

    sort(edges.begin(), edges.end(), [] (const auto &lhs, const auto &rhs) {
        return lhs[2] < rhs[2];
    });

    int minCost = 0;
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        const auto &e = edges[i];
        if (dsu.get(e[0]) != dsu.get(e[1])) {
            dsu.merge(e[0], e[1]);
            ++cnt;
            minCost += e[2];
        }
        if (cnt == n - 1) {
            break;
        }
    }

    dsu = DSU(n);

    int maxCost = 0;
    cnt = 0;
    for (int i = m - 1; i >= 0; --i) {
        const auto &e = edges[i];
        if (dsu.get(e[0]) != dsu.get(e[1])) {
            dsu.merge(e[0], e[1]);
            ++cnt;
            maxCost += e[2];
        }
        if (cnt == n - 1) {
            break;
        }
    }

    for (int i = 0; i < q; ++i) {
        int query;
        cin >> query;
        cout << (cnt == n - 1 && query <= maxCost && query >= minCost ? "YES\n" : "NO\n");
    }
}
