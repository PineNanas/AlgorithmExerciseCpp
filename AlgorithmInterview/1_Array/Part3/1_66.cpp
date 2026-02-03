#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        bool fixed = false;
        while (i >= 0 && !fixed)
        {
            if (digits[i] != 9)
            {
                digits[i]++;
                fixed = true;
            }
            else if (digits[i] == 9)
            {
                digits[i] = 0;
                i--;
            }
        }
        if (fixed)
        {
            return digits;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};