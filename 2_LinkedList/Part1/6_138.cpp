#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hashMap;
        Node* p = head;
        while (p != nullptr)
        {
            Node* newNodePtr = new Node(p->val);
            hashMap.insert({p, newNodePtr});
            p = p->next;
        }
        p = head;
        Node* newHead = hashMap[head];
        Node* p2 = nullptr;
        while (p != nullptr)
        {
            p2 = hashMap[p];
            p2->next = hashMap[p->next];
            p2->random = hashMap[p->random];
            p = p->next;
        }
        return newHead;
    }
};