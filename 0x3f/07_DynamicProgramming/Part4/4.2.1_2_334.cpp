#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(3, LONG_LONG_MAX);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (dp[j] >= nums[i])
                {
                    dp[j] = nums[i];
                    if (dp[2] != LONG_LONG_MAX)
                    {
                        return true;
                    }
                    break;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int first = nums[0];
        int second = INT_MAX;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > second)
            {
                return true;
            }
            if (nums[i] > first)
            {
                second = nums[i];
            }
            else
            {
                first = nums[i];
            }
        }
        return false;
    }
};