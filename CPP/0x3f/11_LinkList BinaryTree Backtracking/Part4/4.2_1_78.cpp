#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        int n = nums.size();

        auto dfs = [&] (this auto&& dfs, int i) -> void
        {
            if (i >= n)
            {
                ans.push_back(cur);
                return;
            }
            cur.push_back(nums[i]);
            dfs(i + 1);
            cur.pop_back();
            dfs(i + 1);
            return;
        };

        dfs(0);
        return ans;
    }
};