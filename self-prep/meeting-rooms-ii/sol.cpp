#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end): start(start), end(end) {}
};

int minMeetingRooms(vector<Interval>& intervals) {
    map<int, int> minus;
    std::sort(intervals.begin(), intervals.end(), [] (const auto& lhs, const auto& rhs) -> bool {
        return lhs.start < rhs.start || lhs.start == rhs.start && lhs.end < rhs.end;
    });

    int cnt = 0;
    int cntMax = 0;
    for (const auto& [l, r]: intervals) {
        while (!minus.empty() && (*minus.begin()).first <= l) {
            cnt -= (*minus.begin()).second;
            minus.erase(minus.begin());
        }
        ++cnt;
        cntMax = max(cntMax, cnt);
        if (!minus.contains(r)) {
            minus[r] = 1;
        } else {
            ++minus[r];
        }
    }
    return cntMax;
}

int main() {
    int n;
    cin >> n;
    vector<Interval> v;
    for (int i = 0; i < n; ++ i) {
        int l, r;
        cin >> l >> r;
        v.emplace_back(l, r);
    }
    cout << minMeetingRooms(v) << '\n';
}
