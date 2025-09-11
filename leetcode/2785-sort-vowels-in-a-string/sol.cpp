#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;


string sortVowels(string s) {
    set<char> vowels {'a','o','i','u','e','A','O','I','U','E'};
    int n = s.size();
    string v;

    for (int i = 0; i < n; ++i) {
        if (vowels.contains(s[i])) {
            v += s[i];
        }
    }
    sort(v.begin(), v.end());

    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (vowels.contains(s[i])) {
            s[i] = v[j++];
        }
    }
    return s;
}

// int main() {
//     string s;
//     cin >> s;
//     cout << sortVowels(s) << '\n';
// }