#include <vector>
#include <queue>
#include <iostream>

using namespace std;


vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();

    priority_queue<pair<int,int>> q;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    q.push({0,0});
    vector<pair<int,int>> delta = {{0,1},{1,0},{0,-1},{-1,0}};
    while (!q.empty()) {
        auto cell = q.top();
        q.pop();
        int y = cell.first, x = cell.second;
        if (visited[y][x]) {
            continue;
        }
        visited[y][x] += 1;
        for (auto [dx, dy]: delta) {
            int xn = x + dx, yn = y+dy;
            if ((xn >= 0) && (yn >= 0) && (xn < n) && (yn < m) && (!visited[yn][xn])) {
                if ((heights[yn][xn] >= heights[y][x]) || (xn == 0) || (yn == 0)) {
                    q.push({yn, xn});
                }
            }
        }
    }

    q.push({m-1, n-1});

    while (!q.empty()) {
        auto cell = q.top();
        q.pop();
        int y = cell.first, x = cell.second;
        if (visited[y][x] >= 2) {
            continue;
        }
        visited[y][x] += 2;
        for (auto [dx, dy]: delta) {
            int xn = x + dx, yn = y+dy;
            if ((xn >= 0) && (yn >= 0) && (xn < n) && (yn < m) && (visited[yn][xn] < 2)) {
                if ((heights[yn][xn] >= heights[y][x]) || (xn == n - 1) || (yn == m - 1)) {
                    q.push({yn, xn});
                }
            }
        }
    }

    vector<vector<int>> result;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j] >= 3) {
                result.push_back({i,j});
            }
        }
    }
    return result;
}

int main() {

    int n,m;

    cin >> m >> n;


    vector<vector<int>> v(m, vector<int>(n,0));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int x;
            cin >> x;
            v[i][j] = x;
        }
    }

    for (auto u : pacificAtlantic(v)) {
        cout << "[" << u[0] << "," << u[1] << "] ";
    }
    cout << '\n';
}