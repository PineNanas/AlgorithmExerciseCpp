#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        string t;
        for (auto &&c : s)
        {
            if (t.empty())
            {
                t.push_back(c);
                continue;
            }
            if (c == '(')
            {
                t.push_back(c);
            }
            else
            {
                if (t.back() == '(')
                {
                    t.pop_back();
                }
                else
                {
                    t.push_back(c);
                }
            }
        }
        return t.size();
    }
};