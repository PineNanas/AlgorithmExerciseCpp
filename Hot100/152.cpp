#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {INT_MAX, INT_MIN});
        int ans = INT_MIN;
        auto dfs = [&] (this auto&& dfs, int x) -> pair<int, int>
        {
            if (x < 0)
            {
                return {1, 1};
            }
            if (dp[x].first != INT_MAX || dp[x].second != INT_MIN)
            {
                return dp[x];
            }
            auto [Max, Min] = dfs(x - 1);
            if (nums[x] > 0)
            {
                Max = max(nums[x], nums[x] * Max);
                Min = min(nums[x], nums[x] * Min);
            }
            else
            {
                int tmp = Max;
                Max = max(nums[x], nums[x] * Min);
                Min = min(nums[x], nums[x] * tmp);
            }
            dp[x].first = Max;
            dp[x].second = Min;
            ans = max(ans, Max);
            return {Max, Min};
        };
        dfs(n - 1);
        return ans;
    }
};