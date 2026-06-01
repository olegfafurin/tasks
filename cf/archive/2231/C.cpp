#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
#include <utility>
#include <functional>

using namespace std;

int main() {
    int testK;
    cin >> testK;
    while (testK--) {
        int n;
        cin >> n;
        unordered_map<int, int> cnt;
        int nMax = 0, nMin = 1e9 + 1;
        set<pair<int,int>, greater<pair<int,int>>> q;
        for (int i = 0; i < n; ++i) {
            int v;
            cin >> v;
            ++cnt[v];
            if (v > nMax) {
                nMax = v;
            }
            if (v < nMin) {
                nMin = v;
            }
        }
        for (auto &p: cnt) {
            q.insert(p);
        }
        int opCnt = 0;
        while (true) {
            int nMax = q.begin()->first;
            int nMaxCnt = q.begin()->second;
            int nMin = q.rbegin()->first;
            int nMinCnt = q.rbegin()->second;
            if (nMax == nMin) {
                cout << opCnt << '\n';
                break;
            } else if (nMin == 1 && nMax == 2) {
                opCnt += min(nMinCnt, nMaxCnt);
                cout << opCnt << '\n';
                break;
            } else if (nMin + 1 == nMax && nMin % 2 == 1) {
                opCnt += nMinCnt;
                cout << opCnt << '\n';
                break;
            }
            int deltaOp = nMax % 2 == 0 ? nMaxCnt : (2 * nMaxCnt);
            opCnt += deltaOp;
            int newNumber = (nMax + 1) / 2;
            q.erase(q.begin());
            auto it = q.lower_bound({newNumber, 100'000});
            if (it != q.end() && it->first == newNumber) {
                int newCnt = it->second + nMaxCnt;
                q.erase(it);
                q.insert({newNumber, newCnt});
            } else {
                q.insert({newNumber, nMaxCnt});
            }
        }
    }
}
