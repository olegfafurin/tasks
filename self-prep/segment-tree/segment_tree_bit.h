#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template<typename T>
class SegmentTree {
    
    vector<T> data;
    size_t s;

    T prefSum(size_t r) {
        T rs = T();
        size_t i = s + r;
        rs += data[i];
        while (i > 1) {
            if (i % 2 == 1) {
                rs += data[i - 1];
            }
            i /= 2;
        }
        return rs;
    }

public:

    SegmentTree(int n) {
        size_t s = 1;
        while (s < n) {
            s <<= 1;
        }
        data = vector<T>(2 * s);
        this->s = s;
    }

    SegmentTree(vector<T> v) {
        const size_t n = v.size();
        size_t s = 1;
        while (s < n) {
            s <<= 1;
        }
        data = vector<T>(2 * s);
        this->s = s;
        copy(v.begin(), v.end(), data.begin() + s);
        for (size_t i = s - 1; i >= 1; --i) {
            data[i] = data[2 * i] + data[2 * i + 1];
        }

    }

    T sum(size_t l, size_t r) {
        return prefSum(r) - (l == 0 ? 0 : prefSum(l - 1));
    }


    vector<T> getAll() {
        vector<T> v(data.begin() + s, data.end());
        return v;
    }

    void update(int index, int val) {
        size_t ind = s + index;
        T delta = val - data[ind];
        while (ind > 0) {
            data[ind] += delta;
            ind /= 2;
        }
    }

};


