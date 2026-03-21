#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> minQ;
        deque<int> maxQ;
        long long ans = 0;
        int left = 0;
        int right = 0;
        while (right < nums.size())
        {
            while (!minQ.empty() && nums[minQ.back()] > nums[right])
            {
                minQ.pop_back();
            }
            minQ.push_back(right);
            while (!maxQ.empty() && nums[maxQ.back()] < nums[right])
            {
                maxQ.pop_back();
            }
            maxQ.push_back(right);
            while (nums[maxQ.front()] - nums[minQ.front()] > 2)
            {
                if (maxQ.front() == left)
                {
                    maxQ.pop_front();
                }
                if (minQ.front() == left)
                {
                    minQ.pop_front();
                }
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
};