#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<vector<long long>> dp(n, vector<long long>(4, LONG_LONG_MIN));

        auto dfs = [&] (this auto&& dfs, int x, int y) -> long long
        {
            if (y < 0)
            {
                return 0;
            }
            if (x < 0)
            {
                return LONG_LONG_MIN;
            }
            if (dp[x][y] != LONG_LONG_MIN)
            {
                return dp[x][y];
            }
            
            long long maxValue;
            long long choose = dfs(x - 1, y - 1);
            if (choose == LONG_LONG_MIN)
            {
                maxValue = dfs(x - 1, y);
            }
            else
            {
                maxValue = max(dfs(x - 1, y), choose + (long long)a[y] * b[x]);
            }
            dp[x][y] = maxValue;
            return maxValue; 
        };
        
        return dfs(n - 1, 3);
    }
};

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(5));
        for (int i = 1; i <= 4; i++)
        {
            dp[0][i] = LONG_LONG_MIN;
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (dp[i][j] == LONG_LONG_MIN)
                {
                    dp[i + 1][j + 1] = dp[i][j + 1];
                    continue;
                }
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i][j] + (long long)a[j] * b[i]);
            }
        }

        return dp.back().back();
    }
};

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<long long> dp(5, LONG_LONG_MIN);
        dp[0] = 0;
        long long pre;
        long long cur;
        
        for (int i = 0; i < n; i++)
        {
            pre = dp[0];
            for (int j = 0; j < 4; j++)
            {
                if (pre == LONG_LONG_MIN)
                {
                    pre = dp[j + 1];
                    continue;
                }
                cur = max(dp[j + 1], pre + (long long)a[j] * b[i]);
                pre = dp[j + 1];
                dp[j + 1] = cur;
            }
        }

        return dp.back();
    }
};

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<long long> dp(5, LONG_LONG_MIN);
        dp[0] = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 3; j >= 0; j--)
            {
                if (dp[j] == LONG_LONG_MIN)
                {
                    continue;
                }
                dp[j + 1] = max(dp[j + 1], dp[j] + (long long)a[j] * b[i]);
            }
        }

        return dp.back();
    }
};