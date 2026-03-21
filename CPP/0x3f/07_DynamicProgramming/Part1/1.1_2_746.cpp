#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int last2 = 0;
        int last1 = 0;
        int now;
        for (int i = 2; i < cost.size() + 1; i++)
        {
            now = min(last2 + cost[i - 2], last1 + cost[i - 1]);
            last2 = last1;
            last1 = now;
        }
        return now;
    }
};