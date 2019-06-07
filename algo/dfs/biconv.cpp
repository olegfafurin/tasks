//
// Created by imd on 10/24/2018.
//

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> mark;
vector<int> up, depth, p, col;
static vector<vector<int>> edges, number;
vector<bool> ans;
int d = 0, color = 1;


ifstream fin("biconv.in");
ofstream fout("biconv.out");

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

void dfs2(int v, int parent, int color) {
    mark[v] = true;
    p[v] = parent;
    int local = color;
    if (ans[v]) {
        for (int i = 0; i < edges[v].size(); i++) {
            if (col[number[v][i]] == 0) {
                col[number[v][i]] = color;
            }
            if ((!mark[edges[v][i]]) && (p[v] != edges[v][i])) {
                dfs2(edges[v][i], v, ans[edges[v][i]] ? ++::color : color);
                color = ++::color;
            }
        }
    }
    else {
        for (int i = 0; i < edges[v].size(); i++) {
            if (col[number[v][i]] == 0) {
                col[number[v][i]] = color;
            }
            if ((!mark[edges[v][i]]) && (p[v] != edges[v][i])) {
                dfs2(edges[v][i], v, ans[edges[v][i]] ? ++:: color : color);
            }
        }
    }
}

int main() {
    int n, m;
    ifstream fin("biconv.in");
    ofstream fout("biconv.out");
    fin >> n >> m;
    if (m == 0) {
        fout << '0';
        fout.close();
        exit(0);
    }
    edges = vector<vector<int>>(200000);
    number = vector<vector<int>>(200000);
    depth = vector<int>(20000);
    p = vector<int>(20000);
    ans = vector<bool>(20000);
    mark = vector<bool>(20000);
    up = vector<int>(20000);
    col = vector<int>(200000);
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

    for (int i = 0; i < n; i++) {
        mark[i] = false;
        p[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (!mark[i]) dfs2(i, -1, color);
    }
    int cur = 20000;
    int num = 0;
    for (int i = 1; i <= m; i++) {
        cur = min(cur, col[i]);
        num = max(num, col[i]);
    }
    for (int i = 1; i <= m; i++) {
        col[i] -= (cur - 1);
    }
    fout << (num - cur + 1) <<'\n';
    for (int i = 1; i <= m; i++) {
        fout << col[i] << ' ';
    }


}