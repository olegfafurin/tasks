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
    //ifstream fin("neg_cycle.in");
    vector<pair<pair<int, int>, int>> edges(0);
    vector<bool> mark(250), change(250);
    vector<int> p(250), d(250);
    int n, w;
    cin >> n;
    for (int i = 0; i < n; i++) {
        p[i] = -1;
        for (int j = 0; j < n; j++) {
            cin >> w;
            if ((w < 0) && (i == j)) {
                cout << "YES\n2\n" << i + 1 << " " << i + 1;
                exit(0);
            }
            if (w != 1000000000) edges.push_back(make_pair(make_pair(i, j), w));
        }
    }
    int m = (int) edges.size();

    for (int i = 0; i < n; ++i) d[i] = 0;

    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < m; i++) {
            if ((d[edges[i].first.first] + edges[i].second < d[edges[i].first.second]) &&
                (d[edges[i].first.first] < 1000000000)) {
                d[edges[i].first.second] = d[edges[i].first.first] + edges[i].second;
                p[edges[i].first.second] = edges[i].first.first;
            }
        }
    }
    for (int k = 0; k < n; k++) change[k] = false;
    for (int i = 0; i < m; i++) {
        if ((d[edges[i].first.first] + edges[i].second < d[edges[i].first.second]) &&
            (d[edges[i].first.first] < 1000000000)) {
            d[edges[i].first.second] = d[edges[i].first.first] + edges[i].second;
            p[edges[i].first.second] = edges[i].first.first;
            change[edges[i].first.second] = true;
        }
    }
    vector<int> cycle;
    int st_cycle = -1;
    for (int k = 0; k < n; k++) {
        if (change[k]) st_cycle = k;
    }
    if (st_cycle != -1) {
        cout << "YES\n";
        for (int j = 0; j < n; ++j) {
            st_cycle = p[st_cycle];
        }
        int current = st_cycle;
        do {
            cycle.push_back(current);
            current = p[current];
        } while (current != st_cycle);
        cycle.push_back(current);
        cout << cycle.size() << '\n';
        for (int i = (int) (cycle.size() - 1); i >= 0; i--) {
            cout << cycle[i] + 1 << ' ';
        }
        exit(0);
    }

    cout << "NO";
}