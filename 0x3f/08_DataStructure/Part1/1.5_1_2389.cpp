#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        ranges::sort(nums);
        int n = nums.size();
        vector<int> sumV(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            sumV[i + 1] = sumV[i] + nums[i];
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            int left = 0;
            int right = n + 1;
            int mid;
            while (left + 1 < right)
            {
                mid = left + (right - left) / 2;
                if (sumV[mid] > queries[i])
                {
                    right = mid;
                }
                else
                {
                    left = mid;
                }
            }
            ans[i] = right - 1;
        }
        return ans;
    }
};