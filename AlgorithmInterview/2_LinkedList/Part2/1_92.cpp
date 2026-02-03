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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* newHead = new ListNode(head->val);
        ListNode* p = head->next;
        ListNode* q1 = newHead;
        ListNode* q2 = newHead;
        int i = 2;
        while (p)
        {
            ListNode* newNode = new ListNode(p->val);
            if (i >= left && i <= right)
            {
                if (left == 1)
                {
                    newNode->next = newHead;
                    newHead = newNode;
                    q2 = newNode;
                }
                else
                {
                    newNode->next = q2->next;
                    q2->next = newNode;
                }
                if (newNode->next == nullptr)
                {
                    q1 = newNode;
                }
                p = p->next;
                i++;
            }
            else
            {
                q1->next = newNode;
                q1 = newNode;
                q2 = newNode;
                p = p->next;
                i++;
            }
        }
        return newHead;
    }
};