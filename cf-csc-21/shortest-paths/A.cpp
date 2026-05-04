#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main() {
    int n, v;
    cin >> n >> v;
    --v;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool x;
            cin >> x;
            if (x) {
                adj[i].push_back(j);
            }
        }
    }
    
    vector<int> d(n, -1);
    d[v] = 0;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto neighbor: adj[u]) {
            if (d[neighbor] == -1) {
                d[neighbor] = d[u] + 1;
                q.push(neighbor);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << d[i] << ' ';
    }
    cout << '\n';
}
