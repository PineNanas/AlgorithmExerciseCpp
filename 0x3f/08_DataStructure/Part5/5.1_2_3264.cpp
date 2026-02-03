#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue< pair<int, int>, 
                        vector<pair<int, int>>, 
                        greater<pair<int, int>>> minHeap;
        for (int i = 0; i < nums.size(); i++)
        {
            minHeap.push({nums[i], i});
        }
        for (int i = 0; i < k; i++)
        {
            auto [num, index] = minHeap.top(); 
            int newNum = num * multiplier;
            minHeap.pop();
            minHeap.push({newNum, index});
            nums[index] = newNum;
        }
        return nums;
    }
};