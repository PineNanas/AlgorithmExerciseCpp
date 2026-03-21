#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        auto dfs = [&] (this auto&& dfs, int x, int y) -> int
        {
            if (x < 0 || y < 0)
            {
                return 0;
            }
            if (dp[x][y] != -1)
            {
                return dp[x][y];
            }

            int count;
            if (text1[x] == text2[y])
            {
                count = dfs(x - 1, y - 1) + 1;
            }
            else
            {
                count = max(dfs(x - 1, y), dfs(x, y - 1));
            }
            dp[x][y] = count;
            return count;
        };

        return dfs(n - 1, m - 1);
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (text1[i] == text2[j])
                {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else
                {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[n][m];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> dp(m + 1);
        int pre;
        int cur;

        for (int i = 0; i < n; i++)
        {
            pre = dp[0];
            for (int j = 0; j < m; j++)
            {
                if (text1[i] == text2[j])
                {
                    cur = pre + 1;
                }
                else
                {
                    cur = max(dp[j + 1], dp[j]);
                }
                pre = dp[j + 1];
                dp[j + 1] = cur;
            }
        }
        return dp[m];
    }
};