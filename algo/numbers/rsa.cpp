//
// Created by imd on 02/06/2019.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <cmath>
#include <chrono>

using namespace std;

long long fast_pow(long long a, long long n, long long m) {
    long long result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * a) % m;
            n--;
        }
        a = (a * a) % m;
        n /= 2;
    }
    return result;
}

long long inv(long long a, long long m) {
    if (a == 1) return 1;
    return (1 - inv(m % a, a) * m) / a + m;
}

int main() {
    int n, e, c, p = 0, q = 0;
    cin >> n >> e >> c;
    if (n % 2 != 0 && n % 3 != 0) {
        for (int i = 1; i <= ceil(sqrt(n) / 6); i++) {
            if (n % (6 * i - 1) == 0) {
                p = (6 * i - 1);
                q = n / p;
            } else if (n % (6 * i + 1) == 0) {
                p = (6 * i + 1);
                q = n / p;
            }
        }
    } else if (n % 3 == 0) {
        p = 3;
        q = n / 3;
    } else {
        p = 2;
        q = n / 2;
    }
    int phi = (p - 1) * (q - 1);
    int d = inv(e, phi);
    while (d < 0) d += phi;
    while (d > phi) d -= phi;
    cout << fast_pow(c, d, n);
}