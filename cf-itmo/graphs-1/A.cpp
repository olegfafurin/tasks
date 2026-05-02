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
        unordered_map<int,unordered_set<int>> e;
        bool isCorrect = true;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            if (u <= 0 || u > n || v <= 0 || v > n || u == v || e[min(u, v)].contains(max(u, v))) {
                isCorrect = false;
            }
            e[min(u,v)].insert(max(u,v));
        }
        cout << (isCorrect ? "YES" : "NO") << '\n';
    }
}
