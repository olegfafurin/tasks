//
// Created by Oleg.Fafurin on 04.08.2021.
//


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    if (matrix.empty())
        return 0;
    auto similar = [](vector<int> &lhs, vector<int> &rhs) -> bool {
        if (lhs.size() != rhs.size())
            return false;
        if (lhs.empty())
            return true;
        bool diff = lhs[0] != rhs[0];
        for (int i = 0; i < lhs.size(); ++i) {
            if ((lhs[i] != rhs[i]) ^ diff)
                return false;
        }
        return true;
    };
    vector<int> group_size;
    vector<int> group;
    int group_count = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        bool found = false;
        for (int j = 0; j < i; ++j) {
            if (similar(matrix[i], matrix[j])) {
                group.push_back(group[j]);
                group_size[group[i]] += 1;
                found = true;
                break;
            }
        }
        if (!found) {
            group.push_back(group_count++);
            group_size.push_back(1);
        }
    }
    return *max_element(group_size.begin(), group_size.end());
}

int main() {
    vector<int> v{1};
    vector<int> u{0, 0, 0};
    vector<int> w{0, 0, 0};
    vector<vector<int>> m{v};
    cout << maxEqualRowsAfterFlips(m) << endl;
}
