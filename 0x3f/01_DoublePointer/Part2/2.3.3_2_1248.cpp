#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return moreThanK(nums, k) - moreThanK(nums, k + 1);
    }

    int moreThanK(vector<int>& nums, int k)
    {
        int ans = 0;
        int count = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count += nums[i] % 2;
            while (count == k)
            {
                count -= nums[left] % 2;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};