#include <vector>
#include <iostream>

using namespace std;

bool check() {
    int n;
    cin >> n;
    bool valid = true;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        s += d;
        if (d == 0 && n > 1) {
            valid = false;
        }
    }
    return valid && s == 2 * (n - 1);
}

int main() {
    int t;
    cin >> t;

    for (int tn = 0; tn < t; ++tn) {
        cout << (check() ? "YES\n" : "NO\n");
    }
}
