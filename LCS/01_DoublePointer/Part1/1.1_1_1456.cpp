#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int maxVowel = 0;
        for (int i = 0; i < k; i++)
        {
            if (isVowel(s[i]))
            {
                maxVowel++;
            }
        }
        int now = maxVowel;
        int size = s.size();
        int i = 0;
        int j = k;
        while (j < size)
        {
            if (!isVowel(s[i]) && isVowel(s[j]))
            {
                now++;
            }
            if (isVowel(s[i]) && !isVowel(s[j]))
            {
                now--;
            }
            maxVowel = max(maxVowel, now);
            i++;
            j++;
        }
        return maxVowel;
    }
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; 
    }
};