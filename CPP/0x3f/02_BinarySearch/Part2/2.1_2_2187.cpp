#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        auto check = [&] (long long threshold) -> bool
        {
            long long sum = 0;
            for (int i = 0; i < time.size(); i++)
            {
                sum += threshold / time[i];
                if (sum >= totalTrips)
                {
                    return true;
                }
            }
            return false;
        };
        long long left = 0;
        long long right = (long long) totalTrips * ranges::max(time);
        long long mid;
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