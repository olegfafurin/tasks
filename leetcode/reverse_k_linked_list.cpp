//
// Created by imd on 10/9/2019.
//
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {};
};

ListNode *reverseKGroup(ListNode *head, int k) {
    if (k == 1 || head == nullptr || head->next == nullptr) return head;
    ListNode *block_start = head;
    ListNode *cur = head;
    ListNode *nextNext;
    ListNode *next;
    ListNode *prev_block_start = nullptr;
    for (int i = 0; i < k - 1; ++i) {
        if (cur != nullptr) cur = cur->next;
    }
    if (cur == nullptr) return head;
    ListNode *global_head = cur;
    bool flag = false;
    while (true) {
        cur = block_start;
        if (cur == nullptr) break;
        next = cur->next;
        for (int i = 0; i < k - 1; ++i) {
            if (next != nullptr) {
                nextNext = next->next;
                next->next = cur;
                cur = next;
                next = nextNext;
            } else {
                while (cur->next != next) {
                    nextNext = cur->next;
                    cur->next = next;
                    next = cur;
                    cur = nextNext;
                }
                flag = true;
                break;
            }
        }
        if (flag) break;
        if (prev_block_start != nullptr) prev_block_start->next = cur;
        prev_block_start = block_start;
        block_start->next = next;
        block_start = next;
    }
    return global_head;
}

int main() {
    vector<ListNode> nodes = vector<ListNode>();
    for (int i = 0; i < 11; ++i) nodes.emplace_back(ListNode(i));
    for (int i = 0; i < 10; ++i) nodes[i].next = &nodes[i + 1];
    ListNode *cur = reverseKGroup(&nodes[0], 12);
    while (cur != nullptr) {
        cout << cur->val << ' ';
        cur = cur->next;
    }
}
