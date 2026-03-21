#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> countHashMap;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            countHashMap[nums[i]].push_back(i);
        }
        vector<long long> ans(n, 0);
        for (auto &&v : countHashMap)
        {
            int m = v.second.size();
            vector<long long> sumV(m + 1, 0);
            for (int i = 0; i < m; i++)
            {
                sumV[i + 1] = sumV[i] + v.second[i];
            }
            for (int i = 0; i < m; i++)
            {
                long long target = v.second[i];
                long long left = i * target - sumV[i];
                long long right = sumV[m] - sumV[i] - target * (m - i);
                ans[v.second[i]] = left + right;
            }
        }
        return ans;
    }
};