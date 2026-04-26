#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>

std::vector<int> sort(const std::vector<int>& a);

int partition(std::vector<int> &a, int l, int r);

void quicksort(std::vector<int> &a, int l, int r);
#endif // QUICKSORT_H
