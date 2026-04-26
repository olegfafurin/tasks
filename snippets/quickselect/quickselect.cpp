#include <vector>
#include "quickselect.h"

using namespace std;

int getKth(const std::vector<int>& a, int k) {
    vector<int> data(a);
    int l = 0;
    int r = data.size();
    while (true) {
        if (r - l == 1) {
            return data[l];
        }
        int pivotIndex = partition(data, l, r);
        if (pivotIndex == k - 1) {
            return data[k - 1];
        } else if (pivotIndex < k - 1) {
            l = pivotIndex + 1;
        } else {
            r = pivotIndex;
        }
    }           
}
  
int partition(vector<int> &a, int l, int r) {
    int mid = (l + r) / 2;
    swap(a[mid], a[r - 1]);
    int pivot = a[r - 1];
    int i = 0;
    for (int j = 0; j < r - 1; ++j) {
        if (a[j] <= pivot) {
            swap(a[i++], a[j]);
        }
    }
    swap(a[i], a[r - 1]);
    return i;
}