//
// Created by imd on 18/05/2019.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    string str;
    vector<char> s;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    getline(cin, str);
    ifstream fin("lcp.in");
    fin >> str;
    for (auto elem : str) s.emplace_back(elem - '`');
//    getline(cin, str);
//    for (auto elem : str) s.emplace_back(elem - '`');
    s.emplace_back(0);
    unsigned int n = s.size();
    cout << "n is: " << n << '\n';
    vector<unsigned int> p(n), c(n);
    vector<int> quantity(27);
    for (int i = 0; i < n; ++i) quantity[s[i]]++;
    vector<int> cs(27);
    cs[0] = 0;
    for (int i = 1; i < 27; ++i) cs[i] = cs[i - 1] + quantity[i - 1];
    for (int i = 0; i < n; ++i) p[cs[s[i]]++] = i;
    c[p[0]] = 0;
    int class_n = 0;
    for (int i = 1; i < n; ++i) {
        if (s[p[i]] != s[p[i - 1]]) class_n++;
        c[p[i]] = class_n;
    }
    class_n++;

    vector<unsigned int> new_p(n), new_c(n);
    for (unsigned int i = 0; ((unsigned)(1) << i) < n; ++i) {
        for (int j = 0; j < n; ++j) new_p[j] = (p[j] - ((unsigned)(1) << i) + n) % n;
        vector<int> q(class_n);
        for (int j = 0; j < n; ++j) q[c[new_p[j]]]++;
        vector<int> new_cs(class_n);
        new_cs[0] = 0;
        for (int j = 1; j < class_n; ++j) new_cs[j] = new_cs[j - 1] + q[j - 1];
        for (int j = 0; j < n; ++j) p[new_cs[c[new_p[j]]]++] = new_p[j];
        new_c[p[0]] = 0;
        class_n = 0;
        for (int j = 1; j < n; ++j) {
            if (c[p[j - 1]] < c[p[j]] || c[(p[j - 1] + ((unsigned)(1) << i)) % n] < c[(p[j] + ((unsigned)(1) << i)) % n]) class_n++;
            new_c[p[j]] = class_n;
        }
        class_n++;
        c.clear();
        c.resize(class_n);
        copy(new_c.begin(), new_c.end(), c.begin());
    }

    for (int i = 1; i < n; ++i) {
        cout << p[i] + 1 << " ";
    }
    cout << '\n';

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
    cout << "LCPs:";
    for (int i = 1; i < n - 1; ++i) {
        cout << lcp[i] << ' ';
    }
    cout << '\n';
    cout << p[0];
    cout.flush();
}
