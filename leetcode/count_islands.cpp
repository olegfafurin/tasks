//
// Created by imd on 10/9/2019.
//

#include <vector>
#include <iostream>

using namespace std;

vector<vector<bool>> mark;
int n, m;

void dfs(vector<vector<char>> &grid, int x, int y) {
    mark[x][y] = true;
    if (x > 0 && grid[x-1][y] == '1' && !mark[x-1][y]) dfs(grid, x-1, y);
    if (y > 0 && grid[x][y-1] == '1' && !mark[x][y-1]) dfs(grid, x, y-1);
    if (x < n-1 && grid[x+1][y] == '1' && !mark[x+1][y]) dfs(grid, x+1, y);
    if (y < m-1 && grid[x][y+1] == '1' && !mark[x][y+1]) dfs(grid, x, y+1);
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty())
        return 0;
    n = grid.size();
    m = grid[0].size();
    mark = vector<vector<bool>>(n, vector<bool>(m, false));
    int counter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid [i][j] == '1' && !mark[i][j]) {
                counter++;
                dfs(grid, i, j);
            }
        }
    }
    return counter;
}

int main() {
    int u, v;
    char c;
    cin >> u;
    cin >> v;
    vector<vector<char>> field = vector<vector<char>>(u, vector<char>(v));
    for (int i = 0; i < u; ++i) {
        for (int j = 0; j < v; ++j) {
            cin >> c;
            field[i][j] = c;
        }
    }
    cout << numIslands(field);

}