#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> averageVec;
        if (2 * k >= nums.size())
        {
            for (int i = 0; i < nums.size(); i++)
            {
                averageVec.push_back(-1);
            }
            return averageVec;
        }
        if (k == 0)
        {
            return nums;
        }
        for (int i = 0; i < k; i++)
        {
            averageVec.push_back(-1);
        }
        long long sum = 0;
        int si = 2 * k + 1;
        for (int i = 0; i < si; i++)
        {
            sum += nums[i];
        }
        averageVec.push_back(sum / si);
        int i = 0;
        int j = si;
        while (j < nums.size())
        {
            sum -= nums[i];
            sum += nums[j];
            averageVec.push_back(sum / si);
            i++;
            j++;
        }
        for (int i = 0; i < k; i++)
        {
            averageVec.push_back(-1);
        }
        return averageVec;
    }
};