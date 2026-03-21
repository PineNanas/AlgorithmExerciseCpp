#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        auto dfs = [&] (this auto&& dfs, int x, int y) -> int
        {
            if (x < 0 || y < 0)
            {
                return y < 0;
            }
            if (dp[x][y] != -1)
            {
                return dp[x][y];
            }

            int count;
            if (s[x] == t[y])
            {
                count = dfs(x - 1, y - 1) + dfs(x - 1, y);
            }
            else
            {
                count = dfs(x - 1, y);
            }
            dp[x][y] = count;
            return count;
        };
        return dfs(n - 1, m - 1);
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1));
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i + 1][j + 1] = dp[i][j + 1] + dp[i][j] * (s[i] == t[j]);
            }
        }
        return dp.back().back();
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<unsigned long long> dp(m + 1);
        dp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                dp[j + 1] = dp[j + 1] + dp[j] * (s[i] == t[j]);
            }
        }
        return dp.back();
    }
};