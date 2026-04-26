#include <vector>
#include <iostream>
#include <stdexcept>
#include "quickselect.h"


using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = getKth(a, k);
    cout << res;
    cout << '\n';
}