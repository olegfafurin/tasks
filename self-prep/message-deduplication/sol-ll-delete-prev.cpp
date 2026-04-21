#include <vector>
#include <iostream>
#include <list>
#include <iterator>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Message {
    int time;
    string value;
};

std::ostream &operator<<(std::ostream &os, const Message &msg) {
    os << "{" << msg.value << ", " << msg.time << "}";
    return os;
}


vector<Message> process(const vector<Message> &input, int delay) {
    list<Message> cache;
    unordered_map<string, list<Message>::iterator> hm;

    vector<Message> output;

    for (const auto &msg: input) {
        if (!hm.contains(msg.value) || hm[msg.value]->time < msg.time - delay) {
            auto it = cache.insert(cache.end(), msg);
            hm[msg.value] = it;
        } else if (hm.contains(msg.value)) {
            cache.erase(hm[msg.value]);
            hm.erase(msg.value);
        }

        auto oldEnd = find_if(cache.begin(), cache.end(), [&msg, delay](const Message &m) {
            return m.time >= msg.time - delay;
        });
        for_each(cache.begin(), oldEnd, [&hm, &output](const Message &m) {
            output.push_back(m);
            hm.erase(m.value);
        });
        cache.erase(cache.begin(), oldEnd);

        cout << "LL cache: ";
        for (auto it = cache.begin(); it != cache.end(); ++it) {
            cout << *it << ' ';
        }
        cout << '\n';
    }

    for_each(cache.begin(), cache.end(), [&hm, &output](const Message &m) {
        output.push_back(m);
        hm.erase(m.value);
    });
    return output;
}


int main() {
    int n;
    cin >> n;

    int delay;
    cin >> delay;

    vector<Message> input;

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        string msg;
        cin >> msg;
        input.push_back({t, msg});
    }

    auto result = process(input, delay);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << '\n';
    }
}
