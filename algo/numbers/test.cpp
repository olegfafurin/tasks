//
// Created by imd on 02/06/2019.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;

long long inv(long long a, long long m) {
    if (a == 1) return 1;
    return (1 - inv(m % a, a) * m) / a + m;
}

long long gcd(long long a, long long b) {
    while (b) {
        a = a % b;
        a = a + b;
        b = a - b;
        a = a - b;
    }
    return a;
}

int main() {

    for (int i = 0; i < 20; i++) {
        cout << i << ' ' << i / 10 << '\n';
    }
}