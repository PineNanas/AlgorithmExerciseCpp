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
    ListNode* sortList(ListNode* head) {
        if (!head)
        {
            return nullptr;
        }
        if (!head->next)
        {
            return head;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }   
        ListNode* second = slow->next;
        slow->next = nullptr;
        head = sortList(head);
        second = sortList(second);
        return merge(head, second);
    }

    ListNode* merge(ListNode* first, ListNode* second){
        ListNode dummy;
        ListNode* tail = &dummy;
        while (first || second)
        {
            if (!first || (second && first->val > second->val))
            {
                tail->next = second;
                tail = second;
                second = second->next;
            }
            else
            {
                tail->next = first;
                tail = first;
                first = first->next;
            }
        }
        tail->next = nullptr;
        return dummy.next;
    }
};