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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
        {
            return head;
        }
        ListNode* dummyNode = new ListNode(-1, head);
        ListNode* prev = dummyNode;
        ListNode* curr = nullptr;
        ListNode* next = nullptr;
        while (true)
        {
            next = prev;
            int i = 0;
            while (next != nullptr && i < k)
            {
                next = next->next;
                i++;
            }
            if (next == nullptr)
            {
                return dummyNode->next;
            }
            curr = prev->next;
            for (int i = 0; i < k - 1; i++)
            {
                next = curr->next;
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            prev = curr;
        }
        
    }
};