#include <vector>
#include <string>
#include <iostream>

using namespace std;


vector<int> z(const string& s) {
    const int n = s.size();
    vector<int> v(n, 0);
    int r = 0, l = -1;
    for (int i = 1; i < n; ++i) {
        int j = i > r ? 0 : min(v[i - l], r - i + 1);
        while (i + j < n && s[i + j] == s[j]) {
            ++j;
        }
        v[i] = j;
        if (j > 0 && i + j - 1 > r) {
            r = i + j - 1;
            l = i;
        }
    }
    return v;
}


vector<int> z2(const string& s) {
    const int n = s.size();
    vector<int> v(n, 0);
    int r = 0, l = -1;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            v[i] = min(r - i + 1, v[i - l]);
        }
        while (i + v[i] < n && s[i + v[i]] == s[v[i]]) {
            ++v[i];
        }
        if (i + v[i] - 1 > r) {
            r = i + v[i] - 1;
            l = i;
        }
    }
    return v;
}


int main() {
    string s;
    cin >> s;
    vector<int> v = z2(s);
    for (auto x: v) {
        cout << x << ' ';
    }
    cout << '\n';
}
