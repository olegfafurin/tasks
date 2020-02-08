//
// Created by imd on 10/14/2019.
//

#include <vector>
#include <iostream>

using namespace std;

int a, b, c, d;

void rotate(vector<vector<int>> &A) {
    int n = A.size();
    for (int i = 0; i < (double)(n - 1) / 2; ++i) {
        for (int j = i; j < n - i - 1; j++) {
            a = A[i][j];
            b = A[j][n - 1 - i];
            c = A[n - 1 - i][n - 1 - j];
            d = A[n - 1 - j][i];
            A[i][j] = d;
            A[j][n - 1 - i] = a;
            A[n - 1 - i][n - 1 - j] = b;
            A[n - 1 - j][i] = c;
        }
    }
}

int main() {
    auto v = vector<vector<int>>({});
    rotate(v);
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 1; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}