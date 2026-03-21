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
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        dp[0][0] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < target + 1; j++)
            {
                if (nums[i] > j)
                {
                    dp[i + 1][j] = dp[i][j]; 
                }
                else
                {
                    dp[i + 1][j] = dp[i][j - nums[i]] + dp[i][j];
                }
            }
        }
        return dp[n][target];
    }
};

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
        vector<int> dp(target + 1);
        dp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = target; j >= 0; j--)
            {
                if (nums[i] > j)
                {
                    continue;
                }
                dp[j] = dp[j - nums[i]] + dp[j];
            }
        }
        return dp[target];
    }
};