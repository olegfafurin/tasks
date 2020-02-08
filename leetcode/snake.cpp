//
// Created by imd on 10/9/2019.
//

#include <vector>
#include <iostream>
#include <deque>
#include <map>

using namespace std;

struct state {
    int x;
    int y;
    bool dir; // true if horizontal
    state(int x, int y, bool direction) {
        this->x = x;
        this->y = y;
        this->dir = direction;
    }

    bool operator==(const state &other) const {
        return (this->x == other.x && this->y == other.y && this->dir == other.dir);
    }

    bool operator!=(const state &other) const {
        return !(this->x == other.x && this->y == other.y && this->dir == other.dir);
    }

    bool operator<(const state &other) const {
        if (x > other.x) return false;
        if (x < other.x) return true;
        if (y > other.y) return false;
        if (y < other.y) return true;
        return dir < other.dir;
    }
};


map<state, int> mark;
int n;
deque<state> queue;
state init = state(0, 0, true);

void push_state(const state new_state, int level) {
    if (mark.at(new_state) == 0 && new_state != init) {
        mark[new_state] = level;
        queue.emplace_back(new_state);
    }
}

int minimumMoves(vector<vector<int>> &grid) {
    n = grid.size();
    if (grid[n - 1][n - 1] == 1 || grid[n - 1][n - 2] == 1) return -1;
        queue = deque<state>();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mark.insert(pair<state, int>(state(i, j, true), 0));
            mark.insert(pair<state, int>(state(i, j, false), 0));
        }
    }
    queue.emplace_back(init);
    int counter = 0;
    while (!queue.empty()) {
        counter++;
        state current = queue.front();
        queue.pop_front();
        if (current.dir) {
            if (current.y < n - 2 && grid[current.x][current.y + 2] == 0) {
                push_state(state(current.x, current.y + 1, true), mark[current] + 1);
            }
            if (current.x < n - 1 && grid[current.x + 1][current.y] == 0 && grid[current.x + 1][current.y + 1] == 0) {
                push_state(state(current.x, current.y, false), mark[current] + 1);
                push_state(state(current.x + 1, current.y, true), mark[current] + 1);
            }
        } else {
            if (current.x < n - 2 && grid[current.x + 2][current.y] == 0) {
                push_state(state(current.x + 1, current.y, false), mark[current] + 1);
            }
            if (current.y < n - 1 && grid[current.x][current.y + 1] == 0 && grid[current.x + 1][current.y + 1] == 0) {
                push_state(state(current.x, current.y, true), mark[current] + 1);
                push_state(state(current.x, current.y + 1, false), mark[current] + 1);
            }
        }
    }
    state end_pos = state(n - 1, n - 2, true);
    if (mark[end_pos] == 0) {
        if (end_pos != init) return -1;
        else return 0;
    } else return mark[end_pos];
}

int main() {
    int s, c;
    cin >> s;
    auto field = vector<vector<int>>(s, vector<int>(s));
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            cin >> c;
            field[i][j] = c;
        }
    }
    cout << minimumMoves(field);
}