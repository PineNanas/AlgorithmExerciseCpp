#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> cur(n);
        vector<bool> picked(n, false);

        auto dfs = [&] (this auto&& dfs, int x) -> void
        {
            if (x == n)
            {
                ans.push_back(cur);
                return;
            }
            
            for (int i = 0; i < n; i++)
            {
                if (picked[i])
                {
                    continue;
                }
                picked[i] = true;
                cur[x] = nums[i];
                dfs(x + 1);
                picked[i] = false;
            }
            return;
        };

        dfs(0);
        return ans;
    }
};