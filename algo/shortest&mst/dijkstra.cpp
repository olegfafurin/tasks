//
// Created by imd on 11/11/2018.
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
    int s = 0;
    int u, v, w;
    vector<int> begin, end = vector<int>(30000);
    vector<vector<pair<int, int>>> edges(30000);
    set<pair<int, int>> d;
    vector<int> dist(30000);

//    ifstream fin ("dijkstra.in");
//    ofstream fout("dijkstra.out");

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--;
        v--;
        edges[u].push_back(make_pair(v, w));
        edges[v].push_back(make_pair(u, w));
    }

    d.insert(make_pair(0, s));
    dist[s] = 0;
    for (int i = 0; i < n; i++) {
        if (i == s) continue;
        d.insert(make_pair(1000000000, i));
        dist[i] = 1000000000;
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
    for (int i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
}
