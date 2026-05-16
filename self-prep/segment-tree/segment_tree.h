#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template<typename T>
class SegmentTree {
    
    vector<T> data;
    size_t s;

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
        T rs = 0;
        ++r;

        function<void(size_t, size_t, size_t)> dfs = [&] (size_t i, size_t lb, size_t rb) -> void {
            if (l >= r || lb >= rb || l >= rb || r <= lb) {
                return;
            }
            if (l == lb && r >= rb) {
                rs += data[i];
                l = rb;
                return;
            }
            if (rb > lb + 1) {
                size_t mid = (lb + rb) / 2;
                dfs(2 * i, lb, mid);
                dfs(2 * i + 1, mid, rb);
            }
        };

        dfs(1, 0, s);
        return rs;
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


