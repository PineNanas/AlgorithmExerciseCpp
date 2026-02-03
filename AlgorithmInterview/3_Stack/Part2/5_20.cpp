#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string x;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                x.push_back(s[i]);
            }
            else if (s[i] == ')')
            {
                if (x.size() == 0)
                {
                    return false;
                }
                if (x.back() == '(')
                {
                    x.pop_back();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == ']')
            {
                if (x.size() == 0)
                {
                    return false;
                }
                if (x.back() == '[')
                {
                    x.pop_back();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (x.size() == 0)
                {
                    return false;
                }
                if (x.back() == '{')
                {
                    x.pop_back();
                }
                else
                {
                    return false;
                }
            }
        }
        if (x.size() == 0)
        {
            return true;
        }
        return false;
    }
};