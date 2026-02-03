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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummyHead = {0, head};
        ListNode* p = &dummyHead;
        while (p->next != nullptr)
        {
            if (p->next->val != val)
            {
                p = p->next;
            }
            else
            {
                ListNode* s = p->next;
                p->next = s->next;
                delete s;
            }
        }
        return dummyHead.next;
    }
};