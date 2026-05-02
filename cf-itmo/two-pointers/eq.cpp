#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int il = 0;
    int ir = 0;
    long long s;
    for (int j = 0; j < m; ++j) {
        while (il < n && a[il] < b[j]) {
            ++il;
        }
        ir = max(ir, il);
        while (ir < n && a[ir] == b[j]) {
            ++ir;
        }
        s += ir - il;
    }
    cout << s << '\n';
}
