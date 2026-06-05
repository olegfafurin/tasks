#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;


long long prefixWaviness(long long rb) {
    if (rb < 100) {
        return 0;
    }

    long long lhs = 0;    

    vector<int> digits;
    while (rb > 0) {
        digits.push_back(rb % 10);
        rb /= 10;
    }
    reverse(digits.begin(), digits.end());
    
    int n = digits.size();

    long long mult = 1;
    long long rhs = 0;
    for (int i = 0; i < n - 3; ++i) {
        mult *= 10;
        rhs *= 10;
        rhs += digits[i + 3];
    }
    

    long long cnt = 0;
    for (int ind = 1; ind <= n - 2; ++ind) {
        int iRef = digits[ind - 1], jRef = digits[ind], kRef = digits[ind + 1];
        int ref = 100 * iRef + 10 * jRef + kRef;
        for (int num = 0; num < 1000; ++num) {
            int i = num / 100, j = (num % 100) / 10, k = num % 10;
            if (i > j && j < k || i < j && j > k) {
                if (num < ref) {
                    cnt += lhs * mult;
                    if (i > 0) {
                        cnt += mult;
                    }
                } else if (num == ref) {
                    cnt += max(lhs - 1, 0ll) * mult + rhs + 1;
                    if (i > 0 && lhs > 0) {
                        cnt += mult;
                    }
                } else if (num > ref) {
                    cnt += max(lhs - 1, 0ll) * mult;
                    if (i > 0 && lhs > 0) {
                        cnt += mult;
                    }
                }
            }
        }
        
        mult /= 10;
        if (mult > 1) {
            rhs %= mult;
        } else {
            rhs = 0;
        }
        lhs *= 10;
        lhs += iRef;
    }
    return cnt;
}

long long totalWaviness(long long num1, long long num2) {
    return prefixWaviness(num2) - prefixWaviness(num1 - 1);
}


int main() {
   long long l, r;
   cin >> l >> r;
   cout << totalWaviness(l, r) << '\n';
}
