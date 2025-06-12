#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }
        int size = s.size();
        unordered_map<char, int> hashMap1;
        for (int i = 0; i < size; i++)
        {
            hashMap1[s[i]]++;
        }
        for (int i = 0; i < size; i++)
        {
            hashMap1[t[i]]--;
        }
        for (const auto& i : hashMap1)
        {
            if (i.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};