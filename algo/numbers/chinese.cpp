//
// Created by imd on 02/06/2019.
//


#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;


long long inv(long long a, long long m) {
    if (a == 1) return 1;
    return (1 - inv(m % a, a) * m) / a + m;
}

long long process(long long a, long long b, long long n, long long m) {
    long long x1 = (m * inv(m, n)) % (m * n);
    long long x2 = (n * inv(n, m)) % (m * n);
    long long temp = (x1 * a + x2 * b) % (m * n);
    while (temp < 0) temp += m * n;
    while (temp >= m * n) temp -= m * n;
    return temp;
}

int main() {
    long long num, a, b, n, m;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cin >> a >> b >> n >> m;
        long long res = process(a, b, n, m);
        if (res >= n * m)
            cout << "ERROR" << a << ' ' << b << ' ' << res << '\n';
        if ((res - a) % n != 0)
            cout << "ERROR" << a << ' ' << b << ' ' << res << '\n';
        if ((res - b) % m != 0)
            cout << "ERROR" << a << ' ' << b << ' ' << res << '\n';

        cout << res << '\n';
    }
}