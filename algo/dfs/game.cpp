//
// Created by imd on 10/16/2018.
//

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> edges;
int t = 0;
vector<bool> ans, mark;

ifstream fin("components.in");
ofstream fout("components.out");

void dfs(int v) {
    mark[v] = true;
    for (int u : edges[v]) {
        if (!mark[u]) {
            dfs(u);
        }
        ans[v] = ans[v] || !ans[u];
    }
}


int main() {
    int n, m, s;
    ifstream fin("game.in");
    ofstream fout("game.out");
    fin >> n >> m >> s;
    edges = vector<vector<int>>(100000);
    ans = vector<bool>(100000);
    mark = vector<bool>(100000);
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        if (u != v) {
            edges[u - 1].push_back(v - 1);
        }
    }

    dfs(s-1);
    if (ans[s-1]) {
        fout << "First player wins";
    }
    else {
        fout << "Second player wins";
    }

}
