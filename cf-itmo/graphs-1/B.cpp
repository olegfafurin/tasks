#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tn = 0; tn < t; ++tn) {
        int n, m;
        cin >> n >> m;
        vector<int> deg(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            ++deg[u - 1];
            ++deg[v - 1];
        }
        for (int i = 0; i < n; ++i) {
            cout << deg[i] << ' ';
        }
        cout << '\n';
    }
 
}
 
