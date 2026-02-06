#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int last = nums[0];
        if (nums.size() == 1)
        {
            return last;
        }
        int now;
        int ans = last;
        for (int i = 1; i < nums.size(); i++)
        {
            now = max(nums[i], last + nums[i]);
            ans = max(ans, now);
            last = now;
        }
        return ans;
    }
};