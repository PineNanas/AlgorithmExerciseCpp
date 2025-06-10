#include<bits/stdc++.h>
using namespace std;

class ListN 
{
public:
    pair<int, int> keyValue;
    ListN* next = nullptr;

    ListN(){}
    ListN(pair<int, int> keyValuep)
    {
        keyValue = keyValuep;
    }
    ListN(pair<int, int> keybaluep, ListN* nextLN)
    {
        keyValue = keybaluep;
        next = nextLN;
    }
};

class MyHashMap {
public:
    vector<ListN*> internalVec;
    MyHashMap(): internalVec(997, nullptr){}
    
    void put(int key, int value) 
    {
        int index = hash(key);
        ListN* p = internalVec[index];
        pair<int, int> pair1 = {key, value};
        if (p == nullptr)
        {
            internalVec[index] = new ListN(pair1);
            return;
        }
        while (p->next != nullptr)
        {
            if (p->keyValue.first == key)
            {
                p->keyValue.second = value;
                return;
            }
            p = p->next;
        }
        if (p->keyValue.first == key)
        {
            p->keyValue.second = value;
            return;
        }
        p->next = new ListN(pair1);
    }
    
    int get(int key) 
    {
        int index = hash(key);
        ListN* p = internalVec[index];
        while (p != nullptr)
        {
            if (p->keyValue.first == key)
            {
                return p->keyValue.second;
            }
            p = p->next;
        }
        return -1;
    }
    
    void remove(int key) 
    {
        int index = hash(key);
        ListN* p = internalVec[index];
        if (p == nullptr)
        {
            return;
        }
        if (p->keyValue.first == key)
        {
            internalVec[index] = p->next;
            delete p;
            return;
        }
        while (p->next != nullptr && p->next->keyValue.first != key)
        {
            p = p->next;
        }
        if (p->next == nullptr)
        {
            return;
        }
        ListN* q = p->next;
        p->next = q->next;
        delete q;
    }

    int hash(int key)
    {
        return key % 997;
    }
};
