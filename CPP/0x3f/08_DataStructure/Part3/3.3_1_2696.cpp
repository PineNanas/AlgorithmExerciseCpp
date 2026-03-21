#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        string t;
        int ans = 0;
        for (auto &&c : s)
        {
            if (t.empty())
            {
                t.push_back(c);
                continue;
            }
            switch (c)
            {
            case 'B':
                if (t.back() == 'A')
                {
                    t.pop_back();
                }
                else
                {
                    t.push_back(c);
                }
                break;
            case 'D':
                if (t.back() == 'C')
                {
                    t.pop_back();
                }
                else
                {
                    t.push_back(c);
                }
                break;
            default:
                t.push_back(c);
                break;
            }
        }
        return t.size();
    }
};