//
// Created by imd on 02/06/2019.
//


#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
unsigned long N, MOD, Z, NX;
vector<unsigned long> powers;

void fft(vector<unsigned long> &u, int I) {
    unsigned long t1, t2, x;
    unsigned long i, j, p, l, zl, L, BL;
    L = N;
    BL = I;
    while (L >= 2) {
        l = L / 2;
        x = powers[0];
        zl = 0;
        for (j = 0; j < l; j++, x = powers[(zl += BL) & NX])
            for (i = j; i < N; i += L) {
                p = i + l;
                t1 = (u[i] + u[p]) % MOD;
                t2 = (MOD + u[i] - u[p]) % MOD;
                u[p] = (t2 * x) % MOD;
                u[i] = t1 % MOD;
            }
        L /= 2;
        BL *= 2;
    }

    j = 0;
    for (i = 0; i < NX; i++) {
        if (i > j) {
            t1 = u[j];
            u[j] = u[i];
            u[i] = t1;
        }
        l = N / 2;
        while (j >= l) {
            j -= l;
            l /= 2;
        }
        j += l;
    }
}

int main() {
    MOD = 998244353;
    N = 1048576;
    NX = 1048575;
    Z = 3;
    powers = vector<unsigned long>(N);
    powers[0] = 1;
    for (int i = 1; i < N; i++) {
        powers[i] = powers[i - 1] * Z % MOD;
    }
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    vector<unsigned long> b = vector<unsigned long>(N);
    vector<unsigned long> a = vector<unsigned long>(N);
    for (int i = 0; i < s.size(); i++) {
        a[i] = s[i] - '0';
    }
    for (int i = 0; i < t.size(); i++) {
        b[i] = t[i] - '0';
    }

    fft(a, 1);
    fft(b, 1);
    vector<unsigned long> c = vector<unsigned long>(N);
    for (int j = 0; j < N; ++j) {
        c[j] = (a[j] * b[j]) % MOD;
    }
    fft(c, -1);
    unsigned long shift = 0;
    for (int i = 0; i < N; ++i) {
        c[i] = (MOD - c[i]) % MOD;
        c[i] += shift;
        shift = c[i] / 10;
        c[i] = c[i] % 10;
    }
    int i = N - 1;
    while (i >= 0 && c[i] == 0) i--;
    for (int j = i; j >= 0; j--) {
        cout << c[j];
    }
}