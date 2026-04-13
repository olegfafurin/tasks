#include <vector>
#include <iostream>

using namespace std;

class Solution {
    vector<vector<char>> board;
    string word;
    vector<vector<bool>> used;
    const int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int m, n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        m = board.size();
        n = board[0].size();
        used = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    used[i][j] = true;
                    if (dfs({i,j}, 1)) {
                        return true;
                    }
                    used[i][j] = false;
                }
            }
        }
        return false;
    }

    bool dfs(pair<int,int> node, int index) {
        if (index == word.size()) {
            return true;
        }
        int x = node.first, y = node.second;
        for (int t = 0; t < 4; ++t) {
            int dx = d[t][0], dy = d[t][1];
            if (x + dx < m && x + dx >= 0 && y + dy < n && y + dy >= 0 && !used[x + dx][y + dy] && board[x + dx][y + dy] == word[index]) {
                used[x + dx][y + dy] = true;
                if (dfs({x + dx, y + dy}, ++index)) {
                    return true;
                }
                --index;
                used[x + dx][y + dy] = false;
            }
        }
        return false;
    }
};
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    string word;
    cin >> word;
    Solution sol;
    if (sol.exist(board, word)) {
        cout << word << " found\n";
    } else {
        cout << word << " not found\n";
    }
}