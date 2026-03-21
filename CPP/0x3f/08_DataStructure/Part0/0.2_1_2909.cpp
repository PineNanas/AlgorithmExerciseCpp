#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMin(n);
        leftMin[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            leftMin[i] = min(leftMin[i - 1], nums[i]);
        }
        vector<int> rigthtMin(n);
        rigthtMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rigthtMin[i] = min(rigthtMin[i + 1], nums[i]);
        }
        int minSum = INT_MAX;
        for (int i = 1; i < n - 1; i++)
        {
            if (nums[i] > leftMin[i - 1] && nums[i] > rigthtMin[i + 1])
            {
                minSum = min(minSum, nums[i] + leftMin[i - 1] + rigthtMin[i + 1]);
            }
        }
        return minSum == INT_MAX? -1 : minSum;
    }
};