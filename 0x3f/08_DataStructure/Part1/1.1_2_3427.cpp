#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        vector<int> sumV(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            sumV[i + 1] = sumV[i] + nums[i];
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += sumV[i + 1] - sumV[max(0, i - nums[i])];
        }
        return sum;
    }
};