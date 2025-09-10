#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
	int m = languages.size();
	set<int> to_cover;
    vector<set<int>> lang;
    lang.reserve(languages.size());
    for (auto &l: languages) {
    	lang.emplace_back(l.begin(), l.end());
    }
    for (auto &vec: friendships) {
    	int u = vec[0], v = vec[1];
    	set<int> common_lang;
    	set_intersection(lang[u-1].begin(), lang[u-1].end(), lang[v-1].begin(), lang[v-1].end(), inserter(common_lang, common_lang.begin()));
    	if (common_lang.size() == 0) {
    		to_cover.insert(u - 1);
    		to_cover.insert(v - 1);
    	}
    }

    vector<int> to_teach(n, to_cover.size());

    for (int v: to_cover) {
    	for (auto &l: lang[v]) {
    		to_teach[l-1]--;
    	}
    }



    int min_teach = m;
    for (int i = 0; i < n; ++i) {
    	if (min_teach > to_teach[i]) {
    		min_teach = to_teach[i];
    	}
    }
    return min_teach;
}

// int main() {
// 	int n = 3;
// 	vector<vector<int>> languages {{2}, {1,3}, {1,2}, {3}};
// 	vector<vector<int>> friendships {{1,4}, {1,2}, {3,4}};

// 	cout << minimumTeachings(n, languages, friendships) << '\n';
// }