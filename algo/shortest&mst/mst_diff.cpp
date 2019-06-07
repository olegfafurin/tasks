//
// Created by imd on 11/15/2018.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <set>

using namespace std;

struct edge {
    int u;
    int v;
    long long w;

    edge(int u, int v, long long w) : u(u), v(v), w(w) {}

    bool operator<(const edge &other) {
        return (w < other.w);
    }
};

vector<int> id;

int find_set(int v) {
    while (id[v] != v) v = id[v];
    return v;
}

void unite(int v, int u) {
    if (rand() & 1){
        int r_v = find_set(v);
        id[r_v] = find_set(u);
    }
    else {
        int r_u = find_set(u);
        id[r_u] = find_set(v);
    }
}


int main() {

//    ifstream fin("mst_diff.in");
    int n, m, u, v, comp, prev;
    long long diff, min_edge, max_edge, w;
    cin >> n >> m;
    vector<edge> edges;
    id = vector<int>(1000);

    if (m == 0) {
        cout << "NO";
        exit(0);
    }

    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        if (u == v) continue;
        edges.emplace_back(--u, --v, w);
    }

    for (int i = 0; i < n; ++i) {
        id[i] = i;
    }

    sort(edges.begin(), edges.end());

    comp = n;
    diff = 1000000000;

    for (int j = 0; j < m; j++) {
        if ((j > 0) && (edges[j].w == edges[j-1].w)) continue;
        comp = n;
        for (int i = 0; i < n; ++i) { id[i] = i; }
        min_edge = edges[j].w;
        for (int i = j; i < edges.size(); i++) {
            if (find_set(edges[i].v) != find_set(edges[i].u)) {
                unite(edges[i].v, edges[i].u);
                comp--;
                max_edge = edges[i].w;
                if (comp == 1) break;
            }
        }
        if (comp != 1) {
            if (j == 0) {
                cout << "NO";
                exit(0);
            } else {
                cout << "YES\n" << diff;
                exit(0);
            }
        }
        diff = min(diff, max_edge - min_edge);
    }
    cout << "YES\n" << diff;
}