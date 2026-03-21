#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> stkin;
    stack<int> stkout;
    MyQueue() {
    }
    
    void push(int x) {
        stkin.push(x);
    }
    
    int pop() {
        if (stkout.size() == 0)
        {
            refresh();
        }
        int ans = stkout.top();
        stkout.pop();
        return ans;
    }
    
    int peek() {
        if (stkout.size() == 0)
        {
            refresh();
        }
        return stkout.top();
    }
    
    bool empty() {
        if (stkout.size() + stkin.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void refresh()
    {
        while (stkin.size() != 0)
        {
            stkout.push(stkin.top());
            stkin.pop();
        }
    }
};
