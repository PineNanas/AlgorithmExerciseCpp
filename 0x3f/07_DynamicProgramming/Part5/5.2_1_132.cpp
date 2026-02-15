#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -2);

        auto check = [&] (int left, int right) -> bool
        {
            while (left < right)
            {
                if (s[left] != s[right])
                {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        };

        auto dfs = [&] (this auto&& dfs, int right) -> int
        {
            if (right == -1)
            {
                return -1;
            }
            if (dp[right] != -2)
            {
                return dp[right];
            }
            
            int left = right;
            int minCut = INT_MAX;
            while (left >= 0)
            {
                if (check(left, right))
                {
                    minCut = min(minCut, dfs(left - 1));
                }
                left--;
            }
            dp[right] = minCut + 1;
            return minCut + 1;
        };
        
        return dfs(n - 1);
    }
};

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = -1;

        auto check = [&] (int left, int right) -> bool
        {
            while (left < right)
            {
                if (s[left] != s[right])
                {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        };

        for (int right = 0; right < n; right++)
        {
            int minCut = INT_MAX;
            for (int left = right; left >= 0; left--)
            {
                if (check(left, right))
                {
                    minCut = min(minCut, dp[left]);
                }
            }
            dp[right + 1] = minCut + 1;
        }
        
        return dp.back();
    }
};

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = -1;
        vector<vector<bool>> isPalid(n, vector<bool>(n, true));

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                isPalid[i][j] = s[i] == s[j] ? isPalid[i + 1][j - 1] : false;
            }
        }
        
        for (int right = 0; right < n; right++)
        {
            int minCut = INT_MAX;
            for (int left = right; left >= 0; left--)
            {
                if (isPalid[left][right])
                {
                    minCut = min(minCut, dp[left]);
                }
            }
            dp[right + 1] = minCut + 1;
        }
        
        return dp.back();
    }
};