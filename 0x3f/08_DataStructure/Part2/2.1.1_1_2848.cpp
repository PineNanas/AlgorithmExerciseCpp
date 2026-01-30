#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            n = max(n, nums[i][1]);
        }
        vector<int> diffVec(n + 2);
        for (auto &&bus : nums)
        {
            diffVec[bus[0]]++;
            diffVec[bus[1] + 1]--;
        }
        int now = 0;
        int ans = 0;
        for (auto &&diff : diffVec)
        {
            now += diff;
            if (now > 0)
            {
                ans++;
            }
        }
        return ans;
    }
};