#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ranges::sort(intervals);
        vector<vector<int>> ans;
        for (auto &&p : intervals)
        {
            if (ans.empty() || p[0] > ans.back()[1])
            {
                ans.push_back(p);
                continue;
            }
            ans.back()[1] = max(ans.back()[1], p[1]);
        }
        return ans;
    }
};