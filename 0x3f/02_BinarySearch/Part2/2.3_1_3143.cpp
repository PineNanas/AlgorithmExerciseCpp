#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        auto inside = [&] (int index,int halfLen) -> bool
        {
            return abs(points[index][0]) <= halfLen && abs(points[index][1]) <= halfLen;
        };
        auto check = [&] (int halfLen) -> bool
        {
            unordered_set<char> existedTag;
            for (int i = 0; i < points.size(); i++)
            {
                if (inside(i, halfLen))
                {
                    if (existedTag.contains(s[i]))
                    {
                        return false;
                    }
                    existedTag.insert(s[i]);
                }
            }
            return true;
        };
        int left = -1;
        int right = 0;
        for (int i = 0; i < points.size(); i++)
        {
            if (abs(points[i][0]) > right)
            {
                right = abs(points[i][0]);
            }
            if (abs(points[i][1]) > right)
            {
                right = abs(points[i][1]);
            }
        }
        right++;
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
        int count = 0;
        for (int i = 0; i < points.size(); i++)
        {
            if (inside(i, left))
            {
                count++;
            }
        }
        return count;
    }
};