#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


double largestTriangleArea(vector<vector<int>>& points) {
    int n = points.size();
    int max_area_d = 0;
    for (int i = 0; i < n - 2; ++i) {
    	int x_i = points[i][0], y_i = points[i][1];
    	for (int j = i + 1; j < n - 1; ++j) {
    		int x_j = points[j][0], y_j = points[j][1];
    		int x1 = x_j - x_i, y1 = y_j - y_i;
    		for (int k = j + 1; k < n; ++k) {
    			int x2 = points[k][0] - x_i, y2 = points[k][1] - y_i;
    			int area_doubled = abs(x1 * y2 - x2 * y1);
    			cout << area_doubled << '\n';
    			if (area_doubled > max_area_d) {
    				cout << "pass\n";
    				max_area_d = area_doubled;
    			}
    		}
    	}
    }
    return static_cast<double>(max_area_d) / 2;
}


int main(int argc, char const *argv[]) {
	vector<vector<int>> v = {{0,0},{0,1}};
	cout << largestTriangleArea(v) << '\n';
	return 0;
}   