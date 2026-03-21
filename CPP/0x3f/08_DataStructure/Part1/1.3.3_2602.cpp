#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        ranges::sort(nums);
        int n = nums.size();
        vector<long long> sumV(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            sumV[i + 1] = sumV[i] + nums[i];
        }
        auto find = [&] (int x) -> int
        {
            int left = -1;
            int right = n;
            int mid;
            while (left + 1 < right)
            {
                mid = left + (right - left) / 2;
                if (nums[mid] <= x)
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }
            return left;
        };
        vector<long long> ans;
        int qIndex;
        long long operation;
        for (int i = 0; i < queries.size(); i++)
        {
            operation = 0;
            qIndex = find(queries[i]);
            operation += (long long)queries[i] * (qIndex + 1) - sumV[qIndex + 1];
            operation += sumV[n] - sumV[qIndex + 1] - (long long)queries[i] * (n - qIndex - 1);
            ans.push_back(operation);
        }
        return ans;
    }
};