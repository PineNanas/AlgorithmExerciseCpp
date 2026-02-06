#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                if (i == 0)
                {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                    continue;
                }
                if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                    continue;
                }
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1][m - 1];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        auto dfs = [&] (this auto&& dfs, int x, int y) -> int
        {
            if (dp[x][y] != 0)
            {
                return dp[x][y];
            }
            if (x == 0 && y == 0)
            {
                return grid[x][y];
            }
            if (x == 0)
            {
                return dfs(x, y - 1) + grid[x][y];
            }
            if (y == 0)
            {
                return dfs(x - 1, y) + grid[x][y];
            }
            int cur = min(dfs(x - 1, y), dfs(x, y - 1)) + grid[x][y];
            dp[x][y] = cur;
            return cur;
        };
        return dfs(n - 1, m - 1);
    }
};