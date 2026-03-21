#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 0;
        int right = ranges::max(nums);
        int mid;
        while (left + 1 < right)
        {
            mid = left + (right - left) / 2;
            if (divideSum(nums, mid) <= threshold)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        return right;
    }

    int divideSum(vector<int>& nums, int divisor)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += (nums[i] + divisor - 1) / divisor;
        }
        return sum;
    }
};