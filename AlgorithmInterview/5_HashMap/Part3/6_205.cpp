#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashMap1, hashMap2;
        for (int i = 0; i < s.size(); i++)
        {
            if (hashMap1.count(s[i]) == 0)
            {
                if (hashMap2.count(t[i]) != 0)
                {
                    return false;
                }
                hashMap1[s[i]] = t[i];
                hashMap2[t[i]] = s[i];
            }
            else if (hashMap1[s[i]] == t[i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};