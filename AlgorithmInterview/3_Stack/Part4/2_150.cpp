#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> intStack;
        for (auto &&token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int a = intStack.top();
                intStack.pop();
                int b = intStack.top();
                intStack.pop();
                int c;
                if (token == "+")
                {
                    c = a + b;
                }
                else if (token == "-")
                {
                    c = b - a;
                }
                else if (token == "*")
                {
                    c = a * b;
                }
                else
                {
                    c = b / a;
                }
                intStack.push(c);
            }
            else
            {
                intStack.push(stoi(token));
            }
        }
        return intStack.top();
    }
};