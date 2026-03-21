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
    ListNode* reverseList(ListNode* head) {
        ListNode* newListHead = nullptr;
        ListNode* p = head;
        while (p != nullptr)
        {
            ListNode* newNode = new ListNode(p->val, newListHead);
            newListHead = newNode;
            p = p->next;
        }
        return newListHead;
    }
};