//
// Created by imd on 10/13/2019.
//


#include <vector>
#include <iostream>

using namespace std;

const static int MOD = 1000000007;

struct matrix;

matrix unit(int n);

struct matrix {
    vector<vector<long long>> table;

//    explicit matrix(vector<vector<long long>> &&table) {
//        table = move(table);
//    }

    explicit matrix(vector<vector<long long>> table) {
        this->table = move(table);
    }

    matrix operator*(const matrix &other) {
        int n = table.size();
        int m = table[0].size();
        int l = table[0].size();
        auto product = vector<vector<long long>>(n, vector<long long>(l));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < l; j++) {
                for (int k = 0; k < m; ++k) {
                    product[i][j] += table[i][k] * other.table[k][j];
                }
                product[i][j] %= MOD;
            }
        }
        matrix result = matrix(product);
        return matrix(product);
    }
};

matrix unit(int n) {
    matrix res = matrix(vector<vector<long long>>());
    for (int i = 0; i < n; ++i) {
        auto currrent_line = vector<long long>(n);
        currrent_line[i] = 1;
        res.table.push_back(currrent_line);
    }
    return res;
}

matrix power(matrix &m, int n) {
    auto init = matrix(m.table);
    auto res = unit(5);
    while (n) {
        if (n & 1) res = res * init;
        init = init * init;
        n /= 2;
    }
    return res;
}

int countVowelPermutation(int n) {
    auto rule = vector<vector<long long>>({{0, 1, 0, 0, 0},
                                           {1, 0, 1, 0, 0},
                                           {1, 1, 0, 1, 1},
                                           {0, 0, 1, 0, 1},
                                           {1, 0, 0, 0, 0}});
    matrix m = matrix(rule);
    matrix t = power(m, n - 1);
    long long res = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; ++j) {
            res += t.table[i][j];
        }
    }
    res %= MOD;
    return res;
}

int main() {
    cout << countVowelPermutation(1);
}