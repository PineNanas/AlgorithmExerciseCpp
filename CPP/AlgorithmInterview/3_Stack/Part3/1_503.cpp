#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> anwser(size, -1);
        stack<int> stk;
        for (int i = 0; i < size * 2 - 1; i++)
        {
            while (stk.size() != 0 && nums[stk.top()] < nums[i % size])
            {
                anwser[stk.top()] = nums[i % size];
                stk.pop();
            }
            stk.push(i % size);
        }
        return anwser;
    }
};