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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* p = head;
        ListNode* q = p->next;
        while (q != nullptr)
        {
            if (q->val == p->val)
            {
                p->next = q->next;
                delete q;
            }
            else
            {
                p = q;
            }
            q = p->next;
        }
        return head;
    }
};