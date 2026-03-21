#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        auto shiftC = [&] (char c, int shiftX) -> char
        {
            return 'a' + ((c - 'a' + shiftX) % 26 + 26) % 26;
        };
        vector<int> diffVec(s.size() + 1, 0);
        for (auto &&shift : shifts)
        {
            if (shift[2])
            {
                diffVec[shift[0]] ++;
                diffVec[shift[1] + 1] --;
            }
            else
            {
                diffVec[shift[0]] --;
                diffVec[shift[1] + 1] ++;
            }
        }
        int sumShift = 0;
        for (int i = 0; i < s.size(); i++)
        {
            sumShift += diffVec[i];
            s[i] = shiftC(s[i], sumShift);
        }
        return s;
    }
};