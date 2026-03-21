#include<bits/stdc++.h>
using namespace std;

class MyHashSet {
public:
    vector<int> internalVec;
    MyHashSet() :internalVec(10000, -2){
    }
    
    void add(int key) {
        int p = key % 9997;
        while (internalVec[p] >= 0 && internalVec[p] != key)
        {
            p = (p + 1) % 9997;
        }
        internalVec[p] = key;
    }
    
    void remove(int key) {
        int p = key % 9997;
        while (internalVec[p] != key && internalVec[p] >=0)
        {
            p = (p + 1) % 9997;
        }
        internalVec[p] = -1;
    }
    
    bool contains(int key) {
        int p = key % 9997;
        while (internalVec[p] >= -1)
        {
            if (internalVec[p] == key)
            {
                return true;
            }
            p = (p + 1) % 9997;
        }
        return false;
    }
};
