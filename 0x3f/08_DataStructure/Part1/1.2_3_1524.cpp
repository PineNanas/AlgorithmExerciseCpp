#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0;
        int even = 0;
        int sum = 0;
        long long ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum % 2 == 1)
            {
                ans += even;
                odd++;
            }
            else
            {
                ans += odd;
                even++;
            }
        }
        return ans % (1000000007);
    }
};