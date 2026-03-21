#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        auto dfs = [&] (this auto&& dfs, int x, bool got, int remain) -> int
        {
            if (x < 0)
            {
                if (!got)
                {
                    return 0;
                }
                return INT_MIN;
            }
            if (remain > 2)
            {
                return INT_MIN;
            }
            if (dp[x][got][remain] != -1)
            {
                return dp[x][got][remain];
            }

            int maxprofit;
            if (got)
            {
                maxprofit = max(dfs(x - 1, true, remain), dfs(x - 1, false, remain) - prices[x]);
            }
            else
            {
                maxprofit = max(dfs(x - 1, false, remain), dfs(x - 1, true, remain + 1) + prices[x]);
            }
            dp[x][got][remain] = maxprofit;
            return maxprofit;
        };

        return dfs(n - 1, false, 0);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(4)));
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0][3] = INT_MIN;
            dp[i][1][3] = INT_MIN;
        }
        for (int k = 0; k < 3; k++)
        {
            dp[0][0][k] = 0;
            dp[0][1][k] = INT_MIN;
        }

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < 3; k++)
            {
                dp[i + 1][0][k] = max(dp[i][0][k], dp[i][1][k + 1] + prices[i]);
            }
            for (int k = 0; k < 3; k++)
            {
                dp[i + 1][1][k] = max(dp[i][1][k], dp[i][0][k] - prices[i]);
            }
        }
        
        return dp[n][0][0];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(3, vector<int>(4));
        dp[0][3] = INT_MIN;
        dp[1][3] = INT_MIN;
        for (int k = 0; k < 3; k++)
        {
            dp[0][k] = 0;
            dp[1][k] = INT_MIN;
        }

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < 4; k++)
            {
                dp[2][k] = dp[0][k];
            }
            for (int k = 0; k < 3; k++)
            {
                dp[0][k] = max(dp[0][k], dp[1][k + 1] + prices[i]);
            }
            for (int k = 0; k < 3; k++)
            {
                dp[1][k] = max(dp[1][k], dp[2][k] - prices[i]);
            }
        }
        
        return dp[0][0];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(4, INT_MIN));
        for (int k = 0; k < 3; k++)
        {
            dp[0][k] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < 3; k++)
            {
                dp[1][k] = max(dp[1][k], dp[0][k] - prices[i]);
                dp[0][k] = max(dp[0][k], dp[1][k + 1] + prices[i]);
            }
        }
        
        return dp[0][0];
    }
};