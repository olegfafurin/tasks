//
// Created by imd on 10/15/2019.
//

#include <vector>
#include <iostream>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int num_div(int n) {
    int k = n;
    vector<int> div = vector<int>(n + 1);
    for (int p = 2; p <= n; p++) {
        while (n % p == 0) {
            div[p]++;
            n /= p;
        }
        if (n == 1) break;
    }
    if (n != 1) return 2;
    int m = 1;
    for (int i = 0; i <= k; ++i) {
        if (div[i] != 0) m *= (div[i] + 1);
    }
    return m;
}

int powmod(int a, int n) {
    if (n == 0) return 1;
    long long cur = 1;
    long long base = a;
    while(n) {
        if (n & 1) cur = (cur * base) % 1000000007;
        base = (base * base) % 1000000007;
        n /= 2;
    }
    return cur;
}

vector<int> solve(vector<int> &A, vector<int> &B) {
    stack<int> s = stack<int>();
    int n = A.size();
    map<int, int> cnt = map<int, int>();
    vector<long long> lspec = vector<long long>(n);
    vector<long long> rspec = vector<long long>(n);
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && A[s.top()] <= A[i]) s.pop();
        if (s.empty()) lspec[i] = -1;
        else lspec[i] = s.top();
        s.push(i);
    }
    s = stack<int>();
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && A[s.top()] < A[i]) s.pop();
        if (s.empty()) rspec[i] = n;
        else rspec[i] = s.top();
        s.push(i);
    }
    for (int i = 0; i < n; ++i) {
        if (cnt.count(A[i]) == 0) cnt[A[i]] = (i - lspec[i]) * (rspec[i] - i);
        else cnt[A[i]] += (i - lspec[i]) * (rspec[i] - i);
//        cout << cnt[A[i]] << ' ';
    }
    int checks = 0;
    for (auto val : cnt) checks += val.second;
//    cout << "Sum is " << checks << '\n';
    map<int, int> corr = map<int, int>();
    for (int i = 0; i < n; ++i) {
        if (corr.count(A[i]) != 0) {
            continue;
        }
        int d = num_div(A[i]);
        if (d % 2 == 0) corr[A[i]] = powmod(A[i], d/2);
        else corr[A[i]] = powmod(sqrt(A[i]), d);
//        cout << A[i] << ": " << corr[A[i]] << '\n';
    }
    sort(A.begin(), A.end(), [&corr](const int x, const int y) -> bool {
        return corr[x] > corr[y];
    });
    vector<long long> cumsum = vector<long long>();
    auto mark = set<int>();
    auto chunks = vector<int>();
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (mark.count(A[i]) == 1) continue;
        cumsum.emplace_back(cur + cnt[A[i]]);
        mark.insert(A[i]);
        chunks.emplace_back(corr[A[i]]);
        cur = cur + cnt[A[i]];
    }
    cumsum.emplace_back(1000000000000000000);
    vector<int> ans = vector<int>();
    for (int i = 0; i < B.size(); i++) {
        if (B[i] - 1 < cumsum[0]) ans.emplace_back(corr[A[0]]);
        else {
            int l = 0;
            int r = cumsum.size() - 1;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (B[i] - 1 < cumsum[mid]) r = mid;
                else l = mid;
            }
            ans.emplace_back(chunks[r]);
        }
    }
   return ans;
}

int main() {
    auto v = vector<int>({39, 99, 70, 24, 49, 13, 86, 43, 88, 74, 45, 92, 72, 71, 90, 32, 19, 76, 84, 46, 63, 15, 87, 1, 39, 58, 17, 65, 99, 43, 83, 29, 64, 67, 100, 14, 17, 100, 81, 26, 45, 40, 95, 94, 86, 2, 89, 57, 52, 91, 45});
    auto q = vector<int>({1221, 360, 459, 651, 958, 584, 345, 181, 536, 116, 1310, 403, 669, 1044, 1281, 711, 222, 280, 1255, 257, 811, 409, 698, 74, 838});
    auto v = vector<int>({2,2,2,2,5,5,7,10});
    auto q = vector<int>({36});
    auto ans = solve(v,q);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
}