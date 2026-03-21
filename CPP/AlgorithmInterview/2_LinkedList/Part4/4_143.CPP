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
    void reorderList(ListNode* head) {
        vector<ListNode*> listNodeVector;
        listNodeVector.reserve(50000);
        ListNode* now = head;
        while (now)
        {
            listNodeVector.push_back(now);
            now = now->next;
        }
        int i = 0;
        int j = listNodeVector.size() - 1;
        while (i < j - 1)
        {
            listNodeVector[i]->next = listNodeVector[j];
            listNodeVector[j]->next = listNodeVector[i + 1];
            i++;
            j--;
        }
        if (i < j)
        {
            listNodeVector[i]->next = listNodeVector[j];
        }
        listNodeVector[j]->next = nullptr;
        return;
    }
};

class Solution2 {
public:
    void reorderList(ListNode* head) {
        if (!head->next)
        {
            return;
        }
        ListNode* mid = findMid(head);
        ListNode* nextHalf = reverse(mid);
        mid = head;
        while (mid->next->next)
        {
            mid = mid->next;
        }
        mid->next = nullptr;
        mergeNodeList(head, nextHalf);
        return;
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

    void mergeNodeList(ListNode* listA, ListNode* listB)
    {
        if (!listA || !listB)
        {
            return;
        }
        ListNode* nextA = nullptr;
        ListNode* nextB = nullptr;
        while (listA && listB)
        {
            nextA = listA->next;
            nextB = listB->next;
            listA->next = listB;
            if (!nextA)
            {
                return;
            }
            else
            {
                listB->next = nextA;
            }
            listA = nextA;
            listB = nextB;
        }
        return;
    }
};