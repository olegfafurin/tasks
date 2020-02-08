//
// Created by imd on 10/14/2019.
//


#include <vector>
#include <iostream>
#include <set>

using namespace std;

struct Node {
    set<pair<char, Node *>> child;
    Node *parent;

    explicit Node(Node *p) {
        this->parent = p;
    }
};

int index;
string s;

void addNode(Node *cur) {
    if (index > s.size()) return;
    switch (s[index]) {
        case '{':
            break;
        case '}':
            break;
        case ',':
            index++;
            addNode(cur->parent);
            break;
        default:
            Node next = Node(cur);
            cur->child.insert(pair<char, Node *>(s[index], &next));
            index++;
            addNode(&next);
    }
}

vector<string> braceExpansionII(string expression) {
    for (int i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        switch (c) {
            case '{':

        }
    }
}

int main() {

}