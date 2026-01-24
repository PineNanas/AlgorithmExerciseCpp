#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> charMap = {{'a', 0}, {'b', 0}, {'c', 0}};
        int ans = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++)
        {
            charMap[s[i]]++;
            while (charMap['a'] && charMap['b'] && charMap['c'])
            {
                charMap[s[left]]--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};