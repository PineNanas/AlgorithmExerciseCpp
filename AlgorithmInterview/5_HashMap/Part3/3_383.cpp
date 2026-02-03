#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hashMap1;
        vector<int> ans;
        for (int i = 0; i < magazine.size(); i++)
        {
            hashMap1[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.size(); i++)
        {
            hashMap1[ransomNote[i]]--;
        }
        
        for (const auto& [_, value] : hashMap1) 
        {
            if (value < 0)
            {
                return false;
            }
        }
        return true;
    }
};