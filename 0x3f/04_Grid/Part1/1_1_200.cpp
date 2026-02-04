#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m));
        int island = 0;
        auto dfs = [&] (this auto&& dfs,int i, int j) -> void
        {
            if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j])
            {
                return;
            }
            if (grid[i][j] == '0')
            {
                return;
            }
            visited[i][j] = 1;
            dfs(i - 1, j);
            dfs(i, j - 1);
            dfs(i + 1, j);
            dfs(i, j + 1);
        };
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] || grid[i][j] == '0')
                {
                    continue;
                }
                island++;
                dfs(i, j);
            }
        }
        return island;
    }
};