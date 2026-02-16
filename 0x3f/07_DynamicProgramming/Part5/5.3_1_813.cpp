#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>> dp(n, vector<double>(k + 1, -1.0));
        vector<int> sumV(n + 1);
        for (int i = 0; i < n; i++)
        {
            sumV[i + 1] = sumV[i] + nums[i];
        }

        auto dfs = [&] (this auto&& dfs, int right, int curK) -> double
        {
            if (curK <= 0)
            {
                if (right < 0)
                {
                    return 0.0;
                }
                return -1e8;
            }
            if (right < 0)
            {
                return 0.0;
            }
            if (dp[right][curK] != -1.0)
            {
                return dp[right][curK];
            }

            int left = right;
            double maxAve = -1e8;
            while (left >= 0)
            {
                maxAve = max(maxAve, dfs(left - 1, curK - 1) + (double)(sumV[right + 1] - sumV[left]) / (right - left + 1));
                left--;
            }
            dp[right][curK] = maxAve;
            return maxAve;
        };

        return dfs(n - 1, k);
    }
};

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>> dp(n + 1, vector<double>(k + 1));
        vector<int> sumV(n + 1);
        for (int i = 0; i < n; i++)
        {
            sumV[i + 1] = sumV[i] + nums[i];
        }
        for (int i = 1; i < n + 1; i++)
        {
            dp[i][0] = -1e8;
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int x = 0; x < k; x++)
            {
                for (int j = 0; j <= i; j++)
                {
                    dp[i + 1][x + 1] = max(dp[i + 1][x + 1], dp[j][x] + (double)(sumV[i + 1] - sumV[j]) / (i - j + 1));
                }
            }
        }

        return dp.back().back();
    }
};