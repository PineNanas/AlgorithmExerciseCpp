#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string awnser = "";
        int a = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                awnser.push_back('(');
                a++;
            }
            else if (s[i] == ')')
            {
                if (a == 0)
                {
                    continue;
                }
                else
                {
                    awnser.push_back(')');
                    a--;
                }
            }
            else
            {
                awnser.push_back(s[i]);
            }
        }
        for (int i = 0; i < a; i++)
        {
            awnser.erase(awnser.find_last_of('('), 1);
        }
        return awnser;
    }
};

int main()
{
    string s = "(a(b(c)d)";
    Solution solution;
    cout << solution.minRemoveToMakeValid(s) << endl;
    return 0;
}