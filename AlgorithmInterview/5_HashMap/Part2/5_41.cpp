#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= 0)
            {
                nums[i] = nums.size() + 1;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int trueIndex = abs(nums[i]);
            if (trueIndex <= nums.size())
            {
                nums[trueIndex - 1] = - abs(nums[trueIndex - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};