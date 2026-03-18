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

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n + 1, {INT_MAX, INT_MIN});
        dp[0].first = 1;
        dp[0].second = 1;
        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                dp[i + 1].first = max(nums[i], nums[i] * dp[i].first);
                dp[i + 1].second = min(nums[i], nums[i] * dp[i].second);
            }
            else
            {
                dp[i + 1].first = max(nums[i], nums[i] * dp[i].second);
                dp[i + 1].second = min(nums[i], nums[i] * dp[i].first);
            }
            ans = max(ans, dp[i + 1].first);
        }
        return ans;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxCur = 1;
        int minCur = 1;
        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                maxCur = max(nums[i], nums[i] * maxCur);
                minCur = min(nums[i], nums[i] * minCur);
            }
            else
            {
                int tmp = maxCur;
                maxCur = max(nums[i], nums[i] * minCur);
                minCur = min(nums[i], nums[i] * tmp);
            }
            ans = max(ans, maxCur);
        }
        return ans;
    }
};