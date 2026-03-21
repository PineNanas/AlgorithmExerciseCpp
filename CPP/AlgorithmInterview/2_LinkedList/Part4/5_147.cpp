#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head->next)
        {
            return head;
        }
        ListNode* sorted = head;
        ListNode* tosort = head->next;
        sorted->next = nullptr;
        while (tosort)
        {
            ListNode* p = tosort->next;
            if (tosort->val < sorted->val)
            {
                tosort->next = sorted;
                sorted = tosort;
            }
            else
            {
                ListNode* insertPosition = sorted;
                while (insertPosition->next && tosort->val > insertPosition->next->val)
                {
                    insertPosition = insertPosition->next;
                }
                if (insertPosition->next)
                {
                    tosort->next = insertPosition->next;
                    insertPosition->next = tosort;
                }
                else
                {
                    insertPosition->next = tosort;
                    tosort->next = nullptr;
                }
            }
            tosort = p;
        }
        return sorted;
    }
};