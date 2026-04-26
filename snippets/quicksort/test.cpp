#include <vector>
#include <iostream>
#include <stdexcept>
#include "quicksort.h"


using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> res = sort(a);
    if (res.size() != n) {
        throw range_error("Output size is not equal to input size");
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';
}