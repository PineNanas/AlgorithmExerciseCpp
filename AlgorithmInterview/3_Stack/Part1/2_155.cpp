#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    vector<int> insideVector;
    vector<int> minVector;
    int topprt { -1 };

    MinStack() {
    }
    
    void push(int val) {
        insideVector.emplace_back(val);
        if (topprt == -1)
        {
            minVector.emplace_back(val);
        }
        else
        {
            minVector.emplace_back(min(minVector[topprt], val));
        }
        topprt ++;
    }
    
    void pop() {
        insideVector.pop_back();
        minVector.pop_back();
        topprt--;
    }
    
    int top() {
        return insideVector[topprt];
    }
    
    int getMin() {
        return minVector[topprt];
    }
};
