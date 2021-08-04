//
// Created by Oleg.Fafurin on 03.08.2021.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int maxArea(vector<int> &height) {
    size_t n = height.size();
    if (n == 0)
        return 0;
    vector<pair<int, int>> info(n);
    for (size_t i = 0; i < height.size(); ++i) {
        info[i] = {height[i], i};
    }
    sort(info.begin(), info.end(),
         [](auto lhs, auto rhs) { return lhs.first > rhs.first || lhs.first == rhs.first && lhs.second > rhs.second; });
    vector<int> max_on_prefix(n), min_on_prefix(n);
    int cur_max = 0;
    max_on_prefix[0] = info[0].second;
    min_on_prefix[0] = info[0].second;
    for (size_t i = 1; i < n; ++i) {
        max_on_prefix[i] = max(max_on_prefix[i - 1], info[i].second);
        min_on_prefix[i] = min(min_on_prefix[i - 1], info[i].second);
    }
    for (size_t i = 0; i < n; ++i) {
        int candidate = max(info[i].second - min_on_prefix[i], max_on_prefix[i] - info[i].second) * info[i].first;
        if (candidate > cur_max)
            cur_max = candidate;
    }
    return cur_max;
}

int main() {
    vector<int> v{};
    cout << maxArea(v);
}

