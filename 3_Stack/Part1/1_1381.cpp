#include<bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    vector<int> insideStack;
    int top;
    int max;
    CustomStack(int maxSize) {
        insideStack.resize(maxSize);
        top = -1;
        max = maxSize;
    }
    
    void push(int x) {
        if (top < max - 1)
        {
            insideStack[++top] = x;
        }
    }
    
    int pop() {
        return top != -1 ? insideStack[top--] : -1;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, top + 1); i++)
        {
            insideStack[i] += val;
        }
        
    }
};