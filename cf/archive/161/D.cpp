#include <vector>
#include <iostream>
#include <functional>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector adj(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector dp(n, vector<int>(k + 1));
    long long ans = 0;

    auto dfs = [&] (this auto dfs, int v, int p) -> void {
        dp[v][0] = 1;
        for (int u: adj[v]) {
            if (u != p) {
                dfs(u, v);
                ans += dp[u][k - 1];
                for (int i = 1; i < k; ++i) {
                    ans += dp[v][i] * dp[u][k - 1 - i];
                    dp[v][i] += dp[u][i - 1];
                }
                dp[v][k] += dp[u][k - 1];
            }
        }
    };

    dfs(0, -1);
    cout << ans << '\n';
}
