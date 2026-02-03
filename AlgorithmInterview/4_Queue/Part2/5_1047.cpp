#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        int p = 0;
        while (p < s.size())
        {
            if (ans.size() == 0 || ans.back() != s[p])
            {
                ans.push_back(s[p]);
            }
            else
            {
                ans.pop_back();
            }
            p++;
        }
        return ans;
    }
};