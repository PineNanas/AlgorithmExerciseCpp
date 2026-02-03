#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ones = 0;
        int zeros = 0;
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i] == 1)
            {
                ones++;
            }
            else
            {
                zeros++;
            }
        }
        for (int i = 0; i < sandwiches.size(); i++)
        {
            if (sandwiches[i] == 1)
            {
                if (ones != 0)
                {
                    ones--;
                }
                else
                {
                    return zeros;
                }
            }
            else
            {
                if (zeros != 0)
                {
                    zeros--;
                }
                else
                {
                    return ones;
                }
            }
        }
        return 0;
    }
};