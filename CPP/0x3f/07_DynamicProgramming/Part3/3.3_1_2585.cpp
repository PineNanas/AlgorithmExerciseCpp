#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        int mod = 1000000007;
        vector<vector<long long>> dp(n, vector<long long> (target + 1, -1));

        auto dfs = [&] (this auto&& dfs, int curIndex, int curTarget) -> long long
        {
            if (curIndex < 0)
            {
                if (curTarget == 0)
                {
                    return 1;
                }
                return 0;
            }
            if (dp[curIndex][curTarget] != -1)
            {
                return dp[curIndex][curTarget];
            }
            
            int problem = types[curIndex][0], mark = types[curIndex][1];
            if (mark > curTarget)
            {
                return dfs(curIndex - 1, curTarget);
            }
            
            long long projCount = dfs(curIndex - 1, curTarget); 
            int i = 1;
            while (i <= problem && curTarget - (i * mark) >= 0)
            {
                projCount += dfs(curIndex - 1, curTarget - i * mark);
                projCount %= mod;
                i++;
            }
            dp[curIndex][curTarget] = projCount;
            return projCount;
        };

        return dfs(n - 1, target);
    }
};

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        int mod = 1e9 + 7;
        vector<long long> dp(target + 1);
        dp[0] = 1;
        
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = target; j >= 0; j--)
            {
                for (int k = 1; k <= types[i - 1][0] && j - k * types[i - 1][1] >= 0; k++)
                {
                    dp[j] += dp[j - k * types[i - 1][1]];
                    dp[j] %= mod;
                }
            }
        }
        return dp[target];
    }
};