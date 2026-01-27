#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        ranges::sort(start);
        auto check = [&] (int minD) -> bool
        {
            long long lastPoint = start[0];
            for (int i = 1; i < start.size(); i++)
            {
                if (lastPoint + minD <= start[i])
                {
                    lastPoint = start[i];
                }
                else if (lastPoint + minD > start[i] && lastPoint + minD <= start[i] + d)
                {
                    lastPoint = lastPoint + minD;
                }
                else
                {
                    return false;
                }
            }
            return true;
        };
        int left = 0;
        int right = ranges::max(start) + d + 1;
        int mid;
        while (left + 1 < right)
        {
            mid = left + (right - left) / 2;
            (check(mid)? left : right) = mid;
        }
        return left;
    }
};