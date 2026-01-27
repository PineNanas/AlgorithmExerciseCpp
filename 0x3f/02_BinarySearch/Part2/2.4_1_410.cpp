#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int maxValue = ranges::max(nums);
        auto check = [&] (int maxThreshold) -> bool
        {
            if (maxThreshold < maxValue)
            {
                return false;
            }
            int sum = 0;
            int count = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (sum + nums[i] > maxThreshold)
                {
                    sum = 0;
                    count++;
                    if (count == k)
                    {
                        return false;
                    }
                }
                sum += nums[i];
            }
            return true;
        };
        int sumValue = accumulate(nums.begin(), nums.end(), 0);
        int left = maxValue - 1;
        int right = sumValue + 1;
        int mid;
        while (left + 1 < right)
        {
            mid = left + (right - left) / 2;
            (check(mid) ? right : left) = mid;
        }
        return right;
    }
};