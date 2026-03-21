#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue< pair<int, int>,
                        vector<pair<int, int>>,
                        greater<pair<int, int>>> minHeap;
        long long ans = 0;
        for (int i = 0; i < values.size(); i++)
        {
            minHeap.push({values[i].back(), i});
            values[i].pop_back();
        }
        int day = 1;
        while (!minHeap.empty())
        {
            auto [value, store] = minHeap.top();
            ans += (long long)value * day;
            minHeap.pop();
            if (!values[store].empty())
            {
                minHeap.push({values[store].back(), store});
                values[store].pop_back();
            }
            day++;
        }
        return ans;
    }
};