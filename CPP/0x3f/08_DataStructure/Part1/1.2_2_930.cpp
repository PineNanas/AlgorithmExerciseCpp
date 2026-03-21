#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> sumCount;
        sumCount[0]++;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            ans += sumCount[sum - goal];
            sumCount[sum]++;
        }
        return ans;
    }
};