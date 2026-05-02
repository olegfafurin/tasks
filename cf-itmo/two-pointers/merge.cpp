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
    vector<int> ans;
    ans.reserve(n + m);
    int i = 0;
    int j = 0;
    while (i < n || j < m) {
        if (j == m || i < n && a[i] < b[j]) {
            ans.push_back(a[i++]);
        } else {
            ans.push_back(b[j++]);
        }
    }
    for (int t = 0; t < m + n; ++t) {
        cout << ans[t] << ' ';
    }
    cout << '\n';
}
