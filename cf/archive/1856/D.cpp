#include <vector>
#include <cstdlib>
#include <deque>
#include <bit>
#include <iostream>

using namespace std;


int getInv(int l, int r) {
    int x;
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    cin >> x;
    return x;
}


int getInt() {
    int x;
    cin >> x;
    if (x == -1) {
        exit(EXIT_FAILURE);
    }
    return x;
}

int main() {
    int testCnt;
    cin >> testCnt;
    while (testCnt--) {
        auto n = static_cast<unsigned int>(getInt());
        auto s = bit_ceil(n);
        deque<int> d;
        for (int i = 0; i < n; ++i) {
            d.push_front(i + 1);
        }
        for (int i = 0; i < s - n; ++i) {
            d.push_front(-1);
        }
        while (d.size() > 1) {
            int r = d.front();
            d.pop_front();
            int l = d.front();
            d.pop_front();
            if (r == -1) {
                d.push_back(l);
                continue;
            }
            int inv2 = getInv(l, r);
            if (l + 1 == r) {
                d.push_back(inv2 ? l : r);
            } else if (inv2 == getInv(l, r - 1)) {
                d.push_back(r);
            } else {
                d.push_back(l);
            }
        }
        cout << "! " << d.front() << '\n';
        cout.flush();
    }
}
