#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        deque<int>  minQueue, maxQueue;
        int left = 0, right = 0;
        while (right < nums.size())
        {
            while (!minQueue.empty() && nums[minQueue.back()] > nums[right])
            {
                minQueue.pop_back();
            }
            while (!maxQueue.empty() && nums[maxQueue.back()] < nums[right])
            {
                maxQueue.pop_back();
            }
            minQueue.push_back(right);
            maxQueue.push_back(right);
            while (!minQueue.empty() && !maxQueue.empty() && nums[maxQueue.front()] - nums[minQueue.front()] > limit)
            {
                if (left == minQueue.front())
                {
                    minQueue.pop_front();
                }
                if (left == maxQueue.front())
                {
                    maxQueue.pop_front();
                }
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};