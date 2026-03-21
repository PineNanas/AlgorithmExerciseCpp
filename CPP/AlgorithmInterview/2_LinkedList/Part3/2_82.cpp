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
        ListNode* dummyHead = new ListNode(-101, head);
        ListNode* p = dummyHead;
        unordered_set<int> hashSet;
        while (p->next->next != nullptr)
        {
            if (p->next->val == p->next->next->val)
            {
                hashSet.insert(p->next->val);
            }
            if (hashSet.find(p->next->val) != hashSet.end())
            {
                p->next = p->next->next;
            }
            else
            {
                p = p->next;
            }
        }
        if (hashSet.find(p->next->val) != hashSet.end())
        {
            p->next = p->next->next;
        }
        return dummyHead->next;
    }
};