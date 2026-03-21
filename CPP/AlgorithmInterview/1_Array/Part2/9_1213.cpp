#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int size1 = arr1.size();
        int size2 = arr2.size();
        int size3 = arr3.size();
        vector<int> ans;
        int i = 0, j = 0, k = 0;
        while (i < size1 && j < size2 && k < size3)
        {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
            {
                ans.emplace_back(arr1[i]);
                i++;
                j++;
                k++;
            }
            else if (arr1[i] <= arr2[j] && arr1[i] <= arr3[k])
            {
                i++;
            }
            else if (arr2[j] <= arr1[i] && arr2[j] <= arr3[k])
            {
                j++;
            }
            else if (arr3[k] <= arr2[j] && arr3[k] <= arr1[i])
            {
                k++;
            } 
        }
        return ans;
    }
};