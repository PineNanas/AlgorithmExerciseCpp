#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int prod = 1;
        int left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prod *= nums[i];
            while (left < i && prod >= k)
            {
                prod /= nums[left];
                left++;
            }
            if (prod < k)
            {
                ans += i - left + 1;
            }
        }
        return ans;
    }
};