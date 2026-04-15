#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        for (int i = 0; i <= n / 2; ++i) {
            if (words[(startIndex + i) % n] == target || words[(startIndex - i + n) % n] == target) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> v;
    v.reserve(n);
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    string target;
    int startIndex;
    cin >> target;
    cin >> startIndex;

    Solution sol;
    cout << sol.closestTarget(v, target, startIndex) << '\n';
}