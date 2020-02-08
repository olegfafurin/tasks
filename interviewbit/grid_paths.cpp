//
// Created by imd on 10/15/2019.
//


#include <vector>
#include <iostream>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &A) {
    int m = A.size();
    if (m == 0) return 0;
    int n = A[0].size();
    vector<vector<int>> p = vector<vector<int>>(m, vector<int>(n));
    p[0][0] = 1;
    for (int t = 1; t < n + m - 1; t++) {
        for (int i = 0; i <= t; i++) {
            if (i < m && t - i < n && A[i][t - i] != 1) {
                if (i - 1 < m && i - 1 >= 0 && A[i - 1][t - i] != 1) p[i][t - i] += p[i - 1][t - i];
                if (t - i - 1< n && t - i - 1>= 0 && A[i][t - i - 1] != 1) p[i][t - i] += p[i][t -  i - 1];
            }
        }
    }
    return p[m - 1][n - 1];
}


int main() {
    auto v = vector<vector<int>>({{0, 0, 1, 0,0,0},
                                  {0, 0, 0, 0, 1 ,0}});
    cout << uniquePathsWithObstacles(v);
}