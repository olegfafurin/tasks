//
// Created by imd on 10/10/2019.
//

#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<pair<int, int>, bool> mark;
map<pair<int, int>, bool> visited;
int n, m;

vector<pair<int, int>> neighbours(pair<int, int> cell) {
    int x = cell.first;
    int y = cell.second;
    vector<pair<int, int>> result = vector<pair<int, int>>();
    if (x > 0) result.emplace_back(pair<int, int>(x - 1, y));
    if (y > 0) result.emplace_back(pair<int, int>(x, y - 1));
    if (x < n - 1) result.emplace_back(pair<int, int>(x + 1, y));
    if (y < m - 1) result.emplace_back(pair<int, int>(x, y + 1));
    return result;
}

void reach(vector<vector<int>> &heightMap, int x, int y) {
    auto cell = pair<int, int>(x, y);
    mark[cell] = true;
    for (auto u : neighbours(cell))
        if (mark.count(u) == 0 || (!mark[u] && heightMap[u.first][u.second] >= heightMap[x][y]))
            reach(heightMap, u.first, u.second);
}

int find_border(vector<vector<int>> &heightMap, int &ground, int &cells, int x, int y) {
    auto cell = pair<int, int>(x, y);
    cells++;
    visited[cell] = true;
    int a = 20000;
    ground += heightMap[x][y];
    for (auto u: neighbours(cell)) {
        if ((visited.count(u) == 0 || !visited[u]) && !mark[u]) {
            a = min(a, find_border(heightMap, ground, cells, u.first, u.second));
        } else if (mark[u]) a = min(a, heightMap[u.first][u.second]);
    }
    return a;
}

int trapRainWater(vector<vector<int>> &heightMap) {
    n = heightMap.size();
    if (n == 0) return 0;
    m = heightMap[0].size();
    if (m == 0) return 0;
    vector<vector<bool>> reachable = vector<vector<bool>>(n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        mark[pair<int, int>(i, 0)] = true;
        mark[pair<int, int>(i, m - 1)] = true;
    }
    for (int i = 0; i < m; ++i) {
        mark[pair<int, int>(0, i)] = true;
        mark[pair<int, int>(n - 1, i)] = true;
    }
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            mark[pair<int, int>(i, j)] = false;
        }
    }
    for (int i = 0; i < n; ++i) {
        reach(heightMap, i, 0);
        reach(heightMap, i, m - 1);
    }
    for (int i = 0; i < m; ++i) {
        reach(heightMap, 0, i);
        reach(heightMap, n - 1, i);
    }
    int round_cells;
    int round_ground;
    int rain = 0;
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            auto cell = pair<int, int>(i, j);
            if ((visited.count(cell) == 0 || !visited[cell]) && !mark[cell]) {
                round_cells = 0;
                round_ground = 0;
                int min_surrounding = find_border(heightMap, round_ground, round_cells, i, j);
                rain += round_cells * min_surrounding - round_ground;
            }
        }
    }
    return rain;
}

int main() {
    int u, v, t;
    cin >> u >> v;
    auto field = vector<vector<int>>(u, vector<int>(v));
    for (int i = 0; i < u; ++i) {
        for (int j = 0; j < v; ++j) {
            cin >> field[i][j];
        }
    }
    cout << trapRainWater(field);
}