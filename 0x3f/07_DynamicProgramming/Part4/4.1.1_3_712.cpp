#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        auto dfs = [&] (this auto&& dfs, int x, int y) -> int 
        {
            if (x < 0)
            {
                int sum = 0;
                for (int i = 0; i <= y; i++)
                {
                    sum += (int)s2[i];
                }
                return sum;
            }
            if (y < 0)
            {
                int sum = 0;
                for (int i = 0; i <= x; i++)
                {
                    sum += (int)s1[i];
                }
                return sum;
            }
            if (dp[x][y] != -1)
            {
                return dp[x][y];
            }


            int cost;
            if (s1[x] == s2[y])
            {
                cost = dfs(x - 1, y - 1);
            }
            else
            {
                cost = min(dfs(x - 1, y) + (int)s1[x], dfs(x, y - 1) + (int)s2[y]);
            }
            dp[x][y] = cost;
            return cost;
        };

        return dfs(n - 1, m - 1);
    }
};

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; i++)
        {
            dp[i + 1][0] = dp[i][0] + (int)s1[i];
        }
        for (int j = 0; j < m; j++)
        {
            dp[0][j + 1] = dp[0][j] + (int)s2[j];
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (s1[i] == s2[j])
                {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else
                {
                    dp[i + 1][j + 1] = min(dp[i][j + 1] + (int)s1[i], dp[i + 1][j] + (int)s2[j]);
                }
            }
        }
        return dp[n][m];
    }
};

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> dp(m + 1);
        for (int j = 0; j < m; j++)
        {
            dp[j + 1] = dp[j] + (int)s2[j];
        }
        int pre;
        int cur;

        for (int i = 0; i < n; i++)
        {
            pre = dp[0];
            dp[0] += (int)s1[i];
            for (int j = 0; j < m; j++)
            {
                if (s1[i] == s2[j])
                {
                    cur = pre;
                }
                else
                {
                    cur = min(dp[j + 1] + (int)s1[i], dp[j] + (int)s2[j]);
                }
                pre = dp[j + 1];
                dp[j + 1] = cur;
            }
        }
        return dp.back();
    }
};