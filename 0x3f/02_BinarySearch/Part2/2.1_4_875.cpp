#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto check = [&] (int speed) -> bool
        {
            long long sum = 0;
            for (int i = 0; i < piles.size(); i++)
            {
                sum += (long long)(piles[i] - 1) / speed + 1; 
            }
            return sum <= h;
        };
        int left = 0;
        int right = ranges::max(piles);
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