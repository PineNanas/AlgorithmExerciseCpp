#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<bool>> controlled(n, vector<bool>(n, false));
        int ans = 0;

        auto dfs = [&] (this auto&& dfs, int line) -> void
        {
            if (line == n)
            {
                ans++;
                return;
            }
            
            // 每个位置都尝试
            for (int column = 0; column < n; column++)
            {
                if (controlled[line][column])
                {
                    continue;
                }

                // 填写控制位置
                vector<pair<int, int>> controllAfterPut;
                for (int i = line + 1; i < n; i++)
                {
                    if (!controlled[i][column])
                    {
                        controllAfterPut.push_back({i, column});
                        controlled[i][column] = true;
                    }
                    int diff = i - line;
                    if (column - diff >= 0 && !controlled[i][column - diff])
                    {
                        controllAfterPut.push_back({i, column - diff});
                        controlled[i][column - diff] = true;
                    }
                    if (column + diff < n && !controlled[i][column + diff])
                    {
                        controllAfterPut.push_back({i, column + diff});
                        controlled[i][column + diff] = true;
                    }
                }
                // 递归
                dfs(line + 1);
                // 还原
                for (auto &&[x, y] : controllAfterPut)
                {
                    controlled[x][y] = false;
                }
            }
            return;
        };
        dfs(0);
        return ans;
    }
};