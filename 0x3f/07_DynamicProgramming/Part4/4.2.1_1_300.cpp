#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        auto dfs = [&] (this auto&& dfs, int x) -> int
        {
            if (dp[x] != -1)
            {
                return dp[x];
            }
            int res = 0;
            for (int i = 0; i < x; i++)
            {
                if (nums[i] >= nums[x])
                {
                    continue;
                }
                res = max(res, dfs(i));
            }
            res++;
            dp[x] = res;
            return res;
        };
        
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] >= nums[i])
                {
                    continue;
                }
                dp[i] = max(dp[i], dp[j]);
            }
            dp[i]++;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = {};

        auto lower = [&] (int x) -> int
        {
            int left = -1;
            int right = dp.size();
            int mid;
            while (left + 1 < right)
            {
                mid = left + (right - left) / 2;
                if (dp[mid] >= x)
                {
                    right = mid;
                }
                else
                {
                    left = mid;
                }
            }
            return right;
        };

        int changePoint;
        for (int i = 0; i < n; i++)
        {
            changePoint = lower(nums[i]);
            if (changePoint == dp.size())
            {
                dp.push_back(nums[i]);
            }
            else
            {
                dp[changePoint] = nums[i];
            }
        }
        
        return dp.size();
    }
};