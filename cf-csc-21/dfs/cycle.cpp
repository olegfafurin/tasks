#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

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
    vector<int> path;
    int cycleStart = -1;
    
    function<bool(int)> dfs = [&] (int v) -> bool {
        visited[v] = 1;
        path.push_back(v);
        for (const auto& u: adj[v]) {
            if (visited[u] == 0) {
                if (dfs(u)) {
                    return true;
                }
            } else if (visited[u] == 1) {
                cycleStart = u;
                return true;
            }
        }
        path.pop_back();
        visited[v] = 2;
        return false;
    };

    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0) {
            if (dfs(i)) {
                cout << "YES\n";
                for (auto it = find(path.begin(), path.end(), cycleStart); it != path.end(); ++it) {
                    cout << *it + 1 << ' ';
                }
                cout << '\n';
                return 0;
            }
        }
    }
    cout << "NO\n";
}
