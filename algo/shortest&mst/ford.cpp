//
// Created by imd on 11/12/2018.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <set>

using namespace std;

vector<int> changed;
vector<vector<int>> l;

void dfs(int vertex) {
    changed[vertex] = 1;
    for (int nb : l[vertex]) {
        if (!changed[nb]) dfs(nb);
    }
}


int main() {
    vector<pair<pair<int, int>, long long>> edges(0);
    changed = vector<int>(2000);
    l = vector<vector<int>>(2000);
    vector<int> p(2000);
    vector<long long> d(2000);
    auto INFTY = LONG_LONG_MAX / 2;
    int n, m, s, u, v;
    long long w;

//    ifstream fin ("ford.in");
//    ofstream fout("ford.out");

    cin >> n >> m >> s;
    s--;
    w = -1;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        u--;
        v--;
        l[u].push_back(v);
        edges.push_back(make_pair(make_pair(u, v), w));
    }

    for (int i = 0; i < n; ++i) d[i] = INFTY;
    d[s] = 0;
    for (int k = 0; k < n; k++) changed[k] = 0;
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < m; i++) {
            if ((d[edges[i].first.first] + edges[i].second < d[edges[i].first.second]) && (d[edges[i].first.first] < INFTY)) {
                if (d[edges[i].first.first] + edges[i].second > -INFTY) {
                    d[edges[i].first.second] = d[edges[i].first.first] + edges[i].second;
                    p[edges[i].first.second] = edges[i].first.first;
                }
                else {
                    d[edges[i].first.second] = -INFTY;
                    changed[edges[i].first.second] = 1;
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if ((d[edges[i].first.first] + edges[i].second < d[edges[i].first.second]) && (d[edges[i].first.first] < INFTY)) {
            changed[edges[i].first.second] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (changed[i]) dfs(i);
    }

    for (int i = 0; i < n; ++i) {
        if (d[i] == INFTY) {
            cout << "*\n";
            continue;
        } else if (changed[i]) {
            cout << "-\n";
        } else cout << d[i] << '\n';
    }
}