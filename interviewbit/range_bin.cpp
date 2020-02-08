//
// Created by imd on 10/23/2019.
//


#include <vector>
#include <iostream>

using namespace std;

vector<int> searchRange(const vector<int> &A, int B) {
    if (A.empty()) return vector<int>({-1, -1});
    int l = 0;
    int r = A.size() - 1;
    int lb, rb;
    if (A[r] < B || A[l] > B) return vector<int>({-1, -1});
    if (A[l] == B) lb = 0;
    else {
        while(r - l > 1) {
            int mid = (l + r) / 2;
            if (A[mid] >= B) r = mid;
            else l = mid;
        }
        lb = r;
    }
    l = 0;
    r = A.size() - 1;
    if (A[r] == B) rb = A.size();
    else {
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (A[mid] > B) r = mid;
            else l = mid;
        }
        rb = r;
    }
    if (lb >= rb) return vector<int>({-1, -1});
    return vector<int>({lb, rb - 1});
}

int main() {
    auto v = vector<int>({1,2,3,3,4});
    for (auto c : searchRange(v, 3)) {
        cout << c << ' ';
    }
}