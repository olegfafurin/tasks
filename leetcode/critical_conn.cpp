//
// Created by imd on 10/8/2019.
//

#include <vector>
#include <iostream>

using namespace std;

vector<bool> mark;
vector<vector<int>> bridges;
vector<vector<int>> e;
vector<int> p, level, uplevel;

void dfs(int v, int newLevel) {
    mark[v] = true;
    level[v] = newLevel;
    uplevel[v] = newLevel;
    for (auto u: e[v]) {
        if (p[v] != u) {
            if (!mark[u]) {
                p[u] = v;
                dfs(u, newLevel + 1);
                uplevel[v] = min(uplevel[v], uplevel[u]);
            } else uplevel[v] = min(uplevel[v], level[u]);
        }
    }
    uplevel[v] = uplevel[v];
    if (uplevel[v] == level[v] && p[v] != -1) bridges.emplace_back(vector<int>({v, p[v]}));
}


vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
    e = vector<vector<int>>(n, vector<int>());
    for (auto edge: connections) {
        e[edge[0]].emplace_back(edge[1]);
        e[edge[1]].emplace_back(edge[0]);
    }
    mark = vector<bool>(n, false);
    level = vector<int>(n);
    uplevel = vector<int>(n);
    bridges = vector<vector<int>>();
    p = vector<int>(n, -1);
    for (int i = 0; i < n; ++i)
        if (!mark[i]) {
            p[i] = -1;
            dfs(i, 0);
        }
    return bridges;
}

int main() {
    int a, b, n, m;
    cin >> n >> m;
    vector<vector<int>> conn = vector<vector<int>>();
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        conn.emplace_back(vector<int>({a, b}));
    }
    for (auto u: criticalConnections(n, conn)) {
        cout << u[0] << ' ' << u[1] << '\n';
    }
}