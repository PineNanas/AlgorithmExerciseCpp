#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;

        auto dfs = [&] (this auto&& dfs, int x, int y, int z) -> void
        {
            if (y == 0 && z == 0)
            {
                ans.push_back(path);
                return;
            }
            if (z < 0)
            {
                return;
            }
            if (9 - x + 1 < y)
            {
                return;
            }
            
            for (int i = x; i < 10; i++)
            {
                path.push_back(i);
                dfs(i + 1, y - 1, z - i);
                path.pop_back();
            }
            return;
        };

        dfs(1, k, n);
        return ans;
    }
};