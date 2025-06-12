#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        vector<int> ans(2);
        for (int i = 0; i < nums.size(); i++)
        {
            if (hashMap.count(nums[i]) != 0)
            {
                ans[0] = i;
                ans[1] = hashMap[nums[i]]; 
            }
            hashMap.insert({target - nums[i], i});
        }
        return ans;
    }
};