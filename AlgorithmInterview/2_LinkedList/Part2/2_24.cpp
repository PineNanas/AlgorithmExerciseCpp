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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyNode = new ListNode(-1, head);
        ListNode* p = dummyNode;
        ListNode* q = nullptr;
        while (p->next != nullptr && p->next->next != nullptr)
        {
            q = p->next;
            p->next = q->next;
            q->next = p->next->next;
            p->next->next = q;
            p = q;
        }
        return dummyNode->next;
        

    }
};