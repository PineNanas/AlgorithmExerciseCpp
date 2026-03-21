#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(n, -1);
        auto dfs = [&] (this auto&& dfs, int x) -> int
        {
            if (x < 0)
            {
                return 0;
            }
            if (cache[x] != -1)
            {
                return cache[x];
            }
            int maxX = max(dfs(x - 1), nums[x] + dfs(x - 2));
            cache[x] = maxX;
            return maxX;
        };

        return dfs(n - 1);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = nums[0];
        if (n == 1)
        {
            return nums[0];
        }
        ans[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            ans[i] = max(ans[i - 1], ans[i - 2] + nums[i]);
        }
        return ans[n - 1];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int last2 = nums[0];
        if (n == 1)
        {
            return last2;
        }
        int last1 = max(nums[0], nums[1]);
        int now = last1;
        for (int i = 2; i < n; i++)
        {
            now = max(last2 + nums[i], last1);
            last2 = last1;
            last1 = now;
        }
        return now;
    }
};