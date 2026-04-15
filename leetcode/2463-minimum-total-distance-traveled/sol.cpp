#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size(), m = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e12));
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1e12;
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = 1e12;
                long long rs_part = 0;
                for (int k = i; k >=0 && factory[j - 1][1] >= i - k; --k) {
                    long long dp_part = dp[k][j-1];
                    if (k < i) {
                        rs_part += abs(robot[k] - factory[j - 1][0]);
                    }
                    if (dp_part == 1e12) {
                        continue;
                    }
                    if (dp_part + rs_part <= dp[i][j]) {
                        dp[i][j] = dp_part + rs_part;
                    }
                }
            }
        }
        return dp[n][m];
    }
};

int main() {

    int n,m;
    cin >> n >> m;

    vector<int> robot(n, 0);
    vector<vector<int>> factory(m, {0,0});

    for (int i = 0; i < n; ++i) {
        cin >> robot[i];
    }

    for (int j = 0; j < m; ++j) {
        cin >> factory[j][0] >> factory[j][1];
    }

    Solution sol;
    long long answer = sol.minimumTotalDistance(robot, factory);

    cout << answer << '\n';
}