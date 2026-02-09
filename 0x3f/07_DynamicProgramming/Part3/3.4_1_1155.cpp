#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<vector<long long>> dp(n, vector<long long> (target + 1, -1));

        auto dfs = [&] (this auto&& dfs, int curRoll, int curTarget) -> long long
        {
            if (curRoll < 0)
            {
                if (curTarget == 0)
                {
                    return 1;
                }
                return 0;
            }
            if (curTarget < 1)
            {
                return 0;
            }
            if (dp[curRoll][curTarget] != -1)
            {
                return dp[curRoll][curTarget];
            }

            long long projCount = 0;
            for (int i = 1; i < k + 1; i++)
            {
                projCount += dfs(curRoll - 1, curTarget - i);
                projCount %= mod;
            }
            dp[curRoll][curTarget] = projCount;
            return projCount;
        };

        return dfs(n - 1, target);
    }
};

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long> (target + 1));
        dp[0][0] = 1;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j < target + 1; j++)
            {
                for (int x = 1; x < k + 1 && x <= j; x++)
                {
                    dp[i][j] += dp[i - 1][j - x];
                    dp[i][j] %= mod;
                }
            }
        }
                
        return dp[n][target];
    }
};

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<long long> dp(target + 1);
        dp[0] = 1;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = target; j >= 0; j--)
            {   
                int start = min(k, j);
                dp[j] = 0;
                for (int x = start; x > 0; x--)
                {
                    dp[j] += dp[j - x];
                    dp[j] %= mod;
                }
            }
        }  
        return dp[target];
    }
};

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if (target < n || target > n * k)
        {
            return 0;
        }
        int mod = 1e9 + 7;
        vector<long long> dp(target + 1 - n);
        dp[0] = 1;

        for (int i = 1; i < n + 1; i++)
        {
            int maxJ = min(i * k, target - n);
            for (int j = 1; j <= maxJ; j++)
            {
                dp[j] += dp[j - 1];
            }
            for (int j = maxJ; j >= k; j--)
            {   
                dp[j] = (dp[j] - dp[j - k]) % mod;
            }
        }  
        return dp.back();
    }
};