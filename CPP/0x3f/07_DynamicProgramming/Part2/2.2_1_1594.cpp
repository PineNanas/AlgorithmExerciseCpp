#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        if (grid[0][0] == 0)
        {
            return 0;
        }
        int n = grid.size(), m = grid[0].size();
        vector<vector<long long>> dpMax(n, vector<long long>(m, LONG_LONG_MIN));
        vector<vector<long long>> dpMin(n, vector<long long>(m, LONG_LONG_MAX));
        dpMax[0][0] = grid[0][0];
        dpMin[0][0] = grid[0][0];

        auto dfs = [&] (this auto&& dfs, int x, int y) -> pair<long long, long long>
        {
            if (x < 0 || y < 0)
            {
                return {LONG_LONG_MIN, LONG_LONG_MAX};
            }
            if (dpMax[x][y] != LONG_LONG_MIN && dpMin[x][y] != LONG_LONG_MAX)
            {
                return {dpMax[x][y], dpMin[x][y]};
            }

            auto [leftMax, leftMin] = dfs(x - 1, y);
            auto [upMax, upMin] = dfs(x, y - 1);
            int cur = grid[x][y];
            long long i = max(leftMax, upMax) * cur;
            long long j = min(leftMin, upMin) * cur;
            long long curMax = max(i, j);
            long long curMin = min(i, j);
            dpMax[x][y] = curMax;
            dpMin[x][y] = curMin;
            return {curMax, curMin};
        };
        long long ans = dfs(n - 1, m - 1).first % 1000000007;
        return ans >= 0 ? ans : -1;
    }
};