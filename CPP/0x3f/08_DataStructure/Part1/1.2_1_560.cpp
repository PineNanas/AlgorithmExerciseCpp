#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumCount;
        sumCount[0]++;
        vector<int> sumV(nums.size() + 1, 0);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sumV[i + 1] = sumV[i] + nums[i];
            ans += sumCount[sumV[i + 1] - k];
            sumCount[sumV[i + 1]]++;
        }
        return ans;
    }
};