#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diffVec(52, 0);
        for (auto &&range : ranges)
        {
            diffVec[range[0]]++;
            diffVec[range[1] + 1]--;
        }
        int sum = 0;
        for (int i = 0; i < 52; i++)
        {
            sum += diffVec[i];
            if (i >= left && i <= right && sum <= 0)
            {
                return false;
            }
        }
        return true;
    }
};