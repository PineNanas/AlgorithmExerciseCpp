#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int clumsy(int n) {
        stack<int> stk;
        stk.push(n--);
        int operation = 0;
        while (n > 0)
        {
            if (operation % 4 == 0)
            {
                stk.top() *= n;
            }
            else if (operation % 4 == 1)
            {
                stk.top() /= n;
            }
            else if (operation % 4 == 2)
            {
                stk.push(n);
            }
            else
            {
                stk.push(-n);
            }
            n--;
            operation++;
        }
        int ans = 0;
        while (!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};