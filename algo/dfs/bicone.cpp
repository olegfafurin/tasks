//
// Created by imd on 10/24/2018.
//

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> mark;
vector<int> up, depth, p;
static vector<vector<int>> edges, number;
vector<bool> is_bridge;
vector<int> ans;
int d = 0, color = 0;


ifstream fin("bicone.in");
ofstream fout("bicone.out");

void dfs(int v) {
    mark[v] = true;
    depth[v] = d;
    up[v] = d++;
    for (int i = 0; i < edges[v].size(); i++) {
        int u = edges[v][i];
        if (!mark[u]) {
            p[u] = number[v][i];
            dfs(u);
            up[v] = min(up[v], up[u]);
        } else if (number[v][i] != p[v]) {
            up[v] = min(up[v], depth[u]);
        }
    }
    if ((up[v] >= depth[v]) && (p[v] != -1)) {
        is_bridge[p[v]] = true;
    }
    d--;
}

void dfs2(int v) {
    mark[v] = true;
    ans[v] = color;
    for (int i = 0; i < edges[v].size(); i++) {
        int u = edges[v][i];
        if (!mark[u] && (!is_bridge[number[v][i]])) dfs2(u);
    }
}

int main() {
    int n, m;
    ifstream fin("bicone.in");
    ofstream fout("bicone.out");
    fin >> n >> m;
    edges = vector<vector<int>>(200000);
    number = vector<vector<int>>(200000);
    depth = vector<int>(20000);
    p = vector<int>(20000);
    is_bridge = vector<bool>(200000);
    ans = vector<int>(20000);
    mark = vector<bool>(20000);
    up = vector<int>(20000);
    color = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        if (u != v) {
            edges[u - 1].push_back(v - 1);
            edges[v - 1].push_back(u - 1);
            number[u - 1].push_back(i + 1);
            number[v - 1].push_back(i + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!mark[i]) {
            p[i] = -1;
            dfs(i);
        }
    }

    for (int i = 0; i < n; i++) mark[i] = false;

    for (int i = 0; i < n; i++) {
        if (!mark[i]) {
            ++color;
            dfs2(i);
        }
    }
    fout << color << '\n';
    for (int i = 0; i < n; i++) fout << ans[i] << ' ';
}