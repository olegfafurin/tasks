//
// Created by imd on 10/17/2018.
//
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> mark, out;
vector<int> up, depth, p;
static vector<vector<int>> edges, number;
vector<int> ans;
int d = 0;


ifstream fin("bridges.in");
ofstream fout("bridges.out");

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
        }
        else if (number[v][i] != p[v]) {
            up[v] = min(up[v], depth[u]);
        }
    }
    if ((up[v] >= depth[v]) && (p[v] != -1)){
        ans.push_back(p[v]);
    }
    d--;
}

int main() {
    int n, m;
    ifstream fin("bridges.in");
    ofstream fout("bridges.out");
    fin >> n >> m;
    edges = vector<vector<int>>(200000);
    number = vector<vector<int>>(200000);
    depth = vector<int>(20000);
    p = vector<int>(20000);
    ans = vector<int>();
    mark = vector<bool>(20000);
    up = vector<int>(20000);
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
    fout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int bridge : ans) {
        fout << bridge << ' ';
    }

}
