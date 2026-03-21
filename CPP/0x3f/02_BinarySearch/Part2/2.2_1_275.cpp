#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        auto check = [&] (int x) -> bool
        {
            if (citations[citations.size() - x] >= x)
            {
                return true;
            }
            return false;
        };
        int left = 0;
        int right = citations.size() + 1;
        int mid;
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
