#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sumN = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if (sumN % 2)
        {
            return false;
        }
        sumN /= 2;
        vector<vector<int>> dp(n, vector<int>(sumN + 1, -1));

        auto dfs = [&] (this auto&& dfs, int x, int curSum) -> bool
        {
            if (x < 0)
            {
                return false;
            }
            if (curSum == 0)
            {
                return true;
            }
            if (curSum < 0)
            {
                return false;
            }
            if (dp[x][curSum] != -1)
            {
                return dp[x][curSum];
            }

            return dp[x][curSum] = dfs(x - 1, curSum) || dfs(x - 1, curSum - nums[x]);
        };

        return dfs(n - 1, sumN);
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sumN = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if (sumN % 2)
        {
            return false;
        }
        sumN /= 2;
        vector<int> dp(sumN + 1);
        dp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = sumN; j >= 0; j--)
            {
                if (nums[i] > j)
                {
                    continue;
                }
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[sumN];
    }
};