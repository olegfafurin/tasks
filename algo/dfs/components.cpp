//
// Created by imd on 10/11/2018.
//

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> edges;
vector<int> ans;
int t = 0;
vector<int> col;

ifstream fin("components.in");
ofstream fout("components.out");

void dfs(int v, int color) {
    col[v] = color;
    for (int u : edges[v]) {
        if (!col[u]) {
            dfs(u, color);
        }
    }
}


int main() {
    int n, m;
    ifstream fin("components.in");
    ofstream fout("components.out");
    fin >> n >> m;
    edges = vector<vector<int>>(200000);
    ans = vector<int>();
    col = vector<int>(100000);
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        if (u != v) {
            edges[u - 1].push_back(v - 1);
            edges[v - 1].push_back(u - 1);
        }
    }

    int color = 0;
    for (int i = 0; i < n; i++) {
        if (!(col[i])) {
            dfs(i, ++color);
        }
    }
    fout << color<< "\n";
    for (int i = 0; i < n; i++) {
        fout << col[i] << ' ';
    }
}