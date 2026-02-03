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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        for (int i = 0; i < n; i++)
        {
            p = p->next;
        }
        ListNode* q = head;
        if (p == nullptr)
        {
            if (q->next == nullptr)
            {
                return nullptr;
            }
            return q->next;
        }
        while (p->next != nullptr)
        {
            p = p->next;
            q = q->next;
        }
        p = q->next;
        q->next = p->next;
        delete p;
        return head;
    }
};