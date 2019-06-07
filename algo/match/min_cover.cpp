//
// Created by imd on 11/30/2018.
//

#include <iostream>
#include "algorithm"
#include "vector"

using namespace std;

vector<bool> mark, has_match, take;
vector<vector<int>> c;
vector<int> match;
int counter = 0;
int from_first, from_second;

void dfs(int v) {
    for (int u : c[v]) {
        if (!mark[u]) {
            mark[u] = true;
            from_second++;
            dfs(match[u]);
        }
    }
}

int main() {
    int n, m, k;
    int u, v;
    c = vector<vector<int>>(4000);
    mark = has_match = take = vector<bool>(4000);
    match = vector<int>(4000);

    cin >> m >> n;
    for (int i = 0; i < n; ++i) match[i] = -1;
    for (int i = 0; i < n; ++i) mark[i] = false;
    for (int i = 0; i < m; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> u;
            c[i].emplace_back(u - 1);
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> k;
        if (k == 0) continue;
        match[k - 1] = i;
        has_match[i] = true;
        counter++;
    }
    for (int i = 0; i < m; ++i) {
        if (!has_match[i]) dfs(i);
    }
    for (int i = 0; i < n; ++i) {
        if ((!mark[i]) && (match[i] != -1)) {
            take[match[i]] = true;
            from_first++;
        }
    }

    if (from_second + from_first != counter) {
        return(1);
    }

    cout << counter << '\n';
    cout << from_first << ' ';
    for (int i = 0; i < m; ++i) {
        if (take[i]) cout << i + 1 << ' ';
    }
    cout << '\n';
    cout << from_second << ' ';
    for (int i = 0; i < n; ++i) {
        if (mark[i]) cout << i + 1 << ' ';
    }


}