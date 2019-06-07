//
// Created by imd on 10/10/2018.
//

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> edges;
vector<int> ans, p;
vector<bool> out;
int t = 0;
vector<int> col;

ifstream fin("cycle.in");
ofstream fout("cycle.out");

void dfs(int v, int color) {
    col[v] = color;
    t++;

    for (int u : edges[v]) {
        if (!col[u]) {
            p[u] = v;
            dfs(u, color);
        }
        else if ((col[u] == col[v]) && (!out[u])) {
            int begin = u;
            fout << "YES\n";
            while ((v != u) && (p[v] != -1)) {
                fout << v + 1 << ' ';
                v = p[v];
            }
            fout << v + 1;
            exit(0);
        }
    }
    out[v] = true;
}


int main() {
    int n, m;
    ifstream fin("cycle.in");
    ofstream fout("cycle.out");
    fin >> n >> m;
    edges = vector<vector<int>>(100000);
    ans = vector<int>();
    out = vector<bool>(100000);
    p = vector<int>(100000);
    col = vector<int>(100000);
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        edges[v - 1].push_back(u - 1);
        if (u == v) {
            fout << "YES\n"  << v;
            exit(0);
        }
    }

    int color = 0;
    for (int i = 0; i < n; i++) {
        if (!(col[i])) {
            p[i] = -1;
            dfs(i, ++color);
        }
    }
    fout << "NO";
}