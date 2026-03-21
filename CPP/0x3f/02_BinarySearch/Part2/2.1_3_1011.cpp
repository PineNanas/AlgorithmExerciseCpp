#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = ranges::max(weights);
        auto check = [&] (int space) -> bool
        {
            if (space < maxWeight)
            {
                return false;
            }
            int nowday = 0;
            int weightNow = 0;
            for (int i = 0; i < weights.size(); i++)
            {
                if (weightNow + weights[i] > space)
                {
                    weightNow = 0;
                    nowday++;
                    if (nowday >= days)
                    {
                        return false;
                    }
                }
                weightNow += weights[i];
            }
            return true;
        };
        int left = maxWeight - 1;
        int right = accumulate(weights.begin(), weights.end(), 0);
        int mid;
        while (left + 1 < right)
        {
            mid = left + (right - left) / 2;
            if (check(mid))
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        return right;
    }
};