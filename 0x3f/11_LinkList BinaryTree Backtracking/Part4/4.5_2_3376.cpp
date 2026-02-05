#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();
        int minTime = INT_MAX;
        int sumTime = 0;
        int power = 1;
        vector<bool> opened(n, false);

        auto dfs = [&] (this auto&& dfs, int x) -> void
        {
            if (sumTime >= minTime)
            {
                return;
            }
            
            if (x == 0)
            {
                minTime = sumTime;
                return;
            }

            for (int i = 0; i < n; i++)
            {
                if (opened[i])
                {
                    continue;
                }
                int time = (strength[i] - 1) / power + 1;
                sumTime += time;
                opened[i] = true;
                power += k;
                dfs(x - 1);
                opened[i] = false;
                power -= k;
                sumTime -= time;
            }
            return;
        };

        dfs(n);
        return minTime;
    }
};