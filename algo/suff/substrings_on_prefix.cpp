//
// Created by imd on 01/06/2019.
//


#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<pair<uint32_t, uint32_t>>> sparse;

int get_min(int l, int r) {
    uint32_t d = r - l;
    uint32_t deg = 0;
    pair<uint32_t, uint32_t> a = {200000, -1};
    while (l < r) {
        if (d % 2 == 1) {
            if (a > sparse[l][deg]) a = sparse[l][deg];
            l += (((uint32_t) (1)) << deg);
        }
        d = d >> (uint32_t) (1);
        deg++;
    }
    return a.first;
}

int main() {
    string str;
    vector<char> s;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> str;
    reverse(str.begin(), str.end());
    for (auto elem : str) s.emplace_back(elem - '`');
    s.emplace_back(0);
    unsigned int n = s.size();
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

    sparse = vector<vector<pair<uint32_t, uint32_t>>>(n, vector<pair<uint32_t, uint32_t>>(20, {0, 0}));
    for (uint32_t i = 1; i < n - 1; ++i) sparse[i][0] = {lcp[i], i};
    for (uint32_t deg = 1; deg < 20; ++deg) {
        uint32_t i = 1;
        while ((i + ((uint32_t) 1 << (deg - 1))) < (n - 1)) {
            sparse[i][deg] = min(sparse[i][deg - 1], sparse[i + ((uint32_t) 1 << (deg - 1))][deg - 1]);
            i++;
        }
        while (i < n - 1) {
            sparse[i][deg] = sparse[i][deg - 1];
            i++;
        }
    }

    vector<pair<int, int>> lcp_ind = vector<pair<int, int>>();
    for (int i = 1; i < n; ++i) {
        lcp_ind.emplace_back(make_pair(n - p[i] - 1, i));
    }
    sort(lcp_ind.begin(), lcp_ind.end());
    long long running = 0;
    cout << 1 << '\n';
    int l = lcp_ind[0].second;
    set<int> added = set<int>({lcp_ind[0].second});
    for (int i = 1; i < n - 1; ++i) {
        int current_ind = lcp_ind[i].second;
        auto b = added.upper_bound(current_ind);
        if (b != added.end() && b != added.begin()) {
            int rb = *b;
            int lb = *(prev(b));
            running -= get_min(lb, rb);
            running += get_min(lb, current_ind) + get_min(current_ind, rb);
        } else if (b != added.end()) {
            running += get_min(current_ind, *b);
        } else {
            int last = *(added.rbegin());
            running += get_min(last, current_ind);
        }
        added.insert(current_ind);
        cout << (((long long) (i + 1) * (long long) (i + 2)) / 2) - running << '\n';
    }
}