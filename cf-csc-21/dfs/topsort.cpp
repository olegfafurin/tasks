#include <vector>
#include <iostream>
#include <functional>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }

    vector<int> visited(n, 0);
    vector<int> answer(n, 0);
    int idx = n - 1;
    
    function<bool(int)> dfs = [&] (int v) -> bool {
        visited[v] = 1;
        for (const auto& u: adj[v]) {
            if (visited[u] == 0) {
                if (!dfs(u)) {
                    return false;
                }
            } else if (visited[u] == 1) {
                return false;
            }
        }
        answer[idx--] = v;
        visited[v] = 2;
        return true;
    };

    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0) {
            if (!dfs(i)) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << answer[i] + 1 << ' ';
    }
    cout << '\n';
}
