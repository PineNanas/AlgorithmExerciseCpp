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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val >= list2->val)
            {
                p->next = list2;
                p = p->next;
                list2 = p->next;
            }
            else
            {
                p->next = list1;
                p = p->next;
                list1 = p->next;
            }

        }
        if (list1 == nullptr)
        {
            p->next = list2;
        }
        else
        {
            p->next = list1;
        }
        return dummy->next;
    }
};