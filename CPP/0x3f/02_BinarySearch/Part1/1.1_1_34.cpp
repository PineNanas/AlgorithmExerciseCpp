#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lowerBound(nums, target);
        if (start == nums.size() || nums[start] != target)
        {
            return {-1, -1};
        }
        int end = lowerBound(nums, target + 1) - 1;
        return {start, end};
    }

    int lowerBound(vector<int>& nums, int target)
    {
        int left = -1;
        int right = nums.size();
        int mid = 0;
        while (left + 1 < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        return right;
    }
};