#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> controlled(n, vector<bool>(n, false));
        vector<int> putPosition(n);
        vector<vector<string>> ans;

        auto finish = [&] () -> void
        {
            vector<string> oneSolve(n);
            for (int i = 0; i < n; i++)
            {
                string s = "";
                for (int j = 0; j < putPosition[i]; j++)
                {
                    s.push_back('.');
                }
                s.push_back('Q');
                for (int j = putPosition[i] + 1; j < n; j++)
                {
                    s.push_back('.');
                }
                oneSolve[i] = s;
            }
            ans.push_back(oneSolve);
        };

        auto dfs = [&] (this auto&& dfs, int line) -> void
        {
            if (line == n)
            {
                finish();
                return;
            }
            
            // 每个位置都尝试
            for (int column = 0; column < n; column++)
            {
                if (controlled[line][column])
                {
                    continue;
                }

                putPosition[line] = column;
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