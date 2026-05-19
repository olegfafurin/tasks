#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;


int lisLength(const vector<int> &v) {
    vector<int> lis;
    const int n = v.size();
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(lis.begin(), lis.end(), v[i]);
        if (it == lis.end()) {
            lis.push_back(v[i]);
        } else if (*it > v[i]) {
            *it = v[i];
        }
    }
    return lis.size();
}

vector<int> lis(const vector<int> &v) {
    const int n = v.size();
    vector<int> lis(n + 1, numeric_limits<int>::max());
    lis[0] = numeric_limits<int>::min();
    vector<int> p(n + 1);
    vector<int> ind(n + 1);
    ind[0] = -1;
    int lisSize = 0;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(lis.begin(), lis.end(), v[i]);
        int j = it - lis.begin();
        if (lis[j] > v[i]) {
            lis[j] = v[i];
            ind[j] = i;
            p[i] = ind[j - 1];
            lisSize = max(lisSize, j);
        }
    }
    vector<int> lisSeq(lisSize);
    int x = ind[lisSize];
    for (int i = lisSize - 1; i >= 0; --i) {
        lisSeq[i] = v[x];
        x = p[x];
    }
    return lisSeq;
}

