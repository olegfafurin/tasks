//
// Created by imd on 10/24/2018.
//

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> mark, out;
vector<int> up, depth, p;
static vector<vector<int>> edges, number;
vector<bool> ans;
int d = 0;


ifstream fin("points.in");
ofstream fout("points.out");

void dfs(int v) {
    mark[v] = true;
    depth[v] = d;
    up[v] = d++;
    int child = 0;
    for (int u : edges[v]) {
        if (!mark[u]) {
            p[u] = v;
            dfs(u);
            child++;
            up[v] = min(up[v], up[u]);
            if ((up[u] >= depth[v]) && (p[v] != -1)) {
                ans[v] = true;
            }
        } else if (u != p[v]) {
            up[v] = min(up[v], depth[u]);
        }
    }
    if ((p[v] == -1) && (child > 1)) {
        ans[v] = true;
    }
    d--;
}

int main() {
    int n, m;
    ifstream fin("points.in");
    ofstream fout("points.out");
    fin >> n >> m;
    edges = vector<vector<int>>(200000);
    number = vector<vector<int>>(200000);
    depth = vector<int>(20000);
    p = vector<int>(20000);
    ans = vector<bool>(20000);
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
    fout << count(ans.begin(), ans.end(), true) << '\n';
    for (int i = 0; i < n; i++) {
        if (ans[i]) fout << i + 1 << '\n';
    }

}
