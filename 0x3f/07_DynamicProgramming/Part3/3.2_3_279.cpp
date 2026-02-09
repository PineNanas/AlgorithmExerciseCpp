#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int start = sqrt(n) + 1;
        vector<vector<int>> dp(start, vector<int>(n + 1, -1));
        auto dfs = [&] (this auto&& dfs, int x, int y) -> int
        {
            if (x < 1)
            {
                if (y == 0)
                {
                    return 0;
                }
                return INT_MAX - 1;
            }
            if (x * x > y)
            {
                return dfs(x - 1, y);
            }
            if (dp[x][y] != -1)
            {
                return dp[x][y];
            }
            

            int count = min(dfs(x, y - x * x) + 1, dfs(x - 1, y));
            dp[x][y] = count;
            return count;
        };

        return dfs(start, n);
    }
};

class Solution {
public:
    int numSquares(int n) {
        int start = sqrt(n) + 1;
        vector<int> dp(n + 1, INT_MAX - 1);
        dp[0] = 0;

        for (int i = 1; i < start + 1; i++)
        {
            for (int j = i * i; j < n + 1; j++)
            {
                dp[j] = min(dp[j - i * i] + 1, dp[j]);
            }
        }

        return dp[n];
    }
};