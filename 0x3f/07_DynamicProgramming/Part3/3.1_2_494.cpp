#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        target = accumulate(nums.begin(), nums.end(), target);
        int n = nums.size();
        if (target % 2 || target < 0)
        {
            return 0;
        }
        target /= 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        auto dfs = [&] (this auto&& dfs, int x, int curTar) -> int
        {
            if (x < 0)
            {
                if (curTar == 0)
                {
                    return 1;
                }
                return 0;
            }
            if (curTar < 0)
            {
                return 0;
            }
            if (dp[x][curTar] != -1)
            {
                return dp[x][curTar];
            }

            return dp[x][curTar] = dfs(x - 1, curTar) + dfs(x - 1, curTar - nums[x]);
        };

        return dfs(n - 1, target);  
    }
};