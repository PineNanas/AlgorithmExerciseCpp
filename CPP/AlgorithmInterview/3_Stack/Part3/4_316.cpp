#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> letterLeft(26);
        vector<int> inAns(26);
        for (int i = 0; i < s.size(); i++)
        {
            letterLeft[s[i] - 'a']++;
        }
        string ans;
        for (int i = 0; i < s.size(); i++)
        {
            letterLeft[s[i] - 'a']--;
            if (inAns[s[i] - 'a'])
            {
                continue;
            }
            while (!ans.empty() && ans.back() > s[i] && letterLeft[ans.back() - 'a'])
            {
                inAns[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            inAns[s[i] - 'a'] = 1;
            ans.push_back(s[i]);
        }
        return ans;
    }
};