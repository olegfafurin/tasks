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
#include <xmath.h>

using namespace std;

int main() {
    int n, m;
    int s, f;
    int w;
    vector<int> begin, end = vector<int>(2000);
    vector<vector<pair<int, unsigned long long>>> edges(4000000);
    set<pair<unsigned long long, int>> d;
    vector<unsigned long long> dist(2000);

    auto INFTY = ULONG_LONG_MAX / 2;

//    ifstream fin ("dijkstra.in");
//    ofstream fout("dijkstra.out");

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s >> f;
    s--;
    f--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            cin >> w;
            if (w == -1) continue;
            edges[i].push_back(make_pair(j,w));
        }
    }

    d.insert(make_pair(0, s));
    dist[s] = 0;
    for (int i = 0; i < n; i++) {
        if (i == s) continue;
        d.insert(make_pair<>(INFTY, i));
        dist[i] = INFTY;
    }
    for (int i = 1; i < n; i++) {
        int current = (*d.begin()).second;
        for (auto r : edges[current]) {
            if (r.second + dist[current] < dist[r.first]) {
                d.erase(make_pair(dist[r.first], r.first));
                dist[r.first] = dist[current] + r.second;
                d.insert(make_pair(dist[r.first], r.first));
            }
        }
        d.erase(make_pair(dist[current], current));
    }
    if (dist[f] == INFTY) {
        cout << -1;
        exit(0);
    }
    cout << dist[f];
}