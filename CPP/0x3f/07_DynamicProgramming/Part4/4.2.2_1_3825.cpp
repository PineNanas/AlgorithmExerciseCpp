#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int w = bit_width((uint32_t) ranges::max(nums));

        for (int i = 0; i < w; i++)
        {
            vector<int> dp;      
            for (auto &&x : nums)
            {
                if ((x >> i & 1) == 0)
                {
                    continue;
                }
                auto pos = ranges::lower_bound(dp, x);
                if (pos == dp.end())
                {
                    dp.push_back(x);
                }
                else
                {
                    *pos = x;
                }
            }
            ans = max(ans, (int)dp.size());
        }
        return ans;
    }
};