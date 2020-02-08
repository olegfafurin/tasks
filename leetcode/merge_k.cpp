//
// Created by imd on 10/8/2019.
//

#include <set>
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {};
};

template <typename T>
struct Comp {
    bool operator() (const T &lhs, const T &rhs) const {
        return lhs.val < rhs.val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    multiset<ListNode, Comp<ListNode>> candidates = multiset<ListNode, Comp<ListNode>>();
    for (ListNode *l: lists) candidates.emplace(*l);
    ListNode dummy = ListNode(0);
    ListNode *current = &dummy;
    while (!candidates.empty()) {
        ListNode minCandidate = *candidates.begin();
        auto *newOne = new ListNode(minCandidate.val);
        current->next = newOne;
        current = current->next;
        candidates.erase(candidates.begin());
        if (minCandidate.next != nullptr) candidates.emplace(*minCandidate.next);
    }
    return dummy.next;
}

int main() {
    ListNode a = ListNode(3);
    ListNode b = ListNode(7);
    ListNode c = ListNode(5);
    ListNode d = ListNode(9);
    a.next = &b;
    c.next = &d;

    vector<ListNode *> lists = vector<ListNode *>({&a, &c});
    auto result = mergeKLists(lists);
    while (result != nullptr) {
        cout << result->val << ' ' ;
        result = result->next;
    }
}