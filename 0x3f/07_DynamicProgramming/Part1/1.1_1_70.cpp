#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int last2 = 1;
        if (n == 0)
        {
            return 1;
        }
        int last1 = 2;
        int now = last1;
        for (int i = 2; i < n; i++)
        {
            now = last1 + last2;
            last2 = last1;
            last1 = now;   
        }
        return now;
    }
};