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

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> nodeSet;
        while (head)
        {
            if (nodeSet.contains(head))
            {
                return head;
            }
            nodeSet.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

class Solution2
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        } 
        ListNode *fast = head;
        ListNode *slow = head;
        do
        {
            slow = slow->next;
            if (!fast->next || !fast->next->next)
            {
                return nullptr;
            }
            fast = fast->next->next;
        } while (fast != slow);
        fast = head;
        while (fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};