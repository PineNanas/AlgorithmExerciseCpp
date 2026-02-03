#include<bits/stdc++.h>
using namespace std;

class Checkout {
public:
    deque<int> maxQueue;
    queue<int> outQueue;
    Checkout() {
        
    }
    
    int get_max() {
        if (maxQueue.empty())
        {
            return -1;
        }
        return maxQueue.front();
    }
    
    void add(int value) {
        while (!maxQueue.empty() && maxQueue.back() < value)
        {
            maxQueue.pop_back();
        }
        maxQueue.push_back(value);
        outQueue.push(value);
    }
    
    int remove() {
        if (outQueue.empty())
        {
            return -1;
        }
        int ans = outQueue.front();
        if (outQueue.front() == maxQueue.front())
        {
            maxQueue.pop_front();
        }
        outQueue.pop();
        return ans;
    }
};
