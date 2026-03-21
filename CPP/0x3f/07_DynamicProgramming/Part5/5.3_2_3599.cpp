#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] ^ nums[i];
        }
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        

        auto dfs = [&] (this auto&& dfs, int right, int curK) -> int
        {
            if (right < 0)
            {
                if (curK == 0)
                {
                    return 0;
                }
                return INT_MAX;
            }
            if (curK == 0)
            {
                return INT_MAX;
            }
            if (dp[right][curK] != -1)
            {
                return dp[right][curK];
            }
            

            int minRes = INT_MAX;
            for (int left = 0; left < right + 1; left++)
            {
                minRes = min(minRes, max(dfs(left - 1, curK - 1), pre[right + 1] ^ pre[left]));
            }
            dp[right][curK] = minRes;
            return minRes;
        };

        return dfs(n - 1, k);
    }
};

class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] ^ nums[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        dp[0][0] = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int x = 0; x < k; x++)
            {
                for (int j = 0; j < i + 1; j++)
                {
                    dp[i + 1][x + 1] = min(dp[i + 1][x + 1], max(dp[j][x], pre[i + 1] ^ pre[j]));
                }
            }
        }
        
        return dp.back().back();
    }
};

class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] ^ nums[i];
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for (int x = 0; x < k; x++)
        {
            for (int i = n; i > 0; i--)
            {
                int res = INT_MAX;
                for (int j = 0; j < i; j++)
                {
                    res = min(res, max(dp[j], pre[i] ^ pre[j]));
                }
                dp[i] = res;
            }
            dp[0] = INT_MAX;
        }
        
        return dp.back();
    }
};