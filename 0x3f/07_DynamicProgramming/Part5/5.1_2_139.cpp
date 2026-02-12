#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n, -1);

        auto check = [&] (string word, int x) -> bool
        {
            int m = word.size();
            if (x < m - 1)
            {
                return false;
            }
            for (int i = 0; i < m; i++)
            {
                if (s[x - i] != word[m - 1 - i])
                {
                    return false;
                }
            }
            return true;
        };

        auto dfs = [&] (this auto&& dfs, int x) -> bool
        {
            if (x < -1)
            {
                return false;
            }
            if (x == -1)
            {
                return true;
            }
            if (dp[x] != -1)
            {
                return dp[x];
            }

            for (auto &&word : wordDict)
            {
                if (check(word, x) && dfs(x - word.size()))
                {
                    dp[x] = 1;
                    return true;
                }
            }
            dp[x] = 0;
            return false;
        };

        return dfs(n - 1);
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        auto check = [&] (string word, int x) -> bool
        {
            int m = word.size();
            if (x + m > n)
            {
                return false;
            }
            for (int i = 0; i < m; i++)
            {
                if (s[x + i] != word[i])
                {
                    return false;
                }
            }
            return true;
        };

        for (int i = 0; i < n + 1; i++)
        {
            if (dp[i] == true)
            {
                for (auto &&word : wordDict)
                {
                    int m = word.size();
                    if (!dp[i + m] && check(word, i))
                    {
                        dp[i + m] = true;
                    }
                }
            }
        }
        return dp.back();
    }
};