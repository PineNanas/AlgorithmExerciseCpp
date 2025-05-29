#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        int size = s.size();
        string anwser;
        for (int i = 0; i < size; i++)
        {
            if (anwser.size() == 0)
            {
                anwser.push_back(s[i]);
            }
            else if (islower(anwser.back()))
            {
                if (toupper(anwser.back()) == s[i])
                {
                    anwser.pop_back();
                }
                else
                {
                    anwser.push_back(s[i]);
                }
            }
            else if (isupper(anwser.back()))
            {
                if (tolower(anwser.back()) == s[i])
                {
                    anwser.pop_back();
                }
                else
                {
                    anwser.push_back(s[i]);
                }
            }
        }
        return anwser;
    }
};