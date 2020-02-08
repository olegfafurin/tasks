//
// Created by imd on 10/9/2019.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    int curmax = 0;
    int csum = 0;
    int rain = 0;
    for (int i = 1; i < n; i++) {
        if (height[i] > height[curmax]) {
            int l = i - curmax - 1;
            rain += l * height[curmax] - csum;
            csum = 0;
            curmax = i;
        }
        else csum += height[i];
    }
    curmax = n - 1;
    csum = 0;
    for (int i = n - 2; i >= 0 ; i--) {
        if (height[i] >= height[curmax]) {
            int l = curmax - i - 1;
            rain += l * height[curmax] - csum;
            csum = 0;
            curmax = i;
        }
        else csum += height[i];
    }
    return rain;
}

int main() {
    auto v = vector<int>({2,1,0,2,1,0,1,3,2,3,2,1});
    cout << trap(v);
}