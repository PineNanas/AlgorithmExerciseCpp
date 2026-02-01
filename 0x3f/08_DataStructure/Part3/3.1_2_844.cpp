#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "";
        string t1 = "";
        for (auto &&c : s)
        {
            if (c == '#')
            {
                if (s1.empty())
                {
                    continue;
                }
                s1.pop_back();
            }
            else
            {
                s1.push_back(c);
            }
        }
        for (auto &&c : t)
        {
            if (c == '#')
            {
                if (t1.empty())
                {
                    continue;
                }
                t1.pop_back();
            }
            else
            {
                t1.push_back(c);
            }
        }
        return s1 == t1;
    }
};