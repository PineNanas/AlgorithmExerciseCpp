#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        
        for (int i = 0; i < n; i++)
        {
            auto pos = lower_bound(dp.begin(), dp.end(), nums[i] + 1);
            if (pos == dp.end())
            {
                dp.push_back(nums[i]);
            }
            else
            {
                *pos = nums[i];
            }
        }
        return n - dp.size();
    }
};