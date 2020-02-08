//
// Created by imd on 10/14/2019.
//

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int maxSpecialProduct(vector<int> &A) {
    stack<int> s = stack<int>();
    int n = A.size();
    vector<int> lspec = vector<int>(n);
    vector<int> rspec = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && A[s.top()] <= A[i]) s.pop();
        if (s.empty()) lspec[i] = 0;
        else lspec[i] = s.top();
        s.push(i);
    }
    s = stack<int>();
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && A[s.top()] <= A[i]) s.pop();
        if (s.empty()) rspec[i] = 0;
        else rspec[i] = s.top();
        s.push(i);
    }
    int c = 0;
    for (int i = 0; i < n; ++i) c = max(c, lspec[i] * rspec[i]);
    return c;
}

int main() {
    auto v = vector<int>({5, 3, 1,2, 3,4});
    cout << maxSpecialProduct(v);
}