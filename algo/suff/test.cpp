//
// Created by imd on 17/05/2019.
//

#include <iostream>
#include <set>

using namespace std;

int main() {
    int n = 50000;
    set<int> s = set<int>();
    for (int i = 0; i < n; ++i) {
        s.insert(i);
    }
    cout << *s.begin() << ' ' << *s.rbegin() << ' ';
}