#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int j = k;
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        int maxSum = sum;
        while (j < nums.size())
        {
            sum -= nums[i];
            sum += nums[j];
            maxSum = max(maxSum, sum);
            i++;
            j++;
        }
        return (double)maxSum / k;
    }
};