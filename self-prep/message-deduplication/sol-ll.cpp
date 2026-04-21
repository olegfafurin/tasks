#include <vector>
#include <iostream>
#include <list>
#include <iterator>
#include <unordered_map>

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
            output.push_back(msg);
            auto it = cache.insert(cache.end(), msg);
            hm[msg.value] = it;
        }
        auto oldStart = cache.begin();
        auto oldEnd = oldStart;
        while (oldEnd != cache.end() && oldEnd->time < msg.time - delay) {
            hm.erase(oldEnd->value);
            oldEnd = next(oldEnd);
        }
        cache.erase(oldStart, oldEnd);
    }
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
