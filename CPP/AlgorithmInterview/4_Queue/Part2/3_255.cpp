#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> internalQueue;
    MyStack() {
        
    }
    
    void push(int x) {
        internalQueue.push(x);
        int a = 0;
        for (int i = 0; i < internalQueue.size() - 1; i++)
        {
            a = internalQueue.front();
            internalQueue.push(a);
            internalQueue.pop();
        }
    }
    
    int pop() {
        int ans = internalQueue.front();
        internalQueue.pop();
        return ans;
    }
    
    int top() {
        return internalQueue.front();
    }
    
    bool empty() {
        if (internalQueue.empty())
        {
            return true;
        }
        return false;
    }
};
