//
// Created by imd on 12/04/2019.
//

#include <bits/stdc++.h>

using namespace std;
const long long MOD = 998'244'353;

long long deg(vector<long long> &p, size_t threshold = 1000001) {
    for (int i = min(threshold, p.size()) - 1; i >= 0; i--) {
        if (p[i] != 0) return i;
    }
}

vector<long long> summ(vector<long long> &p, vector<long long> &q) {
    vector<long long> sum;
    for (int i = 0; i < max(p.size(), q.size()); i++) sum.push_back((p[i] + q[i]) % MOD);
    return sum;
}

vector<long long> product(vector<long long> &p, vector<long long> &q) {
    vector<long long> product(p.size() + q.size() - 1);
    for (int i = 0; i < p.size(); i++)
        for (int j = 0; j < q.size(); j++)
            product[i + j] = product[i + j] + (p[i] * q[j]) % MOD;
    return product;
}

vector<long long> inverse(vector<long long> &p) {
    vector<long long> inverse(1000);
    inverse[0] = 1;
    for (int i = 1; i < 1000; i++) {
        for (int j = 0; j < i; ++j) {
            inverse[i] = (inverse[i] - inverse[j] * p[i - j]) % MOD;
        }
    }
    return inverse;
}

void mod(vector<long long> &p) {
    for (int i = 0; i < p.size(); i++) {
        p[i] = (p[i] % MOD + MOD) % MOD;
    }
}

int main() {
    vector<long long> p(1001);
    vector<long long> q(1001);
    vector<long long> sum_res(1001), quot_res(1000), product_res(1000001);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + 1; ++i) cin >> p[i];
    for (int j = 0; j < m + 1; ++j) cin >> q[j];
    sum_res = summ(p,q);
    mod(sum_res);
    cout << deg(sum_res) << "\n";
    for (int i = 0; i <= deg(sum_res); i++) cout << sum_res[i] << ' ';
    cout << "\n";
    product_res = product(p, q);
    mod(product_res);
    cout << deg(product_res) << "\n";
    for (int i = 0; i <= deg(product_res); i++) cout << product_res[i] << ' ';
    cout << "\n";
    vector<long long> inv = inverse(q);
    mod(inv);
    quot_res = product(inv, p);
    mod(quot_res);
//    cout << deg(quot_res, 1000) << "\n";
    for (int i = 0; i < 1000; i++) cout << quot_res[i] << ' ';
}