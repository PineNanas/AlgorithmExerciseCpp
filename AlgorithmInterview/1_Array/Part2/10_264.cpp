#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumberVector (n);
        uglyNumberVector[0] = 1;
        int i = 0, j = 0, k = 0, x = 1;
        while (x < n)
        {
            int minNum = min({uglyNumberVector[i] * 2, uglyNumberVector[j] * 3, uglyNumberVector[k] * 5});
            if (minNum == uglyNumberVector[i] * 2)
            {
                i++;
            }
            if (minNum == uglyNumberVector[j] * 3)
            {
                j++;
            }
            if (minNum == uglyNumberVector[k] * 5)
            {
                k++;
            }
            uglyNumberVector[x++] = minNum;
        }
        return uglyNumberVector[x - 1];
    }
};