//
// Created by imd on 03/06/2019.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;

int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}

int generator (long long p) {
    vector<int> fact;
    long long phi = p-1,  n = phi;
    for (long long i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (long long res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}

int main() {
    cout << generator(998244353);
}