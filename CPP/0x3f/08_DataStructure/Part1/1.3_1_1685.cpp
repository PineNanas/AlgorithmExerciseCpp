#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> sumV(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            sumV[i + 1] = sumV[i] + nums[i];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = nums[i] * (i -(n - i)) - 2 * sumV[i] + sumV[n]; 
        }
        return ans;
    }
};