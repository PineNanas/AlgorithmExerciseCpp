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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenEnd = head;
        ListNode* oddEnd = nullptr;
        ListNode* target = nullptr;
        if (evenEnd == nullptr)
        {
            return head;
        }
        oddEnd = evenEnd->next;
        if (oddEnd == nullptr)
        {
            return head;
        }
        while (oddEnd->next != nullptr)
        {
            target = oddEnd->next;
            if (target->next == nullptr)
            {
                target->next = evenEnd->next;
                evenEnd->next = target;
                oddEnd->next = nullptr;
            }
            else
            {
                oddEnd->next = target->next;
                target->next = evenEnd->next;
                evenEnd->next = target;
                evenEnd = evenEnd->next;
                oddEnd = oddEnd->next;
            }
        }
        return head;
    }
};