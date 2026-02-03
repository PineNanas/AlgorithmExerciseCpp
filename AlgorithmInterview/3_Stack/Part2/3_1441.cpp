#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> anwser;
        anwser.push_back("Push");
        for (int i = 1; i < target[0]; i++)
        {
            anwser.push_back("Pop");
            anwser.push_back("Push");
        }

        for (int i = 1; i < target.size(); i++)
        {
            int sub = target[i] - target[i - 1] - 1;
            anwser.push_back("Push");
            for (int i = 0; i < sub; i++)
            {
                anwser.push_back("Pop");
                anwser.push_back("Push");
            }
        }
        return anwser;
    }
};