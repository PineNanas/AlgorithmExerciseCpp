#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> circle;
        int next = n;
        while (true)
        {
            if (next == 1)
            {
                return true;
            }
            if (circle.find(next) != circle.end())
            {
                return false;
            }
            circle.insert(next);
            next = getnext(next);
        }
    }
    int getnext(int x)
    {
        int next = 0;
        while (x > 0)
        {
            next += (x % 10) * (x % 10);
            x /= 10;
        }
        return next;
    }
};