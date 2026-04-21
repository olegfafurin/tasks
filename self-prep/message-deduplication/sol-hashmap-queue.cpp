#include <vector>
#include <queue>
#include <iostream>
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
    unordered_map<string, int> lastSeen;
    queue<Message> queue;
    vector<Message> output;
    for (const auto &[t, msg]: input) {
        if (!lastSeen.contains(msg) || lastSeen[msg] < t - delay) {
            output.push_back({t, msg});
            lastSeen[msg] = t;
        }
        while (!queue.empty() && queue.front().time < t - delay) {
            lastSeen.erase(queue.front().value);
            queue.pop();
        }
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
