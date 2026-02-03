#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        for (int i = 0; i < k; i++)
        {
            while(window.size() != 0 && nums[window.back()] <= nums[i])
            {
                window.pop_back();
            }
            window.push_back(i);
        }
        vector<int> ans(nums.size() - k + 1);
        ans[0] = nums[window.front()];
        for (int i = k; i < nums.size(); i++)
        {
            while (window.size() != 0 && window.front() <= i - k)
            {
                window.pop_front();
            }
            while (window.size() != 0 && nums[window.back()] <= nums[i])
            {
                window.pop_back();
            }
            window.push_back(i);
            ans[i - k + 1] = nums[window.front()];
        }
        return ans;
    }
};