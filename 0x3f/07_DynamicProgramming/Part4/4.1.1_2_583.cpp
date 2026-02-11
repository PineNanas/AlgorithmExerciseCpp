#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        auto dfs = [&] (this auto&& dfs, int x, int y) -> int
        {
            if (x < 0)
            {
                return y + 1;
            }
            if (y < 0)
            {
                return x + 1;
            }
            if (dp[x][y] != -1)
            {
                return dp[x][y];
            }
            

            int count;
            if (word1[x] == word2[y])
            {
                count = dfs(x - 1, y - 1);
            }
            else
            {
                count = min(dfs(x - 1, y), dfs(x, y - 1)) + 1;
            }
            dp[x][y] = count;
            return count;
        };
        return dfs(n - 1, m - 1);
    };
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i < m + 1; i++)
        {
            dp[0][i] = i;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (word1[i] == word2[j])
                {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else
                {
                    dp[i + 1][j + 1] = min(dp[i + 1][j], dp[i][j + 1]) + 1;
                }
            }
        }
        return dp[n][m];
    };
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> dp(m + 1);
        for (int i = 0; i < m + 1; i++)
        {
            dp[i] = i;
        }
        int pre;
        int cur;

        for (int i = 0; i < n; i++)
        {
            pre = dp[0];
            dp[0] = i + 1;
            for (int j = 0; j < m; j++)
            {
                if (word1[i] == word2[j])
                {
                    cur = pre;
                }
                else
                {
                    cur = min(dp[j], dp[j + 1]) + 1;
                }
                pre = dp[j + 1];
                dp[j + 1] = cur;
            }
        }
        return dp[m];
    };
};