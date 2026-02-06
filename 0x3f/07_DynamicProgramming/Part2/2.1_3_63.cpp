#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        dp[0][0] = 1;
        
        auto dfs = [&] (this auto&& dfs, int x, int y) -> int
        {
            if (x < 0 || y < 0)
            {
                return 0;
            }
            if (obstacleGrid[x][y])
            {
                dp[x][y] = 0;
                return 0;
            }
            if (dp[x][y] != -1)
            {
                return dp[x][y];
            }
            
            int curPath = dfs(x - 1, y) + dfs(x, y - 1);
            dp[x][y] = curPath;
            return curPath;
        };

        return dfs(n - 1, m - 1);
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0])
        {
            return 0;
        }
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<int>& f = obstacleGrid[0];
        f[0] = 1;
        for (int i = 1; i < m; i++)
        {
            if (f[i])
            {
                f[i] = 0;
                continue;
            }
            f[i] = f[i - 1];
        }
        
        for (int i = 1; i < n; i++)
        {
            if (obstacleGrid[i][0])
            {
                f[0] = 0;
            }
            for (int j = 1; j < m; j++)
            {
                if (obstacleGrid[i][j])
                {
                    f[j] = 0;
                    continue;
                }
                f[j] = f[j] + f[j - 1];
            }
        }
        return f.back();
    }
};