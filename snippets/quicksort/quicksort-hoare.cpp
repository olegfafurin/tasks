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
    quicksort(a, mid, r);
}

int partition(vector<int> &a, int l, int r) {
    int i = l;
    int j = r - 1;
    int pivot = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] < pivot) {
            ++i;
        }
        while (a[j] > pivot) {
            --j;
        }
        if (i >= j) {
            break;
        }
        swap(a[i++], a[j--]);
    }
    return i;
}
