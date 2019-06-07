//
// Created by imd on 10/16/2018.
//

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> edges, downedges;
int t = 0;
vector<bool> mark;
vector<int> out, ans;

ifstream fin("cond.in");
ofstream fout("cond.out");

void dfs_up(int v) {
    mark[v] = true;
    for (int u : edges[v]) {
        if (!mark[u]) {
            dfs_up(u);
        }
    }
    out.push_back(v);
}

void dfs_down(int v, int color) {
    mark[v] = true;
    ans[v] = color;
    for (int u : downedges[v]) {
        if (!mark[u]) {
            dfs_down(u, color);
        }
    }
}


int main() {
    int n, m;
    ifstream fin("cond.in");
    ofstream fout("cond.out");
    fin >> n >> m;
    edges = vector<vector<int>>(200000);
    downedges = vector<vector<int>>(200000);
    mark = vector<bool>(20000);
    out = vector<int>();
    ans = vector<int>(20000);
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        if (u != v) {
            edges[u - 1].push_back(v - 1);
            downedges[v - 1].push_back(u - 1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!mark[i]) dfs_up(i);
    }
    for (int i = 0; i < n; i++) {
        mark[i] = false;
    }
    int col = 0;
    t = n - 1;
    while (t >= 0) {
        dfs_down(out[t--], ++col);
        while ((t >= 0) && (mark[out[t]])) t--;
    }
    fout << col << "\n";
    for (int i = 0; i < n; i++) {
        fout << ans[i] << " ";
    }
}