#include <vector>
#include <iostream>
#include "fenwick_tree.h"


using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    auto ft = FenwickTree<int>(data);

    string cmd;
    while (cin >> cmd) {
        if (cmd == "add") {
            int i, v;
            cin >> i >> v;
            ft.add(i, v);
        } else if (cmd == "set") {
            int i, v;
            cin >> i >> v;
            ft.set(i, v);
        } else if (cmd == "sum") {
            size_t l, r;
            cin >> l >> r;
            cout << ft.sum(l, r) << '\n';
        } else if (cmd == "show") {
            for (int i = 0; i < n; ++i) {
                cout << ft.sum(i, i) << ' ';
            }
            cout << '\n';
        }
    }
}
