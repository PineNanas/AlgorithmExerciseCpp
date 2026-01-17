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
    bool isPalindrome(ListNode* head) {
        if (!head->next)
        {
            return true;
        }
        ListNode* mid = findMid(head);
        ListNode* nextHalf = reverse(mid);
        mid = head;
        while (mid->next->next)
        {
            mid = mid->next;
        }
        mid->next = nullptr;
        while (head && nextHalf)
        {
            if (head->val != nextHalf->val)
            {
                return false;
            }
            head = head->next;
            nextHalf = nextHalf->next;
        }
        return true;
    }
    ListNode* findMid(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head)
    {
        if (!head->next)
        {
            return head;
        }
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};