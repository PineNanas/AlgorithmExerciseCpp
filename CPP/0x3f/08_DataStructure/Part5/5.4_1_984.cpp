#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";
        bool turnA = a >= b;
        while (a > 0 || b > 0)
        {
            if (turnA)
            {
                if (a >= b && a > 1)
                {
                    ans.append("aa");
                    a -= 2;
                }
                else
                {
                    ans.append("a");
                    a--;
                }
            }
            else
            {
                if (b >= a && b > 1)
                {
                    ans.append("bb");
                    b -= 2;
                }
                else
                {
                    ans.append("b");
                    b--;
                }
            }
            turnA = !turnA;
        }
        return ans;
    }
};