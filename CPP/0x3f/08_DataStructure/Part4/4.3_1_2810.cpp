#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string finalString(string s) {
        deque<char> charQ;
        bool tailTrue = true;
        for (auto &&c : s)
        {
            if (c == 'i')
            {
                tailTrue = !tailTrue;
                continue;
            }
            if (tailTrue)
            {
                charQ.push_back(c);
            }
            else
            {
                charQ.push_front(c);
            }
        }
        if (tailTrue)
        {
            return string(charQ.begin(), charQ.end());
        }
        else
        {
            return string(charQ.rbegin(), charQ.rend());
        }
    }
};