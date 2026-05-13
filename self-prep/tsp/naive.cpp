#include <vector>
#include <iostream>
#include <functional>
#include <climits>
#include <unordered_set>


using namespace std;

int main() {
    int n;
    cin >> n;


    vector d(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
        }
    }

    vector<int> path;
    int price = 0;
    unordered_set<int> unused;
    for (int i = 0; i < n; ++i) {
        unused.insert(i);
    }
    vector<int> bestPath;
    int bestPrice = INT_MAX;
    
    function<void()> backtrack = [&] () -> void {
        if (unused.empty()) {
            if (price < bestPrice) {
                bestPrice = price;
                bestPath = path;
            }
            return;
        }
        vector<int> options(unused.begin(), unused.end());
        for (auto u: options) {
            unused.erase(u);
            price += path.empty() ? 0 : d[path[path.size() - 1]][u];
            path.push_back(u);
            backtrack();
            path.pop_back();
            price -= path.empty() ? 0 : d[path[path.size() - 1]][u];
            unused.insert(u);
        }
    };

    backtrack();

    if (bestPath.empty()) {
        cout << "No Hamiltonian path\n";
    } else {
        cout << "best price: " << bestPrice << '\n';
        for (int i = 0; i < n; ++i) {
            cout << bestPath[i] << ' ';
        }
        cout << '\n';
    }
}

