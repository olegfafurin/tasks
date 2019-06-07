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


int main() {
    int n, m;
    int u, v, w;
    vector<vector<int>> d(200, vector<int>(200));
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = 1000000000;
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        u--;
        v--;
        if (d[u][v] > w) d[u][v] = w;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
}