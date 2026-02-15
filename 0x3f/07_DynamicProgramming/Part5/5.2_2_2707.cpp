#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n, -1);

        auto dfs = [&] (this auto&& dfs, int right) -> int 
        {
            if (right < 0)
            {
                return 0;
            }
            if (dp[right] != -1)
            {
                return dp[right];
            }

            int left = right;
            int cost;
            int minCost = INT_MAX;
            while (left >= 0)
            {
                cost = right - left + 1;
                for (auto &&word : dictionary)
                {
                    if (word == s.substr(left, cost))
                    {
                        cost = 0;
                        break;
                    }
                }
                cost += dfs(left - 1);
                minCost = min(minCost, cost);
                left--;
            }
            dp[right] = minCost;
            return minCost;
        };

        return dfs(n - 1);
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> checkSet(dictionary.begin(), dictionary.end());
        vector<int> dp(n + 1);
        
        for (int right = 0; right < n; right++)
        {
            dp[right + 1] = dp[right] + 1;
            for (int left = right; left >= 0; left--)
            {
                if (checkSet.contains(s.substr(left, right - left + 1)))
                {
                    dp[right + 1] = min(dp[right + 1], dp[left]);
                }
            }
        }
        return dp.back();
    }
};