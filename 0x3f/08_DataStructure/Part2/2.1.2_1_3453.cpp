#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        map<int, long long> diffMap;
        long long sum = 0;
        for (auto &&square : squares)
        {
            diffMap[square[1]] += square[2];
            diffMap[square[1] + square[2]] -= square[2];
            sum += (long long)square[2] * square[2];
        }
        long long sumArea = 0, sumL = 0;
        auto cur = diffMap.begin();
        while (true)
        {
            auto [y, l] = *cur;
            int y2 = (++cur)->first;
            sumL += l;
            sumArea += sumL * (y2 - y);
            if (sumArea * 2 >= sum)
            {
                return y2 - (sumArea * 2 - sum) / 2.0 / sumL;
            }
        }
    }
};

class Solution2 {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double sum = 0;
        int maxLine = 0;
        for (auto &&square : squares)
        {
            sum += (double)square[2] * square[2];
            maxLine = max(maxLine, square[1] + square[2]);
        }

        auto check = [&] (double line) -> bool
        {
            double upLine = 0;
            for (auto &&square : squares)
            {
                if (square[1] + square[2] < line) continue;
                upLine += square[2] * (square[1] + square[2] - max((double)square[1], line));
                if (upLine > sum / 2.0) return true;
            }
            return false;
        };

        double left = 0, right = maxLine, mid;
        for (int i = 0; i < 52; i++)
        {
            mid = left + (right - left) / 2.0;
            (check(mid)? left : right) = mid;
        }
        return (left + right) / 2.0;
    }
};