#include <vector>
#include <utility>
#include <climits>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;


class Heap {
    
    vector<pair<int, size_t>> data; // (value, opId)
    unordered_map<size_t, size_t> op; // (opId -> idx in data)

    void siftUp(size_t i) {
        while (i > 1) {
            if (data[i >> 1].first > data[i].first) {
                exchange(i >> 1, i);
            }
            i >>= 1;
        }
    }

    void siftDown(size_t i) {
        while (i << 1 < data.size()) {
            size_t nxt = i;
            int minValue = data[i].first;
            if (data[i << 1].first < data[i].first) {
                nxt = i << 1;
                minValue = data[i << 1].first;
            }
            if ((i << 1 | 1) < data.size() && data[i << 1 | 1].first < minValue) {
                nxt = i << 1 | 1;
                // minValue = data[i << 1 | 1].first;
            }
            if (nxt == i) {
                return;
            }
            exchange(i, nxt);
            i = nxt;
        }
    }

    void exchange(size_t i, size_t j) {
        size_t opIdI = data[i].second;
        size_t opIdJ = data[j].second;
        swap(op[opIdI], op[opIdJ]);
        swap(data[i], data[j]);
    }

public:
    
    Heap() {
        data.push_back({0,0});
    }

    void push(int x, size_t opId) {
        size_t i = data.size();
        op[opId] = i;
        data.push_back({x, opId});
        siftUp(i);
    }

    void decreaseKey(size_t opId, int newValue) {
        if (!op.contains(opId)) {
            return;
        }
        size_t i = op[opId];
        data[i] = {newValue, opId};
        siftUp(i);
    }

    pair<int, size_t> extractMin() {
        exchange(1, data.size() - 1);
        auto p = data[data.size() - 1];
        op.erase(data[data.size() - 1].second);
        data.pop_back();
        siftDown(1);
        return p;
    }

    bool isEmpty() {
        return data.size() == 1;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Heap heap;
    string cmd;
    int opCnt = 0;
    while (cin >> cmd) {
        opCnt++;
        if (cmd == "push") {
            int value;
            cin >> value;
            heap.push(value, opCnt);
        } else if (cmd == "extract-min") {
            if (heap.isEmpty()) {
                cout << '*' << '\n';
            } else {
                auto [value, opId] = heap.extractMin();
                cout << value << ' ' << opId << '\n';
            }
        } else if (cmd == "decrease-key") {
            size_t opId;
            int newValue;
            cin >> opId >> newValue;
            heap.decreaseKey(opId, newValue);
        }
    }
}
