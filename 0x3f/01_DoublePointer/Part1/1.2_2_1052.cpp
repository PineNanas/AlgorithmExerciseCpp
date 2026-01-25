#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        int now = 0;
        int fixed = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            now += customers[i] * grumpy[i];
            fixed += customers[i] * !grumpy[i];
            ans = max(now, ans);
            int left = i + 1 - minutes;
            if (left >= 0)
            {
                now -= customers[left] * grumpy[left];
            }
        }
        return ans + fixed;
    }
};