#include <vector>
#include <iostream>
#include "opt.h"

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> v(n), u(n);
    for (int i = 0; i < n; ++i) {
        cin >> u[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    optimize(u, v);
    for (auto x: v) {
        cout << x << ' ';
    }
    cout << '\n';
}
