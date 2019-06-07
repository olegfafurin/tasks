//
// Created by imd on 10/11/2018.
//

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> edges;
vector<bool> out;
vector<int> col;

ifstream fin("bipartite.in");
ofstream fout("bipartite.out");

void dfs(int v, int color) {
    col[v] = color;
    for (int u : edges[v]) {
        if (!col[u]) {
            dfs(u, 3 - color);
        } else if ((col[u] == col[v]) && (!out[u])) {
            fout << "NO\n";
            fout.close();
            exit(0);
        }
    }
    out[v] = true;
}


int main() {
    int n, m;
    ifstream fin("bipartite.in");
    ofstream fout("bipartite.out");
    fin >> n >> m;
    edges = vector<vector<int>>(100000);
    out = vector<bool>(100000);
    col = vector<int>(100000);
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        edges[u - 1].push_back(v - 1);
        edges[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < n; i++) {
        if (!(col[i])) dfs(i, 1);
    }
    fout << "YES";
}
