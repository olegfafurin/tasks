#include <vector>
#include <iostream>
#include "segment_tree.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    auto st = SegmentTree<int>(data);
    while (true) {
        string cmd;
        cin >> cmd;
        if (cmd == "upd") {
            int i, v;
            cin >> i >> v;
            st.update(i, v);
        } else if (cmd == "sum") {
            size_t l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << '\n';
        } else if (cmd == "show") {
            for (int i = 0; i < n; ++i) {
                cout << st.sum(i, i) << ' ';
            }
            cout << '\n';
        }
    }
}
