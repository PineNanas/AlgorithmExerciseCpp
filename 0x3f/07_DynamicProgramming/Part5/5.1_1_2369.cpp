#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        
        auto dfs = [&] (this auto&& dfs, int right) -> bool
        {
            if (right < 0)
            {
                return 1;
            }
            if (right == 0)
            {
                return 0;
            }
            if (right == 1)
            {
                return nums[0] == nums[1];
            }
            if (dp[right] != -1)
            {
                return dp[right];
            }

            if (nums[right] == nums[right - 1] && nums[right] == nums[right - 2] && dfs(right - 3))
            {
                dp[right] = 1;
                return true;
            }
            if (nums[right] - 1 == nums[right - 1] && nums[right - 1] - 1 == nums[right - 2] && dfs(right - 3))
            {
                dp[right] = 1;
                return true;
            }
            if (nums[right] == nums[right - 1] && dfs(right - 2))
            {
                dp[right] = 1;
                return true;
            }
            dp[right] = 0;
            return false;
        };

        return dfs(n - 1);
    }
};

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[2] = nums[0] == nums[1];

        for (int i = 2; i < n; i++)
        {
            if (dp[i - 2])
            {
                if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2])
                {
                    dp[i + 1] = 1;
                    continue;
                }
                if (nums[i] - 1 == nums[i - 1] && nums[i - 1] - 1 == nums[i - 2])
                {
                    dp[i + 1] = 1;
                    continue;
                }
            }
            if(dp[i - 1])
            {
                if (nums[i] == nums[i - 1])
                {
                    dp[i + 1] = 1;
                    continue;
                }
            }
            dp[i + 1] = 0;
        }
        return dp.back();
    }
};