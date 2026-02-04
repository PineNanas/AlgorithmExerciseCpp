#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        auto dfs = [&] (this auto&& dfs, int i, int j) -> int
        {
            if (i < 0 || j < 0 || i >= n || j >= m)
            {
                return 0;
            }
            if (grid[i][j] == 0)
            {
                return 0;
            }
            grid[i][j] = 0;
            return 1 + dfs(i - 1, j) + dfs(i, j - 1) + dfs(i + 1, j) + dfs(i, j + 1);
        };
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    continue;
                }
                maxArea = max(maxArea, dfs(i, j));
            }
        }
        return maxArea;
    }
};