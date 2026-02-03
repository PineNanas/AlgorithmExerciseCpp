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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* small = new ListNode(0);
        ListNode* smallTail = small;
        ListNode* big = new ListNode(0);
        ListNode* bigTail = big;
        ListNode* now = head;
        while (now != nullptr)
        {
            if (now->val < x)
            {
                smallTail->next = now;
                smallTail = now;
            }
            else
            {
                bigTail->next = now;
                bigTail = now;
            }
            now = now->next;
        }
        smallTail->next = big->next;
        bigTail->next = nullptr;
        now = small->next;
        delete small;
        delete big;
        return now;
    }
};