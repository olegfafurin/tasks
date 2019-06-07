//
// Created by imd on 10/11/2018.
//

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> mark;
vector<int> col;
static vector<vector<int>> edges;
vector<int> ans;
int t = 0;


ifstream fin("hamiltonian.in");
ofstream fout("hamiltonian.out");

void dfs(int v, int color) {
    mark[v] = true;
    col[v] = color;
    t++;
    for (int u : edges[v]) {
        if (!mark[u]) {
            dfs(u, color);
        }
    }
    ans.push_back(v);
}

int main() {
    int n, m;
    ifstream fin("hamiltonian.in");
    ofstream fout("hamiltonian.out");
    fin >> n >> m;
    if (n == 1) {
        fout << "YES";
        fout.close();
        exit(0);
    }
    edges = vector<vector<int>>(100000);
    ans = vector<int>();
    col = vector<int>(100000);
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
    for (int i = 0; i < n-1; i++) {
        int v = ans[i];
        bool flag = false;
        for (int u : edges[v]) {
            if (u == ans[i+1]) flag = true;
        }
        if (!flag) {
            fout << "NO";
            fout.close();
            exit(0);
        }
    }
    fout << "YES";
    fout.close();
}