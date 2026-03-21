#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> vowelStringV(words.size() + 1, 0);
        for (int i = 0; i < words.size(); i++)
        {
            vowelStringV[i + 1] = vowelStringV[i] + checkS(words[i]);
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            ans.push_back(vowelStringV[queries[i][1] + 1] - vowelStringV[queries[i][0]]);
        }
        return ans;
    }

    bool checkS(string s)
    {
        if (checkC(s[0]) && checkC(s[s.size() - 1]))
        {
            return true;
        }
        return false;
    }

    bool checkC(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};