//
// Created by imd on 10/16/2018.
//

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> edges;

ifstream fin("shortpath.in");
ofstream fout("shortpath.out");

int main() {
    int n, m, s, t;
    ifstream fin("shortpath.in");
    ofstream fout("shortpath.out");
    fin >> n >> m >> s >> t;
    edges = vector<vector<int>>(100000);
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        edges[u - 1].push_back(v - 1);
    }

}
