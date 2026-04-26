#include <vector>
#include "quicksort.h"

using namespace std;

vector<int> sort(const vector<int> &a) {
    vector<int> data(a);
    quicksort(data, 0, data.size());
    return data;
}

void quicksort(vector<int> &a, int l, int r) {
    if (l + 1 >= r) return;
    int mid = partition(a, l, r);
    quicksort(a, l, mid);
    quicksort(a, mid + 1, r);
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
