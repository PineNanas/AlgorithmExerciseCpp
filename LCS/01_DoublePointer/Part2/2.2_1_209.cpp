#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int now = 0;
        int nowCount = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (now < target)
            {
                now += nums[i];
                nowCount++;
            }
            while (now >= target)
            {
                ans = min(nowCount, ans);
                now -= nums[left];
                left++;
                nowCount--;
            }
        }
        if (ans == INT_MAX)
        {
            return 0;
        }
        return ans;
    }
};