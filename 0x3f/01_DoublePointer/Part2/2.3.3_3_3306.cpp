#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return moreThanK(word, k) - moreThanK(word, k + 1);
    }

    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long moreThanK(string word, int k)
    {
        unordered_map<char, int> vowelMap;
        long long ans = 0;
        int consonantCount = 0;
        int left = 0;
        int vowelType = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (isVowel(word[i]))
            {
                if (vowelMap[word[i]] == 0)
                {
                    vowelType++;
                }
                vowelMap[word[i]]++;
            }
            else
            {
                consonantCount++;
            }
            while (consonantCount >= k && vowelType == 5)
            {
                if (isVowel(word[left]))
                {
                    vowelMap[word[left]]--;
                    if (vowelMap[word[left]] == 0)
                    {
                        vowelType--;
                    }
                }
                else
                {
                    consonantCount--;
                }
                left++;
            }
            ans += left;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    solution.countOfSubstrings("ieaouqqieaouqq", 1);
    return 0;
}