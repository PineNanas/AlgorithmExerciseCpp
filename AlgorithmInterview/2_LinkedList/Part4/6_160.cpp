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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> listNodeSet;
        listNodeSet.reserve(30000);
        while (headA)
        {
            listNodeSet.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (listNodeSet.contains(headB))
            {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
        {
            return nullptr;
        }
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (true)
        {
            if (pA == pB)
            {
                return pA;
            }
            if (pA)
            {
                pA = pA->next;
            }
            else
            {
                pA = headB;
            }
            if (pB)
            {
                pB = pB->next;
            }
            else
            {
                pB = headA;
            }
        }
        
    }
};