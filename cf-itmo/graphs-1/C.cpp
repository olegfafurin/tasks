#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tn = 0; tn < t; ++tn) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<unordered_set<int>> adj(n);
        vector<int> path;
        path.reserve(k);
        for (int i = 0; i < k; ++i) {
            int v;
            cin >> v;
            path.push_back(v);
        }
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].insert(v);
            adj[v - 1].insert(u);
        }
        bool isValid = true;
        int v = path[0];
        for (int i = 1; i < k; ++i) {
            if (!adj[v - 1].contains(path[i])) {
                isValid = false;
            }
            v = path[i];
        }
        unordered_set<int> p(path.begin() + 1, path.end());
        bool isSimple = (p.size() == path.size() - 1);
        bool isCycle = (path[0] == path[path.size() - 1]);
        if (isValid) {
            if (isCycle) {
                if (isSimple) {
                    cout << "simple cycle\n";
                } else {
                    cout << "cycle\n";
                }
            } else if (isSimple && !p.contains(path[0])) {
                cout << "simple path\n";
            } else {
                cout << "path\n";
            }
        } else {
            cout << "none\n";
        }
    }
}
