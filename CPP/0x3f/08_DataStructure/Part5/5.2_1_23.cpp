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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        auto cmp = [&] (ListNode* a, ListNode* b) -> bool
        {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for (auto &&node : lists)
        {
            while (node)
            {
                minHeap.push(node);
                node = node->next;
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (!minHeap.empty())
        {
            cur->next = minHeap.top();
            cur = minHeap.top();
            minHeap.pop();
        }
        cur->next = nullptr;
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        auto cmp = [&] (ListNode* a, ListNode* b) -> bool
        {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for (auto &&node : lists)
        {
            if (!node)
            {
                continue;
            }
            minHeap.push(node);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (!minHeap.empty())
        {
            cur->next = minHeap.top();
            cur = minHeap.top();
            minHeap.pop();
            if (cur->next)
            {
                minHeap.push(cur->next);
            }
        }
        cur->next = nullptr;
        return dummy->next;
    }
};