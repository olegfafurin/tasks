#include <vector>
#include <iostream>

using namespace std;

template <typename T>

class FenwickTree {

    vector<T> data;

    int n;

    T prefSum(int i) {
        T rs = T();
        while (i >= 0) {
            rs += data[i];
            i = (i & i + 1) - 1;
        }
        return rs;
    }

    public:
    
    FenwickTree(int n): n(n), data(n) {}

    FenwickTree(vector<int> v): FenwickTree(v.size()) {
        for (size_t i = 0; i < n; ++i) {
            add(i, v[i]);
        }
    }
    

    T sum(size_t l, size_t r) {
        return prefSum(r) - prefSum(l - 1);
    }

    void set(size_t i, T val) {
        T delta = val - data[i];
        add(i, delta);
    }

    void add(size_t i, T val) {
        while (i < n) {
            data[i] += val;
            i = i | (i + 1);
        }
    }
};
