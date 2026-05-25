#include <vector>
#include <climits>
#include <iostream>

using namespace std;


class SegmentTree {
    vector<int> data;
    int s;

    public:

    SegmentTree(int n) {
        s = 1;
        while (s < n) {
            s <<= 1;
        }
        data = vector<int>(2 * s);
        for (int i = 0; i < n; ++i) {
            data[s + i] = i;
        }
        for (int i = n; i < s; ++i) {
            data[s + i] = INT_MAX;
        }
        for (int i = s - 1; i > 0; --i) {
            data[i] = min(data[2 * i], data[2 * i + 1]);
        }
    }

    int get(int i) {
        i += s;
        while (data[i] == INT_MAX) {
            i = (i + 1) / 2;
        }
        int ans = data[i];
        int ind = ans + s;
        data[ind] = INT_MAX;
        while (ind > 1) {
            data[ind >> 1] = min(data[ind], data[ind ^ 1]);
            ind >>= 1;
        }
        return ans;
    }

};


int main() {
    int n;
    cin >> n;
    auto st = SegmentTree(n);
    for (int i = 0; i < n; ++i) {
        int idx;
        cin >> idx;
        cout << st.get(idx - 1) + 1 << ' ';
    }
    cout << '\n';
}
