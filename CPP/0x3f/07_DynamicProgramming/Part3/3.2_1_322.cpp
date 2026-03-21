#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        auto dfs = [&] (this auto&& dfs, int coinInd, int curAmt) -> int
        {
            if (coinInd < 0)
            {
                if (curAmt == 0)
                {
                    return 0;
                }
                return INT_MAX - 1;
            }
            if (dp[coinInd][curAmt] != -1)
            {
                return dp[coinInd][curAmt];
            }     
            if (coins[coinInd] > curAmt)
            {
                return dfs(coinInd - 1, curAmt);
            }
            
            return dp[coinInd][curAmt] = min(dfs(coinInd - 1, curAmt), dfs(coinInd, curAmt - coins[coinInd]) + 1);
        };
        int ans = dfs(n - 1, amount);
        return ans == (INT_MAX - 1) ? -1 : ans;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX - 1));
        dp[0][0] = 0;
    
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < amount + 1; j++)
            {
                if (coins[i] > j)
                {
                    dp[i + 1][j] = dp[i][j];
                    continue;
                }
                dp[i + 1][j] = min(dp[i][j], dp[i + 1][j - coins[i]] + 1);
            }
        }
        
        return dp[n][amount] == (INT_MAX - 1) ? -1 : dp[n][amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
    
        for (int i = 0; i < n; i++)
        {
            int coin = coins[i];
            for (int j = coin; j < amount + 1; j++)
            {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        
        return dp[amount] == (INT_MAX - 1) ? -1 : dp[amount];
    }
};