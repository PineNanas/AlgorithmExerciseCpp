#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return biggerThan(nums, goal) - biggerThan(nums, goal + 1);
    }
    int biggerThan(vector<int>& nums, int goal)
    {
        int ans = 0;
        int sum = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while (left <= i && sum >= goal)
            {
                sum -= nums[left];
                left++;
            }
            ans += left;
        }
        return ans;
    }
};