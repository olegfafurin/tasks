//
// Created by imd on 11/30/2018.
//


#include <iostream>
#include "algorithm"
#include "vector"
#include <fstream>

using namespace std;

vector<bool> mark, has_match, take;
vector<vector<int>> c;
vector<int> match;
int from_first, from_second;
int k, m, n, u;

void dfs(int v) {
    for (int u : c[v]) {
        if (!mark[u]) {
            mark[u] = true;
            from_second++;
            dfs(match[u]);
        }
    }
}

bool kuhn(int v) {
    if (mark[v]) return false;
    mark[v] = true;
    for (int u : c[v]) {
        if (match[u] == -1 || kuhn(match[u])) {
            match[u] = v;
            return true;
        }
    }
    return false;
}


int main() {
    c = vector<vector<int>>(150);
    mark = has_match = take = vector<bool>(150);
    match = vector<int>(150);
    vector<bool> temp(150);
//    ifstream fin("indep3.in");
//    ofstream fout("indep.out");
    cin >> k;
    for (int index = 0; index < k; ++index) {
        cin >> m >> n;
        from_second = from_first = 0;
        for (int j = 0; j < m; ++j) {
            for (int t = 0; t < 150; t++) temp[t] = false;
            c[j].clear();
            while (true) {
                cin >> u;
                if (u == 0) {
                    for (int t = 0; t < n; t++) if (!temp[t]) c[j].emplace_back(t);
                    break;
                }
                temp[u - 1] = true;
            }
        }
        for (int i = 0; i < n; ++i) match[i] = -1;
        for (int j = 0; j < m; ++j) mark[j] = has_match[j] = false;
        for (int i = 0; i < m; ++i) {
            if (!mark[i]) {
                for (int j = 0; j < m; ++j) mark[j] = false;
                kuhn(i);
            }
        }
        for (int i = 0; i < n; ++i) if (match[i] != -1) has_match[match[i]] = true;
        for (int j = 0; j < 150; ++j) mark[j] = false;
        for (int i = 0; i < m; ++i) {
            take[i] = false;
            if (!has_match[i]) dfs(i);
        }
        for (int i = 0; i < n; ++i) {
            if ((!mark[i]) && (match[i] != -1)) {
                take[match[i]] = true;
                from_first++;
            }
        }
        cout << n + m - from_first - from_second << '\n';
        cout << m - from_first << ' ' << n - from_second << '\n';
        for (int i = 0; i < m; ++i) if (!take[i]) cout << i + 1 << ' ';
        cout << '\n';
        for (int i = 0; i < n; ++i) if (!mark[i]) cout << i + 1 << ' ';
        cout << "\n\n";
    }
}