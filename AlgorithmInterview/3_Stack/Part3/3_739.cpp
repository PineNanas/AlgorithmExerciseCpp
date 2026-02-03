#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> stk;
        for (int i = 0; i < temperatures.size(); i++)
        {
            while(!stk.empty() && temperatures[stk.top()] < temperatures[i])
            {
                ans[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};