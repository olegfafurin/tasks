#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


double getMedian(vector<int> &data) {
    const size_t n = data.size();
    assert(n > 0);
    size_t i = n / 2;
    auto mid = data.begin() + i;
    nth_element(data.begin(), mid, data.end());
    if (n % 2 == 1) {
        return static_cast<double>(*mid);
    }
    int rhs = *mid;
    auto left_mid = data.begin() + i - 1;
    nth_element(data.begin(), left_mid, mid);
    int lhs = *left_mid;
    return (0.5 * (rhs - lhs)) + lhs;
}


void optimize(const vector<int>& lhs, vector<int>& rhs) {
    const int n = lhs.size();
    assert(n == rhs.size());

    vector<int> diff(n);
    for (int i = 0; i < n; ++i) {
        diff[i] = lhs[i] - rhs[i];
    }
    double shift = getMedian(diff);
    for (auto &x: rhs) {
        x += shift;
    }
}
