#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;
    
        for (int i = 0; i < n; i++)
        {
            int coin = coins[i];
            for (int j = coin; j < amount + 1; j++)
            {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        
        return dp[amount];
    }
};