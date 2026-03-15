#include <bits/stdc++.h>
using namespace std;

struct ListNodeM {
    int key;
    int value;
    ListNodeM *next;
    ListNodeM *front;
    ListNodeM(int key, int value) : key(key), value(value), next(nullptr), front(nullptr) {}
};

class LRUCache {
public:
    unordered_map<int, ListNodeM*> hashMap;
    ListNodeM* dHead;
    ListNodeM* dTail;
    int count;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        count = 0;
        dHead = new ListNodeM(0, 0);
        dTail = new ListNodeM(0, 0);
        dHead->next = dTail;
        dTail->front = dHead;
    }
    
    int get(int key) {
        if (!hashMap.contains(key))
        {
            return -1;
        }
        ListNodeM* cur = hashMap[key];
        cur->front->next = cur->next;
        cur->next->front = cur->front;
        cur->next = dHead->next;
        cur->front = dHead;
        dHead->next->front = cur;
        dHead->next = cur;
        return cur->value;
    }
    
    void put(int key, int value) {
        if (hashMap.contains(key))
        {
            ListNodeM* cur = hashMap[key];
            cur->value = value;
            cur->front->next = cur->next;
            cur->next->front = cur->front;
            cur->next = dHead->next;
            cur->front = dHead;
            dHead->next->front = cur;
            dHead->next = cur;
            return;
        }
        if (count == cap)
        {
            ListNodeM* tail = dTail->front;
            dTail->front = tail->front;
            tail->front->next = dTail;
            hashMap.erase(tail->key);
            delete tail;
        }
        else
        {
            count++;
        }
        ListNodeM* cur = new ListNodeM(key, value);
        cur->next = dHead->next;
        cur->front = dHead;
        dHead->next->front = cur;
        dHead->next = cur;
        hashMap[key] = cur;
        return;
    }
};