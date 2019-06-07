//
// Created by imd on 02/06/2019.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <cmath>
#include <chrono>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int32_t n, x;
    cin >> n >> x;
    int32_t hash = 0;
//    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();

    const int BLOCK_SIZE = 202'623;

    vector<bool> is_prime = vector<bool>(BLOCK_SIZE, true);
    is_prime[0] = false;
    is_prime[1] = false;
    vector<int> primes = vector<int>();
    for (long long i = 2; i <= sqrt(BLOCK_SIZE) + 1; i += 1) {
        if (is_prime[i]) {
            for (long long j = i * i; j <= BLOCK_SIZE; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < min(BLOCK_SIZE, n + 1); ++i) {
        if (is_prime[i]) {
            hash = hash * x + i;
            primes.push_back(i);
        }
    }
    vector<bool> block_primes = vector<bool>(BLOCK_SIZE, true);
    for (long long block_number = 2; (block_number - 1) * BLOCK_SIZE <= n; block_number++) {
        block_primes = vector<bool>(BLOCK_SIZE, true);
        for (int j = 0; j < primes.size(); j++) {
            int p = primes[j];
            if (p > sqrt(block_number * BLOCK_SIZE)) continue;
            if (((block_number - 1) * BLOCK_SIZE) % p == 0) block_primes[0] = false;
            int start = ((int) (((block_number - 1) * BLOCK_SIZE) / p) + 1) * p;
            while (start < block_number * BLOCK_SIZE) {
                block_primes[start % BLOCK_SIZE] = false;
                start = start + p;
            }
        }
        for (int i = 0; i < BLOCK_SIZE; ++i) {
            if (block_primes[i]) {
                if ((block_number - 1) * BLOCK_SIZE + i > n) break;
                hash = hash * x + (block_number - 1) * BLOCK_SIZE + i;
            }
        }
    }

    cout << hash << '\n';

//    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
//    int elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
//    cout << elapsed << " ms elapsed\n";

}
