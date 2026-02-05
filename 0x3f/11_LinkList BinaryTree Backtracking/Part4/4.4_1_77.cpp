#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;

        auto dfs = [&] (this auto&& dfs, int x, int y) -> void
        {
            if (y == 0)
            {
                ans.push_back(path);
                return;
            }
            if (n - x + 1 < y)
            {
                return;
            }
            
            for (int i = x; i < n + 1; i++)
            {
                path.push_back(i);
                dfs(i + 1, y - 1);
                path.pop_back();
            }
            return;
        };

        dfs(1, k);
        return ans;
    }
};