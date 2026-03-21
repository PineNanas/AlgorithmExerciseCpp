#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        auto check = [&] (int eachKid)
        {
            long long sum = 0;
            for (int i = 0; i < candies.size(); i++)
            {
                sum += candies[i] / eachKid;
                if (sum >= k)
                {
                    return true;
                }
            }
            return false;
        };
        long long left = 0;
        long long right = ranges::max(candies) + 1;
        long long mid;
        while (left + 1 < right)
        {
            mid = left + (right - left) / 2;
            if (check(mid))
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};