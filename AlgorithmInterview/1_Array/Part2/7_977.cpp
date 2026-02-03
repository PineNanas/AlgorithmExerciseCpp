#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int size = nums.size();
        vector<int> ans;
        while (i < size && nums[i] < 0) i++;
        int j = i - 1;
        while (j >= 0 || i < size)
        {
            if (j >= 0 && (i >= size || abs(nums[i]) >= abs(nums[j])))
            {
                ans.emplace_back(nums[j] * nums[j]);
                j--;
            }
            else if (i < size && (j < 0 || abs(nums[i]) < abs(nums[j])))
            {
                ans.emplace_back(nums[i] * nums[i]);
                i++;
            }
        }
        return ans;
    }
};