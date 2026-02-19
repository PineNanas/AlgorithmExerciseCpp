#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        auto dfs = [&] (this auto&& dfs, int x, bool got) -> int
        {
            if (x < 0)
            {
                if (!got)
                {
                    return 0;
                }
                return INT_MIN;
            }
            if (dp[x][got] != -1)
            {
                return dp[x][got];
            }

            int maxProfit;
            if (got)
            {
                maxProfit = max(dfs(x - 1, true), dfs(x - 1, false) - prices[x]);
            }
            else
            {
                maxProfit = max(dfs(x - 1, false), dfs(x - 1, true) + prices[x]);
            }
            dp[x][got] = maxProfit;
            return maxProfit;
        };

        return dfs(n - 1, false);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int got = INT_MIN;
        int ngot = 0;

        for (int i = 0; i < n; i++)
        {
            int Nngot = max(ngot, got + prices[i]);
            int Ngot = max(got, ngot - prices[i]);
            got = Ngot;
            ngot = Nngot;
        }
        return ngot;
    }
};