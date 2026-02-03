#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> stack1;
        int i = 0, j = 0;
        while (i < pushed.size())
        {   
            if (stack1.size() == 0 || popped[j] != stack1.back())
            {
                stack1.push_back(pushed[i++]);
            }
            else
            {
                stack1.pop_back();
                j++;
            }
            
        }
        while (j < popped.size())
        {
            if (stack1.back() == popped[j])
            {
                stack1.pop_back();
                j++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};