#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0)
        {
            return head;
        }
        ListNode* p= head;
        int size = 1;
        while (p->next != nullptr)
        {
            p = p->next;
            size++;
        }
        p->next = head;
        p = head;
        ListNode* newHead = nullptr;
        int rollCount = size - k % size;
        int count = 0;
        while (count < rollCount - 1)
        {
            p = p->next;
            count++;
        }
        newHead = p->next;
        p->next = nullptr;
        return newHead;
    }
};