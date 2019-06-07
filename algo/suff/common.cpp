//
// Created by imd on 30/05/2019.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    string str;
    vector<char> s;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    ifstream fin("common.in");
    cin >> str;
    for (auto elem : str) s.emplace_back(elem - '_');
    s.emplace_back(1);
    cin >> str;
    for (auto elem : str) s.emplace_back(elem - '_');
    s.emplace_back(0);
    unsigned int n = s.size();
    vector<int> p(n), c(n);
    vector<int> quantity(28);
    for (int i = 0; i < n; ++i) quantity[s[i]]++;
    vector<int> cs(28);
    cs[0] = 0;
    for (int i = 1; i < 28; ++i) cs[i] = cs[i - 1] + quantity[i - 1];
    for (int i = 0; i < n; ++i) p[cs[s[i]]++] = i;
    c[p[0]] = 0;
    int class_n = 0;
    for (int i = 1; i < n; ++i) {
        if (s[p[i]] != s[p[i - 1]]) class_n++;
        c[p[i]] = class_n;
    }
    class_n++;

    vector<unsigned int> new_p(n), new_c(n);
    for (unsigned int i = 0; ((unsigned) (1) << i) < n; ++i) {
        for (int j = 0; j < n; ++j) new_p[j] = (p[j] - ((unsigned) (1) << i) + n) % n;
        vector<int> q(class_n);
        for (int j = 0; j < n; ++j) q[c[new_p[j]]]++;
        vector<int> new_cs(class_n);
        new_cs[0] = 0;
        for (int j = 1; j < class_n; ++j) new_cs[j] = new_cs[j - 1] + q[j - 1];
        for (int j = 0; j < n; ++j) p[new_cs[c[new_p[j]]]++] = new_p[j];
        new_c[p[0]] = 0;
        class_n = 0;
        for (int j = 1; j < n; ++j) {
            if (c[p[j - 1]] < c[p[j]] ||
                c[(p[j - 1] + ((unsigned) (1) << i)) % n] < c[(p[j] + ((unsigned) (1) << i)) % n])
                class_n++;
            new_c[p[j]] = class_n;
        }
        class_n++;
        c.clear();
        c.resize(class_n);
        copy(new_c.begin(), new_c.end(), c.begin());
    }

//    for (int i = 0; i < n; ++i) {
//        cout << (char) (s[i] + '_');
//    }
//    cout << '\n';

//    for (int i = 1; i < n; ++i) {
//        cout << p[i] + 1 << " ";
//    }
//    cout << '\n';

    vector<int> inv(n), lcp(n);
    for (int i = 0; i < n; ++i) inv[p[i]] = i;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (inv[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[inv[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[inv[i]] = k;
        if (k > 0) k--;
    }
//    cout << "LCPs:";
//    for (int i = 1; i < n - 1; ++i) {
//        cout << lcp[i] << ' ';
//    }
    vector<pair<int, int>> lcp_ind;
    for (int i = 1; i < n - 1; ++i) {
        lcp_ind.emplace_back(make_pair(lcp[i], i));
    }
    sort(lcp_ind.begin(), lcp_ind.end(), [](pair<int, int> a, pair<int, int> b) { return (a.first > b.first) || (a.first == b.first && a.second < b.second); });
    int middle = n - str.size() - 2;
    for (int i = 0; i < n - 2; ++i) {
        if ((long long)(p[lcp_ind[i].second] - middle) * (long long)(p[lcp_ind[i].second + 1] - middle) < 0) {
            for (int j = p[lcp_ind[i].second]; j < p[lcp_ind[i].second] + lcp_ind[i].first; ++j) {
                cout << char(s[j] + '_');
            }
            return 0;
        }
    }
    cout << '\n';
}
