#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        // 找到最小的x使得有k个数小于等于x
        auto check = [&] (int x)
        {
            // 检查是否有k个数小于等于x
            int count = 0;
            for (int i = 1; i < n + 1; i++)
            {
                if (i > x)
                {
                    return false;
                }
                count += min(m, x / i);
                if (count >= k)
                {
                    return true;
                }
            }
            return false;
        };
        int left = 0;
        int right = m * n;
        int mid;
        while (left + 1 < right)
        {
            mid = left + (right - left) / 2;
            (check(mid)? right : left) = mid;
        }
        return right;
    }
};