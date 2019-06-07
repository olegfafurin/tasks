//
// Created by imd on 12/2/2018.
//


#include <iostream>
#include "algorithm"
#include "vector"

using namespace std;

vector<int> mark, p;
vector<vector<int>> c;
vector<int> match, reverse_match;
vector<vector<bool>> matches;

void process(int v, int u){
    int prev = reverse_match[v];
    matches[u][v] = true;
    while (prev != u){
        matches[prev][p[prev]] = true;
        prev = reverse_match[p[prev]];
    }
}

void dfs(int v) {
    mark[v] = 1;
    for (int u : c[match[v]]) {
        if (mark[u] == 2) {
            p[u] = v;
            dfs(u);
        }
        else if (mark[u] == 1) process(v, u);
    }
    mark[v] = 2;
}

int main() {
    int n, k, u;
    c = vector<vector<int>>(2000);
    mark = p = match = reverse_match = vector<int>(2000);
    matches = vector<vector<bool>>(2000, vector<bool>(2000));

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> u;
            c[u - 1].emplace_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> u;
        match[i] = u - 1;
        reverse_match[u - 1] = i;
        matches[i][u - 1] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (mark[i] == 0) dfs(i);
    }
    for (int i = 0; i < n; ++i) {
        cout << count(matches[i].begin(), matches[i].end(), true) << ' ';
        for (int j = 0; j < n; ++j) {
            if (matches[i][j]) cout << j + 1 << ' ';
        }
        cout << '\n';
    }
}