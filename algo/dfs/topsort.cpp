//
// Created by imd on 10/10/2018.
//

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> mark, out;
vector<int> col;
static vector<vector<int>> edges;
vector<int> ans;
int t = 0;


ifstream fin("topsort.in");
ofstream fout("topsort.out");

void dfs(int v, int color) {
    mark[v] = true;
    col[v] = color;
    t++;
    for (int u : edges[v]) {
        if (!mark[u]) {
            dfs(u, color);
        }else {
            if ((col[u] == color) && (!out[u])) {
                fout << -1;
                exit(0);
            }
        }

    }
    ans.push_back(v + 1);
    out[v] = true;
}

int main() {
    int n, m;
    ifstream fin("topsort.in");
    ofstream fout("topsort.out");
    fin >> n >> m;
    edges = vector<vector<int>>(100000);
    ans = vector<int>();
    col = vector<int>(100000);
    out = vector<bool>(100000);
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        edges[u - 1].push_back(v - 1);
    }
    mark = vector<bool>(100000);
    for (int i = 0; i < n; i++) {
        mark[i] = false;
    }
    int color = 0;
    for (int i = 0; i < n; i++) {
        if (!mark[i]) dfs(i, color++);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) {
        fout << ans[i] << '\n';
    }
    fout.close();
}