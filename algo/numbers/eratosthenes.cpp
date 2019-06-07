//
// Created by imd on 02/06/2019.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;

int main() {
//    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
    vector<int> is_prime = vector<int>(1'000'001, 1);
    is_prime[1] = 0;
    long long i = 2;
    while (i <= 1'000'000) {
        if (is_prime[i] == 1) {
            is_prime[i] = i;
            for (long long j = i*i; j <= 1'000'000; j += i) {
                if (is_prime[j] == 1) is_prime[j] = i;
            }
        }
        i++;
    }
//    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
//    int elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
//    cout << elapsed << " ms elapsed\n";
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        while (k != 1) {
            cout << is_prime[k] << ' ';
            k /= is_prime[k];
        }
        cout << '\n';
    }

    ofstream fout ("primes.out");
    for (int i = 0; i < 100000; i++)
        if (is_prime[i] == i) fout << i << '\n';
}
