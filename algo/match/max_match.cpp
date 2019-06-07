//
// Created by imd on 11/29/2018.
//

#include <iostream>
#include "algorithm"
#include "vector"

using namespace std;

vector<bool> mark;
vector<vector<int>> c;
vector<int> match;
int counter = 0;

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
    int n, m, k;
    int u, v;
    c = vector<vector<int>>(200);
    mark = vector<bool>(200);
    match = vector<int>(200);
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        cin >> u >> v;
        c[u - 1].emplace_back(v - 1);
    }
    for (int i = 0; i < m; ++i) match[i] = -1;

    for (int i = 0; i < n; ++i) {
        if (!mark[i]) {
            for (int j = 0; j < n; ++j) mark[j] = false;
            if (kuhn(i)) counter++;
        }
    }

    cout << counter;
}