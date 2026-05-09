class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        auto ans = grid;
        for (int t = 0; t < min(n, m) / 2; ++t) {
            int l = 2 * (n - 1 - 2 * t) + 2 * (m - 1 - 2 * t);
            int shift = k % l;
            if (shift == 0) {
                continue;
            }
            int i = t;
            int j = t;
            int ip = i;
            int jp = j;

            auto step = [&t, &m, &n] (int &x, int &y) -> void {
                if (x == t && y == t) {
                    ++y;
                } else if (y == t) {
                    --x;
                } else if (x == m - 1 - t) {
                    --y;
                } else if (y == n - 1 - t) {
                    ++x;
                } else {
                    ++y;
                }
            };

            for (int ind = 0; ind < shift; ++ind) {
                step(ip, jp);
            }
            for (int ind = 0; ind < l; ++ind) {
                ans[i][j] = grid[ip][jp];
                step(i, j);
                step(ip, jp);
            }
        }
        return ans;
    }
};
