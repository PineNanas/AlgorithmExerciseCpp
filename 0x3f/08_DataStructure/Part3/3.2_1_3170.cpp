#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> letterStacks(26);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (!letterStacks[j].empty())
                    {
                        s[letterStacks[j].top()] = '*';
                        letterStacks[j].pop();
                        break; 
                    }
                }
            }
            else
            {
                letterStacks[s[i] - 'a'].push(i);
            }
        }
        erase(s, '*');
        return s;
    }
};