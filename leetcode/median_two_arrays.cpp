//
// Created by imd on 10/8/2019.
//

#include <vector>
#include <iostream>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size()) swap(nums1, nums2);
    int n = nums1.size();
    int m = nums2.size();
    int l1 = 0;
    int r1 = n - 1;
    int t = (m + n) / 2 - 1;
    int mid;
    if (n == 0) {
        if (m % 2 == 0) return (double)(nums2[m / 2] + nums2[m / 2 - 1]) / 2;
        else return nums2[m / 2];
    }
    double acc;
    if (nums1[0] > nums2[t]) {
        if (t + 1 < m) acc = min(nums1[0], nums2[t + 1]);
        else acc = nums1[0];
        if ((n + m) % 2 == 0) return (acc + nums2[t]) / 2;
        else return acc;
    } else if (nums1[r1] <= nums2[t - r1]) {
        if (t - r1 > 0) acc = max(nums1[r1], nums2[t - r1 - 1]);
        else acc = nums1[r1];
        if ((n + m) % 2 == 0) return (acc + nums2[t - r1]) / 2;
        else return nums2[t - r1];
    }
    while (r1 - l1 > 1) {
        mid = (r1 + l1) / 2;
        if (nums1[mid] <= nums2[t - mid]) l1 = mid;
        else r1 = mid;
    }
    if ((n + m) % 2 == 0) {
//        cout << nums1[l1] << " <= " << nums2[t - l1] << '\n';
//        cout << nums1[l1 + 1] << " > " << nums2[t - l1 - 1] << '\n';
        return ((double) max(nums1[l1], nums2[t - l1 - 1]) + min(nums1[l1 + 1], nums2[t - l1])) / 2;
    } else return min(nums1[l1 + 1], nums2[t - l1]);
}

int main() {
    vector<int> v1({10, 11});
    vector<int> v2({11, 23});
    cout << findMedianSortedArrays(v1, v2) << '\n';
    int a = 3;
    int b = 5;
}