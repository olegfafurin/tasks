//
// Created by imd on 24/05/2019.
//

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <fstream>
#include <set>
#include <deque>

using namespace std;

uint32_t mylog(int32_t n) {
    uint32_t i = 0;
    while (n > 1) {
        n /= 2;
        i++;
    }
    return i;
}

vector<vector<pair<uint32_t, uint32_t>>> sparse;
vector<int> lcp;
deque<pair<uint32_t, uint32_t>> q;

int get_min(int l, int r) {
    uint32_t d = r - l;
    uint32_t deg = 0;
    pair<uint32_t, uint32_t> a = {200000, -1};
    while (l < r) {
        if (d % 2 == 1) {
//            a = min(a, sparse[l][deg]);
            if (a > sparse[l][deg]) a = sparse[l][deg];
            l += ((uint32_t) 1 << deg);
        }
        d = d >> (uint32_t) (1);
        deg++;
    }
    return a.second;
}

pair<long long, pair<int, int>> result;

uint32_t process(int l, int r) {
    if (l == r) return 0;
    int i = get_min(l, r);
    if (result.first < (long long)(lcp[i]) * (long long)(r - l + 1)) {
        result.first = (long long)(lcp[i]) * (long long)(r - l + 1);
        result.second = {l, r};
    }
    return i;
//    process(l, i);
//    process(i + 1, r);
}

int main() {
//    std::chrono::steady_clock::time_pouint32_t begin = std::chrono::steady_clock::now();
    vector<int> s;
    uint32_t m, temp;
    uint32_t n;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    ifstream fin("refrain.in");
//    ofstream fout("refrain.out");
    cin >> n >> m;
    for (uint32_t i = 0; i < n; i++) {
        cin >> temp;
        s.emplace_back(temp);
    }
    s.emplace_back(0);
    n = s.size();
//    cout << n << '\n';
//    cout.flush();
    vector<int> p(n, 0);
    vector<int> c(n, 0);
    vector<int> quantity(12, 0);
    for (int i = 0; i < n; ++i) quantity[s[i]]++;
    vector<int> cs(12, 0);
    for (int i = 1; i < 12; ++i) cs[i] = cs[i - 1] + quantity[i - 1];
    for (int i = 0; i < n; ++i) p[cs[s[i]]++] = i;
    c[p[0]] = 0;
    int class_n = 0;
    for (uint32_t i = 1; i < n; ++i) {
        if (s[p[i]] != s[p[i - 1]]) class_n++;
        c[p[i]] = class_n;
    }
    class_n++;
    vector<int> new_p = vector<int>(n, 0);
    vector<int> new_c = vector<int>(n, 0);
    for (int i = 0; ((uint32_t) (1) << i) < n; ++i) {
        for (int j = 0; j < n; ++j) {
            new_p[j] = (p[j] - ((uint32_t) 1 << i) + n) % n;
        }
        vector<int> qw = vector<int>(200000);
        for (int j = 0; j < n; ++j) qw[c[new_p[j]]]++;
        vector<int> new_cs = vector<int>(class_n);
        new_cs[0] = 0;
        for (int j = 1; j < class_n; ++j) new_cs[j] = new_cs[j - 1] + qw[j - 1];
        for (int j = 0; j < n; ++j) p[new_cs[c[new_p[j]]]++] = new_p[j];
        new_c[p[0]] = 0;
        class_n = 0;
        for (int j = 1; j < n; ++j) {
            if (c[p[j - 1]] < c[p[j]] ||
                c[(p[j - 1] + ((uint32_t) 1 << i)) % n] < c[(p[j] + ((uint32_t) 1 << i)) % n])
                class_n++;
            new_c[p[j]] = class_n;
        }
        class_n++;
        c.clear();
        c.resize(class_n);
        copy(new_c.begin(), new_c.end(), c.begin());
    }

//    for (uint32_t i = 1; i < n; ++i) {
//        fout << p[i] + 1 << " ";
//    }
//    fout << '\n';

    vector<int> inv(n);
    lcp = vector<int>(n);
    for (int i = 0; i < n; ++i) inv[p[i]] = i;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (inv[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[inv[i] + 1];
        while (((i + k) < n) && ((j + k) < n) && (s[i + k] == s[j + k])) k++;
        lcp[inv[i]] = k;
        if (k > 0) k--;
    }
//    fout << "LCPs" << '\n';
//    for (uint32_t i = 1; i < n - 1; ++i) {
//        fout << lcp[i] << ' ';
//    }
//    fout << '\n';
//    fout.flush();
    sparse = vector<vector<pair<uint32_t, uint32_t>>>(n, vector<pair<uint32_t, uint32_t>>(20, {0, 0}));
    for (int i = 1; i < n - 1; ++i) sparse[i][0] = {lcp[i], i};
    for (uint32_t deg = 1; deg < 20; ++deg) {
        int i = 1;
        while (((uint32_t)i + ((uint32_t) 1 << (deg - 1))) < (n - 1)) {
            sparse[i][deg] = min(sparse[i][deg - 1], sparse[i + ((uint32_t) 1 << (deg - 1))][deg - 1]);
            i++;
        }
        while (i < n - 1) {
            sparse[i][deg] = sparse[i][deg - 1];
            i++;
        }
    }

    if (n == 2) {
        cout << 1 << '\n' << 1 << '\n' << s[0];
//        fout.flush();
//        fout.close();
        exit(0);
    }

    result = {n - 1, {inv[0], inv[n - 1]}};

    q.emplace_front(make_pair(1, n - 1));
    while (!q.empty()) {
        auto current = q.back();
        q.pop_back();
        auto mid = process(current.first, current.second);
        if (mid != current.first) q.emplace_front(make_pair(current.first, mid));
        if (mid + 1 != current.second) q.emplace_front(make_pair(mid + 1, current.second));
    }
//    if (result.first == 0) {
//        cout << n - 1 << '\n' << n - 1 << '\n';
//        for (int i = 0; i < n - 1; ++i) cout << s[i] << ' ';
////        fout.flush();
////        fout.close();
//        exit(0);
//    }
    int len;
    if (result == make_pair((long long)(n - 1), make_pair(inv[0], inv[n - 1]))) len = n - 1;
    else len = lcp[result.second.first];
    cout << result.first << "\n" << len << '\n';
    for (int i = 0; i < len; ++i) {
        cout << s[p[result.second.first] + i] << ' ';
    }

//    fout.flush();
//    fout.close();
//    fout.close();
}
